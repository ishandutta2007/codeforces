#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(a) cerr << #a << " = " << a << endl; 
#define forn(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

int n, a, b, da, db;
vector<int> g[100007];

pair<int, int> dfs(int v, int p = -1) {
  auto res = mp(0, v);
  for (auto to : g[v]) if (to != p) {
    auto now = dfs(to, v);
    now.x++;
    res = max(now, res);
  }
  return res;
}

int dist(int v,  int need, int p = -1) {
  if (need == v) return 0;
  for (int to : g[v]) if (to != p) {
    int f = dist(to, need, v);
    if (f != -1) return f + 1;
  }
  return -1;
}

void solve() {
  cin >> n >> a >> b >> da >> db;
  --a; --b;
  for (int i = 0; i < n; ++i) g[i].clear();
  for (int i = 0; i + 1 < n; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

//  cout << dist(a, b) << endl;

  if (da * 2 + 1 <= db && dist(a, b) > da) {

    auto [_, w] = dfs(0);
    auto [dist, _2] = dfs(w);

    if (dist >= da * 2 + 1) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
    }


  } else {
    cout << "Alice\n";
  }

}


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }

}