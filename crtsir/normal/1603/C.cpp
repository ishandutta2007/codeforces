#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int T,n,a[100003];
int dp[2][1003],f[2][1003];
vector<int>v[2],g[2];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i); 
		v[0].clear();
		g[0].clear();
		int ans=0;
		for(int i=1;i<=n;i++){
			v[i&1].clear();
			g[i&1].clear();
			for(int j=1;j<=min(int(sqrt(a[i]))+1,a[i]);j++)
				v[i&1].push_back(j),
				g[i&1].push_back((a[i]-1)/j);
			for(int j=sqrt(a[i])+1;j>0;j--)
				if((a[i]-1)/j+1>v[i&1].back())
					v[i&1].push_back((a[i]-1)/j+1),
					g[i&1].push_back(j-1);
			int nw=0,F=0,DP=0;
			for(int j=0,k=0;j<v[i&1].size();j++){
				nw=v[i&1][j]-bool(a[i]%v[i&1][j]);
				F=0;DP=0;
				while(k<v[i-1&1].size()&&nw>=v[i-1&1][k])k++;k--;
				F+=f[i-1&1][k];
				if(F>=mod)F-=mod;
				DP+=dp[i-1&1][k];
				if(DP>=mod)DP-=mod;
				DP+=1ll*f[i-1&1][k]*g[i&1][j]%mod;
				if(DP>=mod)DP-=mod;
				k++;
				f[i&1][j]=F+1;
				dp[i&1][j]=DP+g[i&1][j];
			}
			if(f[i&1][v[i&1].size()-1]>=mod)
				f[i&1][v[i&1].size()-1]-=mod;
			ans=(ans+dp[i&1][v[i&1].size()-1]);
			if(ans>=mod)ans-=mod;
		}
		printf("%d\n",ans);
	}
}