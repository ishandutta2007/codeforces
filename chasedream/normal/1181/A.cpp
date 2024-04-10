#include <bits/stdc++.h>
using namespace std;

long long x, y, z;

int main() {
  
  cin>>x>>y>>z;
  long long ans = (x+y)/z;
  
  long long gx = x % z;
  long long gy = y % z;
  long long ex = 0;
  if (gx + gy >= z) {
    ex = z - max(gx, gy);
  }
  else ex = 0LL;

  printf("%lld %lld\n", ans, ex);
  return 0;
}