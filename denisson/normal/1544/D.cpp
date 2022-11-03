#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
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

int n;
int to[200007];
int was[200007];
vector<int> g[200007];;

int res = 0;

int ans[200007];

// int used[200007];

int bad[200007];

vector<int> st;
void dfs(int v) {
//  cout << v << ' ' << to[v] << endl;
  st.pb(v);
  was[v] = 1;



  if (was[to[v]]) {

   /* if (!used[to[v]]) {

      ans[v] = to[v];
      used[to[v]] = 1;
      ++res;
    } */

  } else {

    ans[v] = to[v];
 //   ++res;

    dfs(to[v]);
  }
}

void go(int v) {
  was[v] = 1;

    ans[v] = to[v];


  if (was[to[v]]) {
  } else {

  //  ++res;

    go(to[v]);
  }
}


void solve() {
  cin >> n;
  
  for (int i = 0; i < n; ++i) was[i] = bad[i] = 0, g[i].clear();

  for (int i = 0; i < n; ++i) {
    cin >> to[i]; --to[i];
    bad[to[i]] = 1;
    g[to[i]].pb(i);
  }

  res = 0;

  vector<int> D;
  vector<pair<int, int>> F;


  for (int i = 0; i < n; ++i) if (!bad[i]) {
  //  cout << "START" << i << endl;
    st.clear();
    dfs(i);
    if (st.size() == 1) {
      D.pb(st[0]);
    } else {
      F.pb(mp(st[0], st.back()));
    }
  }

  for (int i = 0; i < n; ++i) if (!was[i]) {
  //  cout << "======" << i << endl;
    go(i);
  }

  if (F.size() > 0) {
    for (int i = 1; i < F.size(); ++i) ans[F[i].y] = F[i].x;
    int last = F[0].y;
    for (int v : D) {
      ans[last ]= v;
      last = v;
    }
    ans[last] = F[0].x;
  }

  res = 0;
  for (int i = 0; i < n; ++i) res += ans[i] == to[i];

  cout << res << "\n";
  for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
  cout << "\n";

/*

  for (int i = 0; i < n; ++i) if (!was[i]) {
    st.clear();
    dfs(i);
  }

  for (auto& c : cycs) for (int v : c) cy[v] = 1;

  int res = 0;
  set<int> se;
  for (int i = 0; i < n; ++i) ans[i] = -1, se.insert(i);

  ///

  vector<pair<int, int> > PA;

  for (auto& c : cycs) {
    int emp = 1;
    for (auto v : c) for (int too : g[v]) if (!cy[too]) emp = 0;

    if (emp) {
      res += c.size();
      for (auto v : c) ans[v] = to[v];
      continue;
    }

    int pos = -1;
    vector<int> r;


    for (auto v : c) for (int too : g[v]) if (!cy[too]) {
      find_ma(too);
      if (SUKA[too].size() > r.size()) {
        pos = v;
        swap(SUKA[too], r);
      }
    }

    res += (int)r.size() + (int)c.size() - 1;

    int HE = -1;


    for (int v : c) {
      if (to[v] != pos) ans[v] = to[v]; else HE = v;
    }

    PA.pb(mp(HE, r[0]));

    for (int v : r) {
      ans[v] = to[v];
    }
  }

  ///

  if (PA.size()) {

    vector<int> D;

    for (int i = 0; i < n; ++i) if (ans[i] != -1) se.erase(ans[i]);
    for (int i = 0; i < n; ++i) if (ans[i] == -1) {
      if (se.find(i) != se.end()) D.pb(i);
    }

    for (int i = 1; i < PA.size(); ++i) ans[PA[i].x] = PA[i].y;

    int last = PA[0].x;
    for (int x : D) {
      ans[last] = x;
      last = x;
    }
    ans[last] = PA[0].y;
  }

  cout << res << "\n"; */

}

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

    int tt; cin >> tt; // tt = 1;
  while (tt--) {
    solve();
  }
}