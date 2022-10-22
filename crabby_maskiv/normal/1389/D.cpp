#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
ll k,l1,r1,l2,r2;
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m>>l1>>r1>>l2>>r2;
		if(l1>l2){
			swap(l1,l2);
			swap(r1,r2);
		}
		ll w=min(r1,r2)-max(l1,l2);if(w<0) w=0;
		if(w*n>=m){
			cout<<0<<endl;
			continue;
		}
		m-=w*n;
		ll t0=l2-r1;if(t0<0) t0=0;
		ll t1=(max(r1,r2)-l1)*2-(r1-l1)-(r2-l2)-t0;
		ll ans=1e18;
		for(i=1;i<=n;i++){
			ll sum=i*t0;
			if(i*t1>=m) ans=min(ans,sum+m);
			else{
				sum+=i*t1;
				ans=min(ans,sum+(m-i*t1)*2);
			}
		//	cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}