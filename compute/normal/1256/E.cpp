#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int maxn=3e5+7;
int ans[maxn];
pi a[maxn];
int n;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dp[maxn][3];
int pre[maxn][3];
int ti=1;
void solve(int x,int j){
	ans[a[x].second]=ti;
	if(x==1) return;
	if(j==0) ti++;
	solve(x-1,pre[x][j]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+1+n);
	memset(dp,0x3f,sizeof(dp));
	dp[0][2]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++){
			if(!j&&dp[i-1][2]!=INF){
				dp[i][j]=dp[i-1][2];
				pre[i][j]=2;
			}
			else if(j){
				if(i>1&&j==2&&dp[i-1][j]!=INF)
				{
					dp[i][j]=dp[i-1][j]+a[i].first-a[i-1].first;
					pre[i][j]=2;
				}
				if(dp[i][j]>dp[i-1][j-1]+a[i].first-a[i-1].first)
				{
					pre[i][j]=j-1;
					dp[i][j]=dp[i-1][j-1]+a[i].first-a[i-1].first;
				}
			}
		}
	}
	solve(n,2);
	printf("%lld %d\n",dp[n][2],ti);
	for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');

}