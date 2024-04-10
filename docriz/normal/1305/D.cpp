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

void my_main() {
  int n;
  cin >> n;
  vector<vector<int>> G(n + 1);
  rep(i, 0, n - 1) {
    int x, y;
    cin >> x >> y;
    G[x].pb(y);
    G[y].pb(x);
  }
  /*
  auto deep = VI(n + 1);
  auto fa = VI(n + 1);
  auto son = VI(n + 1);
  auto size = VI(n + 1);
  auto top = VI(n + 1);
  function<void(int, int, int)> dfs1;
  dfs1 = [&](int cur, int father, int dep) -> void {
    fa[cur] = father;
    deep[cur] = dep;
    size[cur] = 1;
    son[cur] = 0;
    for(int i = 0; i < (int)G[cur].size(); i++) {
      int nx = G[cur][i];
      if(nx != father) {
        dfs1(nx, cur, dep + 1);
        size[cur] += size[nx];
        if(size[nx] > size[son[cur]]) {
          son[cur] = nx;
        }
      }
    }
  };
  function<void(int, int)> dfs2;
  dfs2 = [&](int cur, int tp) -> void {
    top[cur] = tp;
    if(son[cur]) dfs2(son[cur], tp);
    for(int i = 0; i < (int)G[cur].size(); i++) {
      int nx = G[cur][i];
      if(nx != fa[cur] && nx != son[cur]) {
        dfs2(nx, nx);
      }
    }
  };
  function<int(int, int)> lca;
  lca = [&](int x, int y) -> int {
    int t1 = top[x], t2 = top[y];
    while(t1 != t2) {
      if(deep[t1] < deep[t2]) {
        swap(t1, t2);
        swap(x, y);
      }
      x = fa[t1], t1 = top[x];
    }
    return deep[x] < deep[y] ? x : y;
  };
  */
  auto bfs = [&](int s, vector<int>& dis) -> void {
    rep(i, 1, n + 1) dis[i] = INT_MAX / 2;
    queue<int> Q;
    dis[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
      int cur = Q.front(); Q.pop();
      for (auto nx: G[cur]) {
        if (dis[cur] + 1 < dis[nx]) {
          dis[nx] = dis[cur] + 1;
          Q.push(nx);
        }
      }
    }
  };
  // dfs1(1, 0, 0);
  // dfs2(1, 1);
  auto query = [&](int x, int y) -> int {
    cout << "? " << x << " " << y << endl;
    int v;
    cin >> v;
    return v;
  };
  auto bad = VI(n + 1);
  while (true) {
    int root = -1;
    int left = 0;
    rep(i, 1, n + 1) if (!bad[i]) root = i, ++left;
    // debug(root);
    if (left <= 1) break;
    assert(root != -1);
    auto dis = VI(n + 1);
    bfs(root, dis);
    // debug(dis);
    PII p1 = mp(-1, -1);
    rep(i, 1, n + 1) if (!bad[i]) p1 = max(p1, mp(dis[i], i));
    bfs(p1.y, dis);
    PII p2 = mp(-1, -1);
    rep(i, 1, n + 1) if (!bad[i]) p2 = max(p2, mp(dis[i], i));
    int a = p1.y, b = p2.y; // diameter
    int lca = query(a, b);
    auto deep = VI(n + 1);
    auto fa = VI(n + 1);
    auto son = VI(n + 1);
    auto size = VI(n + 1);
    function<void(int, int, int)> dfs1;
    dfs1 = [&](int cur, int father, int dep) -> void {
      fa[cur] = father;
      deep[cur] = dep;
      size[cur] = 1;
      son[cur] = 0;
      for(int i = 0; i < (int)G[cur].size(); i++) {
        int nx = G[cur][i];
        if(nx != father) {
          dfs1(nx, cur, dep + 1);
          size[cur] += size[nx];
          if(size[nx] > size[son[cur]]) {
            son[cur] = nx;
          }
        }
      }
    };
    dfs1(lca, 0, 0);
    vector<int> gg;
    while (a != lca) gg.pb(a), a = fa[a];
    while (b != lca) gg.pb(b), b = fa[b];
    for (auto v: gg) {
      // debug(v);
      bad[v] = 1;
      function<void(int)> dfs = [&](int cur) -> void {
        for (auto nx: G[cur]) {
          if (nx == fa[cur]) continue;
          bad[nx] = true;
          dfs(nx);
        }
      };
      dfs(v);
    }
    vector<vector<int>> new_G(n + 1);
    rep(i, 1, n + 1) {
      if (bad[i]) continue;
      for (auto nx: G[i]) {
        if (bad[nx]) continue;
        new_G[i].pb(nx);
      }
    }
    // debug(bad);
    G = new_G;
  }
  int ans = -1;
  rep(i, 1, n + 1) if (!bad[i]) ans = i;
  cout << "! " << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}