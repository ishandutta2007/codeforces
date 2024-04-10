#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
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

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

const int N = (int) 2e5 + 7;
int n, a[N];

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cnt = 1;
    while (cnt + 1 <= n && a[cnt + 1] == a[cnt]) cnt++;
    int prod = 1;
    for (int i = 1; i <= n; i++) {
      if ((a[i] & a[1]) != a[1]) {
        prod = 0;
      }
    }
    if (!prod) {
      cout << "0\n";
      continue;
    }
    int ret = mul(cnt, cnt - 1);
    for (int j = 1; j <= n - 2; j++) {
      ret = mul(ret, j);
    }
    cout << ret << "\n";
  }
  return 0;
}
/**
a1=a2&a3&a4
a1&a2=a3&a4
a1&a2&a3=a4

primul e descrescator, al doilea e crescator =>
toate sunt constante

a1=a1&a2=a1&a2&a3
a2&a3&a4=a3&a4=a4

=> a2 il contine pe a1
=> a3 il contine pe a1

=> a3 il contine pe a4
=> a2 il contine pe a4



**/