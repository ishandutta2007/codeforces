#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll d,k,a,b,t;
  cin >>d>>k>>a>>b>>t;
  if(d <= k) {
    cout << d*a << "\n";
    return 0;
  }
  d-=k;
  ll q = a*k;
  if(k*b <= t+a*k) {
    cout << b*d + q << "\n";
    return 0;
  }
  q += (d/k)*(t+a*k);
  d = d%k;
  q += min(t+d*a,d*b);
  cout << q << "\n";
  return 0;
}