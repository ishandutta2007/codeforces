#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;

int main(){
	int i,j;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;cin>>_;
	while(_--){
		cin>>n;
		ll mnl=1e18,mlc=1e18,mxr=0,mrc=1e18,mx=0,mnc=1e18;
		for(i=1;i<=n;i++){
			ll l,r,c;cin>>l>>r>>c;
			if(l<mnl){
				mnl=l;
				mlc=c;
			}
			else if(l==mnl) mlc=min(mlc,c);
			if(r>mxr){
				mxr=r;
				mrc=c;
			}
			else if(r==mxr) mrc=min(mrc,c);
			if(r-l+1>mx){
				mx=r-l+1;
				mnc=c;
			}
			else if(r-l+1==mx) mnc=min(mnc,c);
			if(mx==mxr-mnl+1) cout<<min(mnc,mlc+mrc)<<endl;
			else cout<<mlc+mrc<<endl;
		}
	}
	return 0;
}