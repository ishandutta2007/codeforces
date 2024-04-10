#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
ll sum[2],mn[2],lft[2];
int main(){
	cin>>T;
	while(T--){
		ll ans=114e15;
		cin>>n;
		sum[0]=sum[1]=0,mn[0]=mn[1]=1e9+114514;lft[0]=lft[1]=n;
		for(int i=0;i<n;i++){
			ll x;cin>>x;
			lft[i%2]--;mn[i%2]=min(mn[i%2],x);sum[i%2]+=x;
			if(i>0){
				ans=min(ans,sum[0]+sum[1]+lft[0]*mn[0]+lft[1]*mn[1]);
			}
		}
		cout<<ans<<"\n";
	}
}