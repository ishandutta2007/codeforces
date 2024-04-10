#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = (int) 1e6 + 7;
int n, k, phi[N];

void calc() {
  for (int i = 1; i <= n; i++) {
    phi[i] = i;
  }
  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) {
        phi[j] /= i;
        phi[j] *= (i - 1);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  if (k == 1) {
    cout << "3\n";
    return 0;
  }
  calc();
  sort(phi + 3, phi + n + 1);
  int ret = 0;
  for (int i = 1; i <= k; i++) {
    ret += phi[2 + i];
  }
  cout << ret + 2 << "\n";
}