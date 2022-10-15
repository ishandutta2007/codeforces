#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroint-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 2e5 + 7;
int n, where[N], skill[N], sol[N], pre[N];
vector<int> a[N];
vector<int> ids[N];

signed realMain() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      a[i].clear();
      sol[i] = 0;
      ids[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      cin >> where[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> skill[i];
      a[where[i]].push_back(skill[i]);
    }
    for (int i = 1; i <= n; i++) {
      sort(a[i].rbegin(), a[i].rend());
      ids[(int) a[i].size()].push_back(i);
    }
    for (int s = 1; s <= n; s++) {
      if (ids[s].empty()) {
        continue;
      }
      for (int i = 0; i <= n; i++) {
        pre[i] = 0;
      }
      for (auto &i : ids[s]) {
        int cur = 0;
        for (int j = 1; j <= s; j++) {
          cur += a[i][j - 1];
          pre[j] += cur;
        }
      }
      for (int k = 1; k <= n; k++) {
        int sz = s;
        sz /= k;
        sz *= k;
        sol[k] += pre[sz];
      }
    }
    for (int k = 1; k <= n; k++) {
      cout << sol[k] << " ";
    }
    cout << "\n";
  }
  return 0;
}