#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

vector<vector<int> > gr;
vector<int> f;

vector<bool> used;
int n, m;

void dfs(int vertex, int need, vector<int> &current) {

  current.pb(vertex);
  used[vertex] = true;
  for (auto to : gr[vertex]) {
    if (to == need) {
      if (current.size() > 2) f = current;
    }
    if (used[to]) continue;
    dfs(to, need, current);
  }
  current.pop_back();

}

void erase(int vertex, int to) {
  for (int i = 0; i < gr[vertex].size(); ++i) {
    if (gr[vertex][i] == to) {
      swap(gr[vertex][i], gr[vertex].back());
      gr[vertex].pop_back();
      return;
    }
  }
}

vector<vector<int> > get_base() {
  vector<int> zero_bad = {(int) -1e9, 1, 0};
  vector<int> one_bad = {0, (int) -1e9, (int) -1e9};
  vector<vector<int> > dp = {zero_bad, one_bad};
  return dp;
}

vector<vector<int> > solve(int vertex) {

  f.clear();
  vector<int> path;
  used.assign(n, false);

  dfs(vertex, vertex, path);

  if (f.empty()) {

    vector<int> children;

    for (auto to : gr[vertex]) {
      erase(to, vertex);
      children.pb(to);
    }

    gr[vertex].clear();
    
    if (children.size() == 0) {
      return get_base();
    }

    vector<vector<vector<int> > > dps;
    for (auto to : children) {
      dps.pb(solve(to));
    }

    auto current = get_base();
    for (auto x : dps) {
      vector<vector<int> > new_dp(current.size() + x.size() - 1);
      for (auto &x : new_dp) {
        for (int j = 0; j < 3; ++j) x.pb(-1e9);
      }

      vector<pair<int, int> > ca, cb;
      for (int was = 0; was < current.size(); ++was) {
        for (int high = 0; high < 3; ++high) {
          if (current[was][high] < 0) continue;
          ca.pb(mp(was, high));
        }
      }

      for (int was = 0; was < x.size(); ++was) {
        for (int high = 0; high < 3; ++high) {
          if (x[was][high] < 0) continue;
          cb.pb(mp(was, high));
        }
      }

      for (auto p1 : ca) {
        for (auto p2 : cb) {
          int was = p1.x, high = p1.y, be = p2.x, t = p2.y;
          if (high + t == 1) continue;
          new_dp[was + be][high] = max(new_dp[was + be][high], current[was][high] + x[be][t]);
        }
      }

      current = new_dp;
    }

    return current;
  }

  reverse(all(f));

  for (int i = 0; i < f.size(); ++i) {
    int a = f[i], b = f[(i + 1) % f.size()];
    erase(a, b);
    erase(b, a);
  }

  vector<vector<vector<int> > > dps;
  vector<int> cf = f;

  for (auto to : cf) {
    dps.pb(solve(to));
  }

  int T = 1;
  for (auto x : dps) T += x.size();

  vector<vector<int> > ans(T);
  for (auto &x : ans) x.assign(3, -1e9);

  for (int start = 0; start < 2; ++start) {

    vector<vector<int> > current = dps[0];
    for (auto &x : current) {
      for (int j = 0; j < 3; ++j) if (j != start && j != 2) x[j] = -1e9;
    }

    for (int j = 1; j < dps.size(); ++j) {

      auto x = dps[j];

      vector<vector<int> > new_dp(current.size() + x.size() - 1);
      for (auto &x : new_dp) {
        for (int j = 0; j < 3; ++j) x.pb(-1e9);
      }

      vector<pair<int, int> > ca, cb;
      for (int was = 0; was < current.size(); ++was) {
        for (int high = 0; high < 3; ++high) {
          if (current[was][high] < 0) continue;
          ca.pb(mp(was, high));
        }
      }

      for (int was = 0; was < x.size(); ++was) {
        for (int high = 0; high < 3; ++high) {
          if (x[was][high] < 0) continue;
          cb.pb(mp(was, high));
        }
      }

      for (auto p1 : ca) {
        for (auto p2 : cb) {
          int was = p1.x, high = p1.y, be = p2.x, t = p2.y;
          if (high + t == 1) continue;
          if (j + 1 == dps.size() && start + t == 1) continue;
          new_dp[was + be][t] = max(new_dp[was + be][t], current[was][high] + x[be][t]);
        }
      }

      current = new_dp;

    }

    for (int i = 0; i < current.size(); ++i) {
      for (int j = 0; j < 3; ++j) {
        ans[i][j] = max(ans[i][j], current[i][j]);
      }
    }
  }

  return ans;




}

int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  gr.assign(n, {});
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    gr[x].pb(y);
    gr[y].pb(x);
  }

  vector<vector<int> > dp = solve(0);
  for (int i = 0; i <= n; ++i) {
    cout << max({dp[i][0], dp[i][1], dp[i][2]}) << " ";
  }

}