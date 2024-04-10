#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int n;
map<ll,int> nm;

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    for(ll k  = 2; k <= 4294967296LL; k*=2) {
      ans += nm[k-a];
    }
    ++nm[a];
  }
  cout << ans << "\n";
}