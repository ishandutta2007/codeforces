#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > g1, g2;
vector<pair<int, int> > rng;

int timer;

void dfs(int vertex) {
  rng[vertex].x = timer++;
  for (auto x : g2[vertex]) dfs(x);
  rng[vertex].y = timer - 1;
}

int ans;
set<pair<int, int> > ms;

void dfs2(int vertex) {

  ans = max(ans, (int) ms.size());
  for (auto x : g1[vertex]) {

    auto pp = rng[x];

    bool add = true;
    pair<int, int> dlt = mp(-1, -1);

    if (ms.size()) {
      auto it = ms.lower_bound(mp(pp.x, 1e9));

      if (it != ms.end()) {
        auto q = (*it);
        if (q.x >= pp.x && q.y <= pp.y) {
          add = false;
        }
      }

      if (add) {

        if (it != ms.begin()) {
          it--;
          auto q = (*it);
          if (q.x <= pp.x && q.y >= pp.y) {
            dlt = q;
            ms.erase(it);
          }
        }

      }
    }

    if (add) ms.insert(pp);
    dfs2(x);
    if (add) ms.erase(ms.find(pp));

    if (dlt != mp(-1, -1)) {
      ms.insert(dlt);
    }

  }

}

void solve() {

  int n;
  cin >> n;

  g1.assign(n, {});
  g2.assign(n, {});

  for (int i = 0; i < n-1; ++i) {
    int x;
    cin >> x;

    g1[x-1].pb(i+1);
  }

  for (int i = 0; i < n-1; ++i) {
    int x;
    cin >> x;

    g2[x-1].pb(i+1);
  }

  rng.assign(n, mp(-1, -1));
  timer = 0;
  dfs(0);

  ans = 1;
  ms.clear();
  ms.insert(rng[0]);

  dfs2(0);
  cout << ans << '\n';


}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}