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

/*
  find the k-th array that satified f().
  time complexity: O(n^2*T(f))
  parameters: 
    f(int n, vector<int> a) should return the number of valid arrays,
    which the first n elements is a[1], a[2], ..., a[n].
    if no valid arrays start with those n elements, return 0.
  note:
    all the arrays(vectors) are 1-based!
    if the complexity is unacceptable, try read inside this function.
  example:
    // find the k-th permutation of length n.
    auto f = [&](int n, vector<int> a) -> ll{
      int m = sz(a);
      assert(m <= n);
      set<int> S;
      rep(i, 0, m) {
        if (S.count(a[i])) return 0;
        S.insert(a[i]);
      }
      ll fac = 1;
      rep(i, 1, n - m + 1) fac *= i;
      return fac; // return (n-m)!
    };
    debug(find_kth(5, 12, f)); // should be [1, 3, 5, 4, 2]
    debug(find_kth(5, 119, f)); // should be [5, 4, 3, 1, 2]
    debug(find_kth(5, 121, f)); // should be assertion failed.
*/
vector<int> find_kth(int n, ll k, const function<ll(int, vector<int>)>& f) {
  vector<int> ret;
  assert(k <= f(n, ret));
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      ret.pb(j);
      assert(sz(ret) == i + 1);
      ll count = f(n, ret);
      if (k > count) {
        k -= count;
      } else {
        break;
      }
      ret.pop_back();
    }
    assert(sz(ret) == i + 1);
  }
  return ret;
}

ll gcd(ll a, ll b) { 
  return b ? gcd(b, a % b) : a;
}

template <typename T>
struct MonotoneQueue {
  std::deque<T> q, m;
  void push(const T &x) {
    q.push_back(x);
    while (!m.empty() && m.back() > x) m.pop_back();
    m.push_back(x);
  }
  void pop() {
    T x = q.front();
    q.pop_front();
    if (x == m.front()) m.pop_front();
  }
  size_t size() {
    return q.size();
  }
  T top() {
    return m.front();
  }
};

int solve(int n, int k, int l, vector<int> a) {
  assert(sz(a) == n + 1);
  auto calc = [&](int mid) -> PII {
    vector<PII> f(n + 1);
    f[0] = mp(0, 0);
    MonotoneQueue<PII> Q;
    Q.push(f[0]);
    int j = 0;
    rep(i, 1, n + 1) {
      f[i] = f[i - 1];
      if (a[i] == 1) ++f[i].x;
      while (j < i - l) Q.pop(), ++j;
      f[i] = min(f[i], mp(Q.top().x + mid, Q.top().y + 1));
      Q.push(f[i]);
    }
    return f[n];
  };
  int v = bs_smallest(0, n, [&](int mid) -> bool {
    return calc(mid).y <= k;
  });
  return calc(v).x - k * v;
}

void my_main() {
  int n, k, l;
  cin >> n >> k >> l;
  string s;
  cin >> s;
  s = "#" + s;
  auto a = VI(n + 1);
  auto b = VI(n + 1);
  rep(i, 1, n + 1) if (s[i] >= 'a' && s[i] <= 'z') a[i] = 1; else b[i] = 1;
  int ans = min(solve(n, k, l, a), solve(n, k, l, b));
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}