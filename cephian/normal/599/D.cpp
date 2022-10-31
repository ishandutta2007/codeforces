#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll x;
vector<pll> v;

int main() {
  ios::sync_with_stdio(0);
  cin >> x;
  for(ll n = 1; n <= 2000000; ++n) {
    ll a = (n*n)-(n*(n-1))/2;
    ll b = (n*(n-1)*(2*n-1))/6 - (n*n*(n-1))/2;
    ll m = (x-b)/a;
    if(m*a+b == x) {
      if(n > m)
        continue;
      v.push_back(pll(n,m));
      if(n != m) v.push_back(pll(m,n));
    }
  }
  sort(v.begin(),v.end());
  cout << v.size() << "\n";
  for(int i = 0; i < v.size(); ++i) {
    cout << v[i].first << " " << v[i].second << "\n";
  }
  return 0;
}