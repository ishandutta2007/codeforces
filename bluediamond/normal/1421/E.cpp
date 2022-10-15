#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef long long ll;
const int N = 200000 + 7;
int n;
int a[N];
pair<int, int> b[N];
ll sum[N];
ll sol = -(ll) 1e18;
bool act[N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if (n == 1) {
    int foo;
    cin >> foo;
    cout << foo << "\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = {a[i], i};
  }
  sort(b + 1, b + n + 1);
  for (int j = 1; j <= n; j++) {
    sum[j] = sum[j - 1] + b[j].first;
  }
  int Forbidden = 0, Voices = 0; /// Love Martin Garrix
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      Forbidden++;
    } else {
      Voices++;
    }
  }
  for (int neg = 0; neg <= n; neg++) {
    if ((neg + n) % 3 == 1) {
      int poz = n - neg;
      if (neg == Forbidden || neg == Voices) {
        for (int i = 1; i <= n; i++) {
          act[i] = 0;
        }
        for (int i = 1; i <= neg; i++) {
          act[b[i].second] = 1;
        }
        bool ok = 0;
        for (int i = 3; i <= n; i++) {
          if (act[i] != act[i - 2]) {
            ok = 1;
          }
        }
        if (ok == 0) {
          if (neg == n) {
            continue;
          }
          ll pre = sum[neg - 1] + b[neg + 1].first;
          sol = max(sol, -pre + sum[n] - pre);
          continue;
        }
      }
      sol = max(sol, -sum[neg] + (sum[n] - sum[neg]));
    }
  }
  cout << sol << "\n";
}