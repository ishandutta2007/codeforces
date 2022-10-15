#include <bits/stdc++.h>

using namespace std;

///#define int ll
typedef long long ll;
typedef long double ld;

///#define int ll

const int N = (int) 5e5 + 7;
int q, sol[N];

vector<int> r[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n = 0;

  cin >> q;
  for (int iq = 1; iq <= q; iq++) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int x;
      cin >> x;
      n++;
      r[x].push_back(n);
    } else {
      int x, y;
      cin >> x >> y;

      if (x == y) {
        continue;
      }

      if ((int) r[x].size() <= (int) r[y].size()) {
        for (auto &it : r[x]) {
          r[y].push_back(it);
        }
        r[x].clear();
      } else {
        swap(r[x], r[y]);
        /// (int) r[x].size() <= (int) r[y].size()
        for (auto &it : r[x]) {
          r[y].push_back(it);
        }
        r[x].clear();
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (auto &it : r[i]) {
      sol[it] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n";


  return 0;
}