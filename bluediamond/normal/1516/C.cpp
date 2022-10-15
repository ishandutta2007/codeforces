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

signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

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

const int N = 100 + 7;
const int L = 2000 * N + 7;
int n, a[N];
bool can[L];

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (1) {
    int j = -1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 == 1) {
        j = i;
        break;
      }
    }
    if (j == -1) {
      for (int i = 1; i <= n; i++) {
        a[i] /= 2;
      }
      continue;
    }

    if (sum % 2) {
      cout << "0\n";
      return 0;
    }
    sum /= 2;
    /// daca pot face sum, scot un nr impar si fac suma impara
    can[0] = 1;
    int ant = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = ant; j >= 0; j--) {
        if (can[j]) {
          can[j + a[i]] = 1;
        }
      }
      ant += a[i];
    }
    if (!can[sum]) {
      cout << "0\n";
      return 0;
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 == 1) {
        cout << "1\n";
        cout << i << "\n";
        return 0;
      }
    }
    assert(0);
  }
  return 0;
}