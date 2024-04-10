#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll a[123456],b[123456];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  for(int i=0;i<n;i++) {
    std::cin >> a[i] >> b[i];
  }
  ll xsum = 0 , ysum = 0;
  ll x2sum=0, y2sum=0;
  for(int i=0;i<n;i++) {
    xsum += a[i];
    ysum += b[i];
    x2sum += 1LL * a[i] * a[i];
    y2sum += 1LL * b[i] * b[i];
  }
  ll ans = n * x2sum - xsum * xsum +  n * y2sum - ysum * ysum;
  std::cout << ans << '\n';
  return 0;
}