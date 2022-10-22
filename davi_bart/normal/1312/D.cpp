#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll pot(ll base,ll esp){
  if(esp==0)return 1;
  ll k=pot(base,esp/2);
  if(esp%2)return (((k*k)%mod)*base)%mod;
  return (k*k)%mod;
}
vector<ll> fact;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll N,M;
    cin>>N>>M;
    fact.push_back(1);
    for(ll i=1;i<300000;i++){
      fact.push_back((fact.back()*i)%mod);
    }
    ll tot=0;
    for(ll i=N-1;i<=M;i++){
      ll mult=1;
      mult=((mult*fact[i-1])*pot((fact[N-2]*fact[i-N+1])%mod,mod-2))%mod;
      mult*=N-2;
      mult%=mod;
      mult*=pot(2,N-3);
      mult%=mod;
      tot+=mult;
      tot%=mod;
    }
    cout<<tot;
    return 0;
}