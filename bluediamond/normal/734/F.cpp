#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());


const int N = 200000 + 7;
int __and[N], __or[N], foo[N];


void place(int n, int a[], int b[], int c[]) {
  for (int bit = 0; bit <= 60; bit++) {
    int ones = 0;
    for (int i = 1; i <= n; i++) {
      __and[i] = __or[i] = 0;
      foo[i] = !!(a[i] & (1LL << bit));
      ones += foo[i];
    }


    for (int i = 1; i <= n; i++) {
      if (foo[i]) {
        __and[i] = ones;
        __or[i] = n;
      } else {
        __or[i] = ones;
      }
    }

    for (int i = 1; i <= n; i++) {
      b[i] += __and[i] * (1LL << bit);
      c[i] += __or[i] * (1LL << bit);
    }
  }
}

int n, b[N], c[N], sum[N], sol[N], bsol[N], csol[N];



signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  time_t bg = clock();

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  int all = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = b[i] + c[i];
    all += sum[i];
  }
  if (all % (2 * n)) {
    cout << "-1\n";
    return 0;
  }
  all /= (2 * n);
  for (int i = 1; i <= n; i++) {
    sum[i] -= all;
    if (sum[i] < 0 || sum[i] % n) {
      cout << "-1\n";
      return 0;
    }
    sol[i] = sum[i] / n;
  }
  place(n, sol, bsol, csol);
  for (int i = 1; i <= n; i++) {
    if (b[i] != bsol[i] || c[i] != csol[i]) {
      cout << "-1\n";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n";
}