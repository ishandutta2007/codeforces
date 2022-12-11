#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int nxt,to;
}bi[200020];
int t,T,n,m,l[100010],r[100010],head[100010],num,ans[100010];
inline void add(int from,int to)
{
	bi[++num]=bian{head[from],to};
	head[from]=num;
}
int l1,r1,l2,r2,c[100010],st[100010],tp;
void dfs(int v,int C)
{
	c[v]=C;st[++tp]=v;
	if(C==1)l1=max(l1,l[v]),r1=min(r1,r[v]);
	else l2=max(l2,l[v]),r2=min(r2,r[v]);
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(!c[u])dfs(u,3-C);
		else if(c[v]==c[u])
		{
			printf("IMPOSSIBLE");
			exit(0);
		}
	}
}
int main()
{
	scanf("%d %d %d %d",&t,&T,&n,&m);
	int n1=0,n2=1000000000;
	for(int i=1;i<=n;++i)scanf("%d %d",&l[i],&r[i]),n1=max(n1,l[i]),n2=min(n2,r[i]);
	if(n1+n2<t)n1+=t-n1-n2;
	if(n1+n2>T)n2-=n1+n2-T;
	if(n2<0)return printf("IMPOSSIBLE"),0;
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;++i)
		if(!c[i])
		{
			l1=0,r1=1000000000,l2=0,r2=1000000000;
			dfs(i,1);
			if(l1<=n1&&n1<=r1&&l2<=n2&&n2<=r2)while(tp)ans[st[tp]]=c[st[tp]],--tp;
			else if(l1<=n2&&n2<=r1&&l2<=n1&&n1<=r2)while(tp)ans[st[tp]]=3-c[st[tp]],--tp;
			else return printf("IMPOSSIBLE"),0;
		}
	printf("POSSIBLE\n");
	printf("%d %d\n",n1,n2);
	for(int i=1;i<=n;++i)putchar(ans[i]+48);
	return 0;
}