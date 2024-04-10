#include <bits/stdc++.h>
#define maxn 1009
using namespace std;
int n;
int c[maxn],r[maxn],b[maxn];
long long dp[1<<16][300];
int cntr[1<<16],cntb[1<<16];
const long long INF=1e12;
int sum[1<<16];
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		char s[10];
		scanf("%s",s);
		if(s[0]=='R')
			c[i]=1;
		else
			c[i]=2;
		scanf("%d%d",&r[i],&b[i]);
	}
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				sum[i]+=r[j];
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				if(c[j]==1)
					cntr[i]++;
				else
					cntb[i]++;
			}
		}
	}
	for(int st=0;st<1<<n;st++)
		for(int i=0;i<=n*n;i++)
			dp[st][i]=INF;
	
	dp[0][0]=0;

	for(int st=0;st<(1<<n);st++){
		for(int j=0;j<=n*n;j++){
			if(dp[st][j]==INF)
				continue;
			for(int k=0;k<n;k++){
				if(st&(1<<k))
					continue;
				int costred=max(0,r[k]-cntr[st]);
				int costblue=max(0,b[k]-cntb[st]);
				dp[st^(1<<k)][j+r[k]-costred]=min(dp[st^(1<<k)][j+r[k]-costred],dp[st][j]+costblue);
			}
		}
	}
	long long ans=INF;
	int mask=(1<<n)-1;
	long long sum=0;
	for(int i=0;i<n;i++)
		sum+=r[i];
	for(int i=0;i<=n*n;i++){
		long long costr=sum-i;
		long long costb=dp[mask][i];
		ans=min(ans,max(costb,costr));
	}
	cout<<ans+n<<endl;
	//system("pause");
	return 0;
}