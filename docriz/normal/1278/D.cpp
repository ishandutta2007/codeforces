#include <bits/stdc++.h>

using namespace std;

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

ll gcd(ll a, ll b) { 
  return b ? gcd(b, a % b) : a;
}

const int MAXN = 1000005;

const int INF = INT_MAX / 2;

struct Node {
  PII val;
  Node *ls, *rs;
  void push_up() {
    val = min(ls->val, rs->val);
  }
}pool[MAXN<<1];

Node *new_node() {
  static int cnt = 0;
  return &pool[cnt++];
}

Node *build(int l, int r) {
  Node *cur = new_node();
  if (l < r) {
    int mid = (l + r) / 2;
    cur->ls = build(l, mid);
    cur->rs = build(mid + 1, r);
    cur->push_up();
  } else {
    cur->val = mp(INF, l);
  }
  return cur;
}

void modify(Node *cur, int l, int r, int p, int v) {
  if (l == r) {
    cur->val.first = v;
  } else {
    int mid = (l + r) / 2;
    if (p <= mid) modify(cur->ls, l, mid, p, v);
    else modify(cur->rs, mid + 1, r, p, v);
    cur->push_up();
  }
}

PII query(Node *cur, int l, int r, int a, int b) {
  if (a <= l && b >= r) {
    return cur->val;
  }
  int mid = (l + r) / 2;
  if (b <= mid) return query(cur->ls, l, mid, a, b);
  if (a > mid) return query(cur->rs, mid + 1, r, a, b);
  return min(query(cur->ls, l, mid, a, b), 
             query(cur->rs, mid + 1, r, a, b));
}

void my_main() {
  int n;
  cin >> n;
  vector<PII> seg(n + 1);
  auto id = VI(2 * n + 1);
  rep(i, 1, n + 1) {
    cin >> seg[i].x >> seg[i].y;
    id[seg[i].x] = i;
    id[seg[i].y] = i;
  }
  Node *root = build(1, 2 * n);
  vector<int> fa(n + 1);
  rep(i, 1, n + 1) fa[i] = i;
  function<int(int)> find = [&](int x) -> int {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
  };
  rep(i, 1, 2 * n + 1) {
    // debug(i, id[i]);
    if (seg[id[i]].x == i) {
      int l = seg[id[i]].x, r = seg[id[i]].y;
      modify(root, 1, 2 * n, l, r);
      if (l > 1) {
        vector<PII> tmp;
        while (true) {
          PII min_p = query(root, 1, 2 * n, 1, l - 1);
          if (min_p.x < r) {
            if (find(id[i]) == find(id[min_p.y])) {
              // debug(id[i], id[min_p.y]);
              cout << "NO\n";
              exit(0);
            } else {
              fa[find(id[i])] = find(id[min_p.y]);
            }
            tmp.pb(min_p);
            modify(root, 1, 2 * n, min_p.y, INF);
          } else {
            break;
          }
        }
        for (auto t: tmp) {
          modify(root, 1, 2 * n, t.y, t.x);
        }
      }
    } else {
      modify(root, 1, 2 * n, seg[id[i]].x, INF);
    }
  }
  set<int> S;
  rep(i, 1, n + 1) S.insert(find(i));
  if (sz(S) == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}