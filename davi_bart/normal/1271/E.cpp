#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pot;
ll N,K;
ll c(ll p){
  if(p>N)return 0;
  ll o=min(1,__builtin_ctz(p));
  ll tot=1ll<<o;
  if(2*p>N){
    return 2-p%2;
  }
  while(p*2+(1ll<<(o+1))<=N){
    p*=2;
    o++;
    tot+=1ll<<o;
  }
  if(p*2<=N)p*=2;
  else return tot;
  tot+=N-p+1;
  return tot;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    cin>>N>>K;
    pot.push_back(1);
    for(int i=0;i<62;i++)pot.push_back(pot[i]*2);
    ll p=61;
    ll val=0;
    while(p>=0){
      while(c(val+pot[p])<K){
          p--;
          if(p==-1){
            cout<<val;
            return 0;
          }
      }
      val+=pot[p];
      p--;
    }
            cout<<val;
    return 0;
}