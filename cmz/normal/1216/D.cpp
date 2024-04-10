#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int a[N];
 
int gcd(int A, int B) {
  return B ? gcd(B, A % B) : A;
}
 
int main() {
  int n;
  scanf("%d", &n);
  ll sum = 0;
  int maxn = 0;
  for(int i = 1; i <= n; ++i) {  
    scanf("%d", &a[i]);
    sum += a[i];
    maxn = max(maxn, a[i]);
  }
  int pos = 0;
  for(int i = 1; i <= n; ++i) {
    pos = gcd(pos, maxn - a[i]);
  }
  printf("%lld %d\n", (1ll * maxn * n - sum) / pos, pos);
  return 0;
}