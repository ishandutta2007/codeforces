#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;


ll qpower(ll a,ll b)
{
  ll ans = 1;
  while(b>0) {
    if(b&1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}

ll n,m,k;
int main(int argc, char const *argv[]) {

  std::cin >> n >> m >> k;
  if(n % 2 != m % 2 && k==-1) {
    std::cout << "0" << '\n';
    return 0;
  }
  std::cout << qpower( qpower(2, n - 1), m - 1) << '\n';
  return 0;
}