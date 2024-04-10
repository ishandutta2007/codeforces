#include <bits/stdc++.h>

using namespace std;


#define int long long

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin>>t;
  while (t--){
    int m,d,w;
    cin>>m>>d>>w;
    cout<<(min(m,d)-1)/(w/__gcd(w,d-1))*min(m,d)-(w/__gcd(w,d-1))*((min(m,d)-1)/(w/__gcd(w,d-1)))*((min(m,d)-1)/(w/__gcd(w,d-1))+1)/2<<"\n";
  }
  return 0;
}