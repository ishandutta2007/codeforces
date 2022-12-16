#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n, q;

int loc[100];
const int INF = 0x3f3f3f3f;
int a[300300];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  memset(loc, INF, sizeof loc);
  cin >> n >> q;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for (int i=n; i>=1; --i) {
    loc[a[i]] = i;
  }
  for (int i=1; i<=q; ++i) {
    int t;
    cin >> t;
    int p = loc[t];
    cout << p << " ";
    for (int j=1; j<=50; ++j) {
      if (loc[j] < p) {
        loc[j]++;
      }
    }
    loc[t] = 1;
  }
  cout << "\n";
  return 0;
}