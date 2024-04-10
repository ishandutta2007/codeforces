#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll mod=998244353;
unordered_map<ll,ll> memo;
ll pot(ll base,ll exp){
  if(memo[exp]>0)return memo[exp];
  if(exp==1)return base;
  if(exp==0)return 1;
  if(exp%2)return memo[exp]=(pot(base,exp-1)*base)%mod;
  return memo[exp]=(pot(base,exp/2)*pot(base,exp/2))%mod;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		cin>>N;
		for(int i=0;i<N;i++){
      ll a;
      cin>>a;
      v.push_back(a);
		}
		ll sol=1;
		for(int i=0;i<N;i++){
      sol*=(100*pot(v[i],mod-2))%mod;
      if(i<N-1)sol++;
      sol%=mod;
      memo.clear();
		}
		cout<<sol<<endl;
}