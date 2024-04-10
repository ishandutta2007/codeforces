#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
pair<pair<int, int>, int> a[200007];
int val[200007];

vector<int> g[200007];
int was[200007];

vector<int> w[2];

void dfs(int v, int cc) {
  w[cc].pb(val[v]);
  was[v] = 1;
  for (int to : g[v]) if (!was[to]) dfs(to, cc ^ 1);
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i].x.x >> a[i].x.y;

  for (int i = 0; i < n; ++i) {
    a[i].y = i;
    if (a[i].x.x > a[i].x.y) {
      swap(a[i].x.x, a[i].x.y);
      val[i] = 1;
    }
    if (a[i].x.x > n) cout << -1,exit(0);
    if (a[i].x.y <= n) cout << -1,exit(0);
  }

  sort(a, a + n);

  set<pair<int, int>> se;

  int conf = 1e9;
  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    if (se.size() == 0) se.insert(mp(a[i].x.y, a[i].y)), cnt = 1;
    else {
      if ((*se.begin()).x > a[i].x.y) {
        ++cnt;
      } else {
        if (a[i].x.y > conf) cout << -1, exit(0);
        conf = a[i].x.y;        
          
        int dd = 0;
        for (auto c : se) {
          if (c.x > a[i].x.y) break;
          ++dd;
          g[a[i].y].pb(c.y);
          g[c.y].pb(a[i].y);
       //   cout << a[i].y + 1 << ' ' << c.y + 1 << endl;
          if (cnt == dd - 1) break;
        }

        cnt = 0;

        // cout << a[i].y + 1 << ' ' << se.begin()->second + 1 << endl;
      }
      se.insert(mp(a[i].x.y, a[i].y));
    }
  }
  int res = 0;

  for (int i = 0; i < n; ++i) if (!was[i]) {
    w[0].clear();
    w[1].clear();
    dfs(i, 0);
    
    int res1 = 0, res2 = 0;

    for (int x : w[0]) res1 += x == 0, res2 += x == 1;
    for (int x : w[1]) res1 += x == 1, res2 += x == 0;

    res += min(res1, res2);
  }


  cout << res;
}