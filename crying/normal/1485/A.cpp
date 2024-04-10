#include<bits/stdc++.h>
#define next Cry_For_theMoon
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define pre(i,a,b) for(ll i=(b);i>=(a);i--)
typedef long long ll;
typedef double db;
using namespace std;
ll t,a,b,l,r,ans;
ll calc(ll a,ll b,ll c){
	rep(i,1,c)a/=b;
	return a;
}
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		ans=1e18;
		rep(i,1,50){
			ll l=0,r=2e9,ret=0;
			while(l<=r){
				ll mid=l+r>>1;
				if(calc(a,b+mid,i)){
					l=mid+1;
				}else{
					ret=mid;
					r=mid-1;
				}
			}
			ans=min(ans,i+ret);
		}
		printf("%lld\n",ans);
	}

	return 0;
}