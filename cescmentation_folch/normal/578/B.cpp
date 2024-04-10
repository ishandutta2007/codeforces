#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll maxl(ll a, ll b){
  if(a > b) return a;
  return b;
}

int main(){
  int n,k;
  ll x;
  cin>>n>>k>>x;
  
  vi V(n);
  for(int i = 0;i < n;++i) cin>>V[i];
  
  if(n == 1){
    for(int i = 1;i <= k;++i) V[0] *= x;
    cout<<V[0]<<endl;
    return 0;
  }
  
  vi PE(n);
  PE[0] = V[0];
  for(int i = 1;i < n;++i) PE[i] = V[i]|PE[i-1];
  
  vi PD(n);
  PD[n-1] = V[n-1];
  for(int i = n-2;i >= 0;--i) PD[i] = V[i]|PD[i+1];
  
  ll y = x;
  for(int i = 1;i < k;++i) x*=y;
  
  ll ma = PD[0];
  int m = -1;
  //cout<<PD[0]<<endl;
  for(int i = 0;i < n;++i){
    ll t;
    if(i == 0) t = (x*V[0])|PD[1];
    else if(i == n-1) t = (x*V[i])|PE[i-1];
    else t = PE[i-1]|(x*V[i])|PD[i+1];
    
    if(t > ma){ 
      m = i;
      ma = t;
    }
  }
  
  if(m > -1) V[m] *= x;
  
  PE[0] = V[0];
  for(int i = 1;i < n;++i) PE[i] = V[i]|PE[i-1];
  
  PD[n-1] = V[n-1];
  for(int i = n-2;i >= 0;--i) PD[i] = V[i]|PD[i+1];
  
  
  cout<<PD[0]<<endl;
}