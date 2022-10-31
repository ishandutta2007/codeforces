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
#define VI(n) vector<int>(n)
#define VII(n, m) vector<vector<int>>(n, vector<int>(m))
#define VIII(n, m, p) vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(p)))

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
int bs_biggest(int l, int r, function<bool(int)> check) {
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
int bs_smallest(int l, int r, function<bool(int)> check) {
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

void my_main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> info(n - 1);
    vector<vector<PII>> good(n - 1);
    map<PII, vector<int>> M;
    rep(i, 1, n - 1) {
      auto v = VI(3);
      rep(j, 0, 3) cin >> v[j];
      sort(v.begin(), v.end());
      M[mp(v[0], v[1])].pb(i);
      M[mp(v[0], v[2])].pb(i);
      M[mp(v[1], v[2])].pb(i);
      info[i] = v;
    }
    vector<vector<int>> G(n + 1);
    auto add_edge = [&](int x, int y) -> void {
      // debug(x, y);
      G[x].pb(y);
      G[y].pb(x);
    };
    rep(i, 1, n - 1) {
      auto& v = info[i];
      if (sz(M[mp(v[0], v[1])]) == 1) {
        add_edge(v[0], v[1]);
        good[i].pb(mp(v[0], v[1]));
      }
      if (sz(M[mp(v[0], v[2])]) == 1) {
        add_edge(v[0], v[2]);
        good[i].pb(mp(v[0], v[2]));
      }
      if (sz(M[mp(v[1], v[2])]) == 1) {
        add_edge(v[1], v[2]);
        good[i].pb(mp(v[1], v[2]));
      } 
    }
    vector<int> per;
    function<void(int, int)> dfs = [&](int cur, int fa) -> void {
      if (sz(per) == n) return;
      per.pb(cur);
      for (auto nx: G[cur]) {
        if (nx == fa) continue;
        dfs(nx, cur);
      }
    };
    dfs(1, -1);
    
    for (auto p: per) cout << p << " ";
    cout << endl;
    
    queue<int> Q;

    rep(i, 1, n - 1) {
      if (sz(good[i]) >= 2) {
        Q.push(i);
        // debug(i);
      }
    }

    vector<int> cut;
    while (!Q.empty()) {
      int cur = Q.front(); Q.pop();
      // debug(cur);
      assert(sz(good[cur]) >= 2);
      cut.pb(cur);
      auto erase = [&](PII pa) -> void {
        auto it = find(M[pa].begin(), M[pa].end(), cur);
        M[pa].erase(it);
        if (sz(M[pa]) == 1) {
          good[M[pa][0]].pb(pa);
          if (sz(good[M[pa][0]]) == 2) {
            // debug(M[pa][0]);
            Q.push(M[pa][0]);
          }
        }
      };
      rep(i, 0, 3) rep(j, i + 1, 3) {
        erase(mp(info[cur][i], info[cur][j]));
      }
    }
    for (auto c: cut) cout << c << " ";
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}