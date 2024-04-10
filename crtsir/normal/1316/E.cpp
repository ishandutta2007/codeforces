#include<bits/stdc++.h>
using namespace std;
long long dp[2][128],a[100003],s[100003][7],n,p,k,t[100003],cnt[128];
bool cmp(int x,int y){return a[x]>a[y];}
int cntt(int x){
	int ret=0;
	while(x)x&=(x-1),ret++;
	return ret;
}
int main(){
	cin>>n>>p>>k;
	for(int i=0;i<n;i++)scanf("%lld",a+i),t[i]=i;
	for(int i=0;i<128;i++)cnt[i]=cntt(i);
	for(int i=0;i<n;i++)for(int j=0;j<p;j++)scanf("%lld",&s[i][j]);
	sort(t,t+n,cmp);bool nw=0;
	for(int i=0;i<(1<<p);i++)dp[0][i]=-1e18;
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<p);j++)
			if(i-cnt[j]<k)
				dp[nw^1][j]=dp[nw][j]+a[t[i]];
			else
				dp[nw^1][j]=dp[nw][j];
		for(int j=0;j<(1<<p);j++)
			for(int l=0;l<p;l++)
				if(!(j&(1<<l)))
					dp[nw^1][j+(1<<l)]=max(dp[nw^1][j+(1<<l)],dp[nw][j]+s[t[i]][l]);
		nw^=1;
	}
	cout<<dp[nw][(1<<p)-1];
}