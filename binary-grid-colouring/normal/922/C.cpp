#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e6+3;
const ll INF =2e15;

ll n,k;
std::map<ll, ll> mp;
int main(int argc, char const *argv[]) {

  std::cin >> n  >> k;
  // for(int i=1;i<=5;i++) {
  //   for(int j=1;j<i;j++) {
  //     for(int k=j+1;k<i+1;k++) {
  //       if(n%j==n%k) {
  //         std::cout << i <<" " <<j<<" " << k << '\n';
  //       }
  //     }
  //   }
  // }
  if(n==1 && k==1) {
    std::cout << "Yes" << '\n';
    return 0;
  }
  if(n==1 && k==2) {
    std::cout << "Yes" << '\n';
    return 0;
  }
  if(k>=n) {
    std::cout << "No" << '\n';
    return 0;
  }
  ll limit = min(100000000LL,k);
  for(ll i=1;i<=limit;i++) {
    mp[n%i]++;
    if(mp[n%i]>=2) {
      std::cout << "No" << '\n';
      return 0;
    }
  }
  std::cout << "Yes" << '\n';
  return 0;
}