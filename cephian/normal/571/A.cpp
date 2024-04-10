#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);

  ll l;
  ll a[3];
  cin >> a[0] >> a[1] >> a[2] >> l;
  ll all = ((l+3)*(l+2)*(l+1))/6;
  for(int i = 0; i < 3; ++i) {
    int j = (i+1) % 3;
    int k = (i+2) % 3;
    int osum = a[j] + a[k];
    for(int ap = a[i]; ap <= a[i] + l; ++ap) {
      ll diff = ap - osum;
      if(ap <= a[j] || ap <= a[k]) continue;
      if(diff < 0) continue;
      diff = min(diff, l - (ap - a[i]));
      all -= ((diff+2)*(diff+1))/2;
    }
  }
  cout << all << endl;
  return 0;
}