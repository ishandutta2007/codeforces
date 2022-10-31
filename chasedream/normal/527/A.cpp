%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

long long n, m;
long long cnt = 0LL;

int main() {
  scanf("%lld%lld", &n, &m);
  if (n > m) swap(n, m);
  while (n > 0) {
    cnt += m / n;
    m %= n;
    swap(n, m); 
  } 
  printf("%lld\n", cnt);
  return 0;
}