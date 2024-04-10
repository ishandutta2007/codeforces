#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, f[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      f[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      f[x]++;
    }
    int mx = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (f[i] > mx) {
        mx = f[i];
        cnt = 0;
      }
      if (f[i] == mx) {
        cnt++;
      }
    }
    int rem = n - mx * cnt;
    cout << cnt - 1 + rem / (mx - 1) << "\n";
  }
  return 0;
}