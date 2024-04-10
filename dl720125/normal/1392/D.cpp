#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
using namespace __gnu_pbds;
using namespace std;

int n,dp1[200010],dp2[200010],dp3[200010],dp4[200010];
char c[200010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>c[i];
		int ans=INF;
		dp1[0]=0;
		for(int i=1;i<=n;i++) dp1[i]=INF;
		for(int i=1;i<=n;i++){
			if(i>=2){
				dp1[i]=min(dp1[i],dp1[i-2]+(c[i-1]!='R')+(c[i]!='L'));
			}
			if(i>=3){
				dp1[i]=min(dp1[i],dp1[i-3]+(c[i-2]!='R')+(c[i-1]!='R')+(c[i]!='L'));
			}
			if(i>=3){
				dp1[i]=min(dp1[i],dp1[i-3]+(c[i-2]!='R')+(c[i-1]!='L')+(c[i]!='L'));
			}
			if(i>=4){
				dp1[i]=min(dp1[i],dp1[i-4]+(c[i-3]!='R')+(c[i-2]!='R')+(c[i-1]!='L')+(c[i]!='L'));
			}
		}
		ans=min(ans,dp1[n]);
		c[n+1]=c[1];
		dp2[1]=0;
		for(int i=2;i<=n+1;i++) dp2[i]=INF;
		for(int i=2;i<=n+1;i++){
			if(i>=3){
				dp2[i]=min(dp2[i],dp2[i-2]+(c[i-1]!='R')+(c[i]!='L'));
			}
			if(i>=4){
				dp2[i]=min(dp2[i],dp2[i-3]+(c[i-2]!='R')+(c[i-1]!='R')+(c[i]!='L'));
			}
			if(i>=4){
				dp2[i]=min(dp2[i],dp2[i-3]+(c[i-2]!='R')+(c[i-1]!='L')+(c[i]!='L'));
			}
			if(i>=5){
				dp2[i]=min(dp2[i],dp2[i-4]+(c[i-3]!='R')+(c[i-2]!='R')+(c[i-1]!='L')+(c[i]!='L'));
			}
		}
		ans=min(ans,dp2[n+1]);
		c[n+2]=c[2];
		dp3[2]=0;
		for(int i=3;i<=n+2;i++) dp3[i]=INF;
		for(int i=3;i<=n+2;i++){
			if(i>=4){
				dp3[i]=min(dp3[i],dp3[i-2]+(c[i-1]!='R')+(c[i]!='L'));
			}
			if(i>=5){
				dp3[i]=min(dp3[i],dp3[i-3]+(c[i-2]!='R')+(c[i-1]!='R')+(c[i]!='L'));
			}
			if(i>=5){
				dp3[i]=min(dp3[i],dp3[i-3]+(c[i-2]!='R')+(c[i-1]!='L')+(c[i]!='L'));
			}
			if(i>=6){
				dp3[i]=min(dp3[i],dp3[i-4]+(c[i-3]!='R')+(c[i-2]!='R')+(c[i-1]!='L')+(c[i]!='L'));
			}
		}
		ans=min(ans,dp3[n+2]);
		c[n+3]=c[3];
		dp4[3]=0;
		for(int i=4;i<=n+3;i++) dp4[i]=INF;
		for(int i=4;i<=n+3;i++){
			if(i>=5){
				dp4[i]=min(dp4[i],dp4[i-2]+(c[i-1]!='R')+(c[i]!='L'));
			}
			if(i>=6){
				dp4[i]=min(dp4[i],dp4[i-3]+(c[i-2]!='R')+(c[i-1]!='R')+(c[i]!='L'));
			}
			if(i>=6){
				dp4[i]=min(dp4[i],dp4[i-3]+(c[i-2]!='R')+(c[i-1]!='L')+(c[i]!='L'));
			}
			if(i>=7){
				dp4[i]=min(dp4[i],dp4[i-4]+(c[i-3]!='R')+(c[i-2]!='R')+(c[i-1]!='L')+(c[i]!='L'));
			}
		}
		ans=min(ans,dp4[n+3]);
		cout<<ans<<'\n';
	}
	return 0;
}