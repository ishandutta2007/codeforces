#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> div_b;
unordered_map<ll,ll> di;
vector<ll> d;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N,b;
		cin>>N>>b;
		for(ll i=2;i*i<=b;i++){
      if(b%i==0){
        d.push_back(i);
        while(b%i==0){
            b/=i;
            div_b[i]++;
        }
      }
		}
		if(b>1){
      div_b[b]++;
      d.push_back(b);
		}
		for(ll i=0;i<d.size();i++){
      ll k=d[i];
      di[d[i]]+=N/k;
      while(k<=N/d[i]+1){
        k*=d[i];
        di[d[i]]+=N/k;
      }
		}
		ll mi=1e18;
		for(ll i=0;i<d.size();i++){
      ll a=d[i];
      mi=min(mi,di[a]/div_b[a]);
		}
		cout<<mi<<endl;
    return 0;
}