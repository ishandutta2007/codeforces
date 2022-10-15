#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    return a - MOD;
  }
  if (a < 0) {
    return a + MOD;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % MOD;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

const int N = 100000 + 7;
int fib[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fib[0] = fib[1] = 1;
  for (int i = 2; i < N; i++) {
    fib[i] = add(fib[i - 1], fib[i - 2]);
  }
  int n, m;
  cin >> n >> m;
  int tot = add(fib[n], fib[m]);
  tot = add(tot, -1);
  tot = mul(tot, 2);
  cout << tot << "\n";


}