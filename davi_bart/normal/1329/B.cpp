#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll K,mod;
vector<ll> pot;
vector<ll> memo(50,0);
ll sol(ll pos){
  if(pos==pot.size()-1)return ((K-pot[pos]+1)%mod+mod)%mod;
  if(memo[pos]>0)return memo[pos];
  memo[pos]=pot[pos];
  for(ll i=pos+1;i<pot.size();i++){
    memo[pos]+=(pot[pos]*sol(i))%mod;
  }
  memo[pos]%=mod;
  return memo[pos];
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll T;
		cin>>T;
		while(T--){
      pot.clear();
      fill(memo.begin(),memo.end(),0);
      cin>>K>>mod;
      pot.push_back(1);
      ll val=1;
      for(ll i=0;;i++){
        val*=2;
        if(val<=K)pot.push_back(val%mod);
        else break;
      }
      ll tot=0;
      for(ll i=0;i<pot.size();i++)tot+=sol(i);
      tot%=mod;
      cout<<tot<<'\n';
		}
    return 0;
}