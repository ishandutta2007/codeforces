#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
ll n,m,k; 
ll f(ll x){
	return x<0?-x:x;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m>>k;
		ll dis=max(n,m);
		ll ans=0;
		if(k<dis){
			cout<<-1<<endl;
			continue;
		}
		if(k-dis>=2){
			ans+=(k-dis)/2*2;
			k=dis+((k-dis)&1);
		}
		ans+=min(n,m)+f(n-m)/2*2;
		if(k>dis){
			if(f(n-m)&1) cout<<ans+1<<endl;
			else cout<<ans-1<<endl;
		}
		else cout<<ans<<endl;
	}
	return 0;
}