%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
#define int long long 
const int N = 1000005;
ll a[N], n;
 
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;
} 
signed main() {
  scanf("%lld", &n);
  scanf("%lld", &a[1]);
  for (int i = 2; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[1] = gcd(a[1], a[i]);
  }  
  ll g = a[1]; int cnt = 0;
  for (int i = 1; i <= sqrt(g); i++) {
    if (g % i == 0) {
      cnt++;
      if ((ll)i * i != g) cnt++;
    }
  } 
  printf("%lld\n", cnt);
}