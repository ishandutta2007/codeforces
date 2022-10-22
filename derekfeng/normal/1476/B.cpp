#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,k;
ll ans,p[103];
ll got(ll x){
	ll num=100*x/k+(100*x%k>0);
}
int main(){
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>k;
		for(int i=0;i<n;i++)cin>>p[i];
		ll l=p[0]-1,r=1e12+1;
		while(l<r-1){
			ll mid=(l+r)>>1;
			ll now=mid;
			bool ok=1;
			for(int i=1;i<n;i++){
				if(p[i]*100>now*k)ok=0;
				now+=p[i];
			}
			if(ok)r=mid;
			else l=mid;
		}
		cout<<r-p[0]<<"\n";
	}
}