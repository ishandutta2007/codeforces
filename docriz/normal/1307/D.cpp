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
#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

void my_main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(k + 1);
  rep(i, 1, k + 1) cin >> a[i];
  vector<vector<int>> G(n + 1);
  rep(i, 0, m) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  auto bfs = [&](int s, vector<int>& dis) -> void {
    assert((int)dis.size() == n + 1);
    rep(i, 1, n + 1) dis[i] = INT_MAX / 2;
    queue<int> Q;
    Q.push(s);
    dis[s] = 0;
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
  vector<int> dis1(n + 1);
  vector<int> dis2(n + 1);
  bfs(1, dis1);
  bfs(n, dis2);
  vector<pair<int, int>> ds;
  for (int i = 1; i <= k; i++) {
    int cur = a[i];
    ds.pb(mp(dis1[cur], dis2[cur]));
  }
  sort(all(ds));
  int ans = 0;
  rep(i, 0, sz(ds) - 1) {
    ans = max(ans, min(dis1[n], ds[i].x + ds[i + 1].y + 1));
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