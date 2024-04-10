#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int M = (int) 1e9 + 7;
const int N = (int) 2e6 + 7;
ll f[N];
bool oke[N];

ll g(ll i) {
  if (i <= 2) {
    return 0;
  } else {
    return f[i];
  }
}

void co() {
  for (int i = 3; i < N; i++) {
    f[i] = (2LL * f[i - 2] + f[i - 1]) % M;
    if (i % 3 == 0) {
      f[i]++;
      if (f[i] >= M) {
        f[i] -= M;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  co();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << 4LL * f[n] % M << "\n";
  }
  return 0;
}