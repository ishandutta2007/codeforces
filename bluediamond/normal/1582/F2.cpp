#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;
///#define int ll


const int N = (int) 1e6 + 7;
const int A = 8192;
int n;
int a[N];

vector<int> where[A];
int mnpos[A]; /// mnpos[xor]

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    where[a[i]].push_back(i);
  }
  for (int i = 0; i < A; i++) {
    mnpos[i] = n + 1;
  }
  for (int lv = 0; lv < A; lv++) {
    vector<int> pos = where[lv];
    int y = (int) pos.size();
    if (y == 0) continue;
    mnpos[lv] = min(mnpos[lv], pos[0]);
    for (int bef = 0; bef < A; bef++) {
      int j = mnpos[bef];
      if (j >= pos.back()) continue;
      /// pos[ceva] > j

      int l = 0, r = (int) pos.size() - 1, ff = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (pos[mid] > j) {
          ff = pos[mid];
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      assert(ff != -1);
      mnpos[bef ^ lv] = min(mnpos[bef ^ lv], ff);
    }
  }


  mnpos[0] = 0;
  int sol = 0;
  for (int x = 0; x < A; x++) {
    sol += (mnpos[x] <= n);
  }
  cout << sol << "\n";

  for (int x = 0; x < A; x++) {
    if (mnpos[x] <= n) {
      cout << x << " ";
    }
  }
  cout << "\n";

  return 0;
}
/**



**/