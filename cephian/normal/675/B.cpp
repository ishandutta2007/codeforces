#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  ll a[4];
  for(int i = 0; i < 4; ++i)
    cin >> a[i];
  swap(a[2],a[3]);
  ll mns = 0x7fffffff,mxs=0;
  for(int i = 0; i < 4; ++i) {
    mxs = max(mxs, a[i]+a[(i+1)&3]);
    mns = min(mns, a[i]+a[(i+1)&3]);
  }
  cout << max(ll(0),n*(n-(mxs-mns))) << "\n";
  return 0;
}