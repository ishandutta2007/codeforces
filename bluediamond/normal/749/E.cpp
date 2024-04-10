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
#define int ll
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

int gauss(int x) {
  return x * (x + 1) / 2;
}

const int N = (int) 1e5 + 7;
int n, a[N], aib[N];
ld sol;

void add(int i, int x) {
  while (i <= n) {
    aib[i] += x;
    i += i & (-i);
  }
}

int pre(int i) {
  int sol = 0;
  while (i) {
    sol += aib[i];
    i -= i & (-i);
  }
  return sol;
}

void clr() {
  for (int i = 1; i <= n; i++) {
    aib[i] = 0;
  }
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  clr();
  for (int i = n; i >= 1; i--) {
    sol += n * (n + 1) / 2 * pre(a[i]);
    add(a[i], +1);
  }
  clr();
  for (int i = 1; i <= n; i++) {
    sol -= (n + 1 - i) * pre(n + 1 - a[i]);
    add(n + 1 - a[i], i);
  }
  clr();
  sol *= 2;
  for (int i = 1; i <= n; i++) {
    sol += i * ((n + 1) * (n - i) - (gauss(n) - gauss(i)));
  }
  cout << fixed << setprecision(9) << sol / (ld) (n * (n + 1)) << "\n";
  return 0;
}