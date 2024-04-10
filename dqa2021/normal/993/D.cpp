#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll INF=0x7f7f7f7f7f7f7f7fLL;
int n;
struct Id{
	ll a,c;
	int b;
}id[60];
bool operator<(const Id x,const Id y)
{return x.a>y.a;}
ll dp[60][60][60];
bool check(ll thrshld)
{
	int jj,kk;
	memset(dp,0x7f,sizeof dp);dp[0][0][0]=0;
	for (int i=1;i<=n;i++) id[i].c=id[i].a-thrshld*id[i].b;
	for (int i=0;i<n;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;k<=n;k++)
			{
				if (dp[i][j][k]==INF) continue;
				if (id[i].a==id[i+1].a) jj=j,kk=k;
				else jj=j+k,kk=0;
				if (jj>0) dp[i+1][jj-1][kk]=min(dp[i+1][jj-1][kk],dp[i][j][k]);
				dp[i+1][jj][kk+1]=min(dp[i+1][jj][kk+1],dp[i][j][k]+id[i+1].c);
			}
	ll tmp=INF;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			tmp=min(tmp,dp[n][i][j]);
	return tmp<=0;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&id[i].a),id[i].a*=1000;
	for (int i=1;i<=n;i++) scanf("%d",&id[i].b);
	sort(id+1,id+n+1);
	ll l=1,r=100000000000LL,mid;
	while (l<r)
	{
		mid=l+r>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%I64d\n",l);
	return 0;
}