#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll x,ll y) {
  x/=__gcd(x,y);
  return x*y;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    vector<int> dd;
    for (int i=1;i*i<=n;i++) {
      if (n%i==0) {
        dd.push_back(i);
        if (i*i==n) continue;
        dd.push_back(n/i);
      }
    }
    ll sol=n-1,a=1,b=n-1;
    for (auto &d : dd) {
      ll s=n/d;
      if (s==1) continue;
      ll cur=(s-1)*d;
      if (cur<sol) {
        sol=cur;
        a=d;
        b=d*(s-1);
      }
    }
    cout<<a<<" "<<b<<"\n";
  }
  return 0;
}