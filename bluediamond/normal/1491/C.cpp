#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 7;
int n;
ll jump[N], done[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> jump[i];
      done[i] = 0;
    }
    ll ret = 0;
    for (int i = 1; i <= n; i++) {
      if (done[i] < jump[i] - 1) {
        ret += jump[i] - 1 - done[i];
        done[i] = jump[i] - 1;
      }
      for (int j = i + 2; j <= min(n * 1LL, i + jump[i]); j++) {
        done[j]++;
      }
      done[i + 1] += (done[i] - (jump[i] - 1));
    }
    cout << ret << "\n";
  }
}