#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
const int kMod = 998244353;

int fact(int n) {
  if (n <= 1) return 1;
  return 1LL * fact(n - 1) * n % kMod;
}
int inv(int x) {
  int e = kMod - 2;
  int r = 1;
  while (e) {
    if (e % 2) r = 1LL * r * x % kMod;
    x = 1LL * x * x % kMod;
    e /= 2;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; ++i)
    cin >> a[i];
  sort(a.begin(), a.end());

  long long coef = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (i < n) coef -= a[i];
    else coef += a[i];
  }

  coef %= kMod;
  coef = 1LL * coef * fact(2 * n) % kMod;
  coef = 1LL * coef * inv(fact(n)) % kMod;
  coef = 1LL * coef * inv(fact(n)) % kMod;
  cout << coef << endl; 



  return 0;
}