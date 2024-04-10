#include <iostream>

using namespace std;
typedef long long ll;

ll c(ll k,ll a) {
  return (k+a-1)/a;
}

int main() {
  ll n,m,a;
  cin >> n >> m >> a;
  cout << c(m,a)*c(n,a) << endl;
  return 0;
}