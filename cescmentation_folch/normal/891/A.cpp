#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int A[n];
  int res = 2*n;
  for (int i = 0; i < n;  ++i) cin >> A[i];
  int tt = 2*n;
  int cont = 0;
  for (int i = 0; i < n; ++i) {
    int k = A[i];
    if (k != 1) ++cont;
    tt = min(tt, k);
    for (int j = i; j < n; ++j) {
      k = gcd(k, A[j]);
      if (k == 1) {
        res = min(res, n + j - i -1);
      }
    }
  }

  if (res == 2*n) cout << -1 << '\n';
  else if (tt == 1) cout << cont << '\n';
  else cout << res << '\n';
}