%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
ll n, m, q;
 
ll gcd(ll n, ll m) {
  return m ? gcd(m, n % m) : n;
} 
 
int main() {
  scanf("%lld%lld%lld", &n, &m, &q);
  ll g = gcd(n, m);
  ll n2 = n / g, m2 = m / g;
  for (int i = 1; i <= q; i++) {
    ll sx, sy, ex, ey;
    scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
    ll p1, p2;
    if (sx == 1) p1 = (sy - 1) / n2 + 1;
    else p1 = (sy - 1) / m2 + 1;
    if (ex == 1) p2 = (ey - 1) / n2 + 1;
    else p2 = (ey - 1) / m2 + 1;
    
    if (p1 == p2) puts("YES"); else puts("NO");
  }
  return 0;
}