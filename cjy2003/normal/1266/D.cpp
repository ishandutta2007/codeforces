#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
long long sum[100010];
long long st1[100010][2],st2[100010][2],cnt1,cnt2;
long long ans[100010][3],cnt;
int main()
{
	scanf("%d %d",&n,&m);
	int x,y,w;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		sum[x]+=w,sum[y]-=w;
	}
	for(int i=1;i<=n;++i)
	{
		if(sum[i]>0)st1[++cnt1][0]=i,st1[cnt1][1]=sum[i];
		if(sum[i]<0)st2[++cnt2][0]=i,st2[cnt2][1]=-sum[i];
	}
	while(cnt1&&cnt2)
	{
		long long mi=min(st1[cnt1][1],st2[cnt2][1]);
		ans[++cnt][0]=st1[cnt1][0],ans[cnt][1]=st2[cnt2][0],ans[cnt][2]=mi;
		st1[cnt1][1]-=mi,st2[cnt2][1]-=mi;
		if(!st1[cnt1][1])--cnt1;
		if(!st2[cnt2][1])--cnt2;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)printf("%lld %lld %lld\n",ans[i][0],ans[i][1],ans[i][2]);
	return 0;
}