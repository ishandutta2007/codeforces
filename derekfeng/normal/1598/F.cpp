#include<bits/stdc++.h>
using namespace std;
int n,N[22],cnt[22];
char s[400004];
int dp[1048600];
int mn[22];
vector<int>f[22];
vector<int>z[800006];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int m;scanf("%s",s+1),m=strlen(s+1);
		int sum=0;
		for(int j=1;j<=m;j++){
			sum+=(s[j]=='('?1:-1);
			z[sum+m].push_back(j);
			mn[i]=min(mn[i],sum);
		}
		f[i].resize(m+10);
		for(int j=0;j<=m;j++){
			f[i][j]=0;
			int nxt=1e9;
			if(j>0&&!z[j-1].empty())nxt=z[j-1][0];
			if(!z[j].empty())for(auto x:z[j]){
				if(x>nxt)break;
				f[i][j]++;
			}
		}
		for(int j=0;j<=m+m;j++)z[j].clear();
		N[i]=m,cnt[i]=sum;
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++)dp[i]=-1e9;
	for(int i=0;i<(1<<n);i++){
		int cur=0;
		for(int j=0;j<n;j++)if((1<<j)&i)cur+=cnt[j];
		for(int j=0;j<n;j++)if(!((1<<j)&i)){
			int MN=mn[j];
			int tmp=dp[i];
			if(N[j]>=cur&&cur>=0)tmp+=f[j][N[j]-cur];
			ans=max(tmp,ans);
			if(cur+MN>=0)dp[i|(1<<j)]=max(dp[i|(1<<j)],tmp);
		}
	}
	printf("%d",ans);
}