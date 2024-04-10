#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,unordered_map<ll,ll> > memo;
ll mod=998244353;
ll pot(ll a,ll b){
  if(b==0)return 1;
  if(memo[a][b]>0)return memo[a][b];
  if(b%2)return memo[a][b]=(pot(a,b-1)*a)%mod;
  return memo[a][b]=(pot(a,b/2)*pot(a,b/2))%mod;
}
vector<ll> v(1000010,0);
vector<vector<ll> > p;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N;
		cin>>N;
		for(ll i=0;i<N;i++){
      ll K;
      cin>>K;
      p.push_back(vector<ll>());
      for(ll j=0;j<K;j++){
        ll a;
        cin>>a;
        v[a]++;
        p[i].push_back(a);
      }
		}
		ll tot=0;
		for(ll i=0;i<N;i++){
      for(ll j=0;j<p[i].size();j++){
        ll den=(N*p[i].size()*N);
        ll num=v[p[i][j]];
        den%=mod;
        tot+=(num*pot(den,mod-2))%mod;
        tot%=mod;
      }
		}
		cout<<tot<<endl;
    return 0;
}