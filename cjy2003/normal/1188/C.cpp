#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
int n,k,m,a[1010],s[100010],ans,dp[2][1010];
int solve(int l)
{
	int t=0;
	memset(dp[t],0,sizeof(dp[t]));
	for(int i=1;i<=n;++i)dp[t][i]=1;
	for(int i=2;i<=k;++i)
	{
		t^=1;
		int last=0,sum=0;
		for(int j=1;j<=n;++j)
		{
			while(last<n&&a[j]-a[last+1]>=l)++last,add(sum,dp[t^1][last]);
			dp[t][j]=sum;
		}
	}
	int res=0;
	for(int i=1;i<=n;++i)add(res,dp[t][i]);
	return res;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	m=a[n]-a[1];
	for(int i=1;i*(k-1)<=m;++i)add(ans,solve(i));
	printf("%d",ans);
	return 0;
}