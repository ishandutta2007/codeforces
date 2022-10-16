#include<bits/stdc++.h>
#define next Cry_For_theMoon
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define pre(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
typedef double db;
using namespace std;
ll t,x,y,ans;
int main(){
	cin>>t;
	while(t--){
		cin>>x>>y;
		ans=0;
		for(ll k=1;k*(k+1)<=x;k++){
			ll rlim=min(y,x/k-1);
			ans+=max(0LL,rlim-k);
		}
		cout<<ans<<endl;
	}
	return 0;
}