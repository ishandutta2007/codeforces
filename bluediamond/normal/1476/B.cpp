#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = 100 + 7;
int n, k, p[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int sum = 0, ret = 0;
    for (int i = 0; i + 1 < n; i++) {
      sum += p[i];
      int need = ((p[i + 1] * 100 + k - 1) / k);
      if (sum < need) {
        ret += need - sum;
        sum = need;
      }
    }
    cout << ret << "\n";
  }

}