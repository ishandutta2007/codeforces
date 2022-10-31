#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

using ll = long long;
using PII = pair<int, int>;
using PIL = pair<int, ll>;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define VL(n) vector<ll>(n)
#define VI(n) vector<int>(n)
#define VII(n, m) vector<vector<int>>(n, vector<int>(m))
#define VLL(n, m) vector<vector<ll>>(n, vector<ll>(m))
#define VIII(n, m, p) vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(p)))
#define VLLL(n, m, p) vector<vector<vector<ll>>>(n, vector<vector<ll>>(m, vector<ll>(p)))

/*
  find the biggest x that check(x) is true.
  time complexity: O(log(r-l))
  space commplexity: O(1)
*/
int bs_biggest(int l, int r, const function<bool(int)>& check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) l = mid; else r = mid - 1;
  }
  return l;
}

/*
  find the smallest x that check(x) is true.
  time complexity: O(log(r-l))
  space commplexity: O(1)
*/
int bs_smallest(int l, int r, const function<bool(int)>& check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid; else l = mid + 1;
  }
  return l;
}

const int MOD = (int)1e9 + 7;

int fexp(int a, int b) {
  int res = 1;
  for(int i = 1; i <= b; i <<= 1) {
    if(i & b) res = (ll)res * a % MOD;
    a = (ll)a * a % MOD;
  }
  return res;
}

int inv(int x) {
  return fexp(x, MOD - 2);
}

ll gcd(ll a, ll b) { 
  return b ? gcd(b, a % b) : a;
}

/*
  example:
    BIT<int> b1(5);
    b1.add(3, 10);
    b1.add(1, 7);
    debug(b1.query(1, 3)); // should be 17
    debug(b1.query(2, 3)); // should be 10
*/
template<typename T>
struct BIT {
  int n;
  vector<T> c;

  BIT(int _n) {
    n = _n;
    c.resize(n + 1);
  }

  void add(int p, T v) {
    assert(p >= 1 && p <= n);
    for (; p <= n; p += p & -p) c[p] += v;
  };

  T sum(int p) {
    T ret = 0;
    for (; p >= 1; p -= p & -p) ret += c[p];
    return ret;
  };

  T query(int l, int r) {
    assert(l <= r && r <= n && l >= 1);
    return sum(r) - sum(l - 1);
  };
};


const int MAXN = 1000005;

vector<PII> mon[MAXN];
int cost_x[MAXN];
int cost_y[MAXN];

struct Node {
  ll max_v;
  ll tag;
  Node *ls, *rs;
  void push_up() {
    max_v = max(ls->max_v, rs->max_v);
  }
  void update(ll t) {
    max_v += t;
    tag += t;
  }
  void push_down() {
    if (tag) {
      ls->update(tag);
      rs->update(tag);
      tag = 0;
    }
  }
}pool[MAXN<<1];

Node *newNode() {
  static int cnt = 0;
  return &pool[cnt++];
}

Node *build(int l, int r) {
  Node *cur = newNode();
  if (l < r) {
    int mid = (l + r) / 2;
    cur->ls = build(l, mid);
    cur->rs = build(mid + 1, r);
    cur->push_up();
  } else {
    cur->max_v = cur->tag = 0;
  }
  return cur;
}

void add(Node *cur, int l, int r, int a, int b, ll v) {
  if (a <= l && b >= r) {
    cur->update(v);
  } else {
    cur->push_down();
    int mid = (l + r) / 2;
    if (a <= mid) add(cur->ls, l, mid, a, b, v);
    if (b > mid) add(cur->rs, mid + 1, r, a, b, v);
    cur->push_up();
  }
}

void my_main() {
  int n, m, p;
  cin >> n >> m >> p;
  memset(cost_x, 127 / 2, sizeof(cost_x));
  memset(cost_y, 127 / 2, sizeof(cost_y));
  rep(i, 1, n + 1) {
    int x, y;
    cin >> x >> y;
    cost_x[x] = min(cost_x[x], y);
    // cin >> a[i].x >> a[i].y;
  }
  rep(i, 1, m + 1) {
    // cin >> b[i].x >> b[i].y;
    int x, y;
    cin >> x >> y;
    cost_y[x] = min(cost_y[x], y);
  }
  const int V = (int)1e6;
  Node *root = build(1, V);
  rep(i, 1, V + 1) {
    if (cost_y[i] == cost_y[0]) {
      add(root, 1, V, i, i, LLONG_MIN / 2);
    } else {
      add(root, 1, V, i, i, -cost_y[i]);
    }
  }
  // cout << root->max_v << endl;
  rep(i, 0, p) {
    int x, y, z;
    cin >> x >> y >> z;
    // debug(x, y, z);
    mon[x].pb(mp(y, z));
  }
  ll ans = LLONG_MIN;
  // debug(cost_x[2], cost_x[4]);
  // debug(cost_y[2], cost_y[3]);
  rep(i, 1, V + 1) {
    for (auto m: mon[i - 1]) {
      if (m.first >= V) continue;
      // debug(i, m.first, m.second);
      add(root, 1, V, m.first + 1, V, m.second);
    }
    if (cost_x[i] == cost_x[0]) continue;
    ll cur_ans = -cost_x[i];
    cur_ans += root->max_v;
    ans = max(ans, cur_ans);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}