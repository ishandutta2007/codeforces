#include<cstdio>
#include<algorithm>
using namespace std;
struct data
{
	int x,c;
}q[33];
long long ans;
int n,L,tot;
int main()
{
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++)
	{
		int x,pp=1<<(i-1);
		scanf("%d",&x);
		if(tot==0||1ll*pp/q[tot].x*q[tot].c>x)
		{
			q[++tot]={pp,x};
		}
	}
	ans=1ll*((L-1)/q[tot].x+1)*q[tot].c;
	long long tmp=1ll*L/q[tot].x*q[tot].c;
	L%=q[tot].x;
	for(int i=tot-1;i;i--)
	{
		ans=min(ans,1ll*((L-1)/q[i].x+1)*q[i].c+tmp);
		tmp+=1ll*L/q[i].x*q[i].c;
		L%=q[i].x;
	}
	printf("%I64d\n",ans);
	return 0;
}