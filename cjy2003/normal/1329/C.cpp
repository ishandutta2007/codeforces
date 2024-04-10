#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,h,g,a[1<<20],dep[1<<20],to[1<<20],st[30],tp,dn[1<<20];
int ans[1<<20],tot;
void dfs(int v)
{
	dn[v]=v;
	if(dep[v]==h)return to[v]=v,void();
	dfs(v*2),dfs(v*2+1);
	to[v]=a[v*2]<a[v*2+1]?to[v*2+1]:to[v*2];
}
int main()
{
	for(int i=1;i<1<<20;++i)dep[i]=dep[i>>1]+1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&h,&g);
		for(int i=1;i<1<<h;++i)scanf("%d",&a[i]);
		dfs(1);
		for(int t=1;t<=(1<<h)-(1<<g);++t)
		{
			int x=dn[1],y;
			ans[++tot]=x;
			y=to[x];
			// printf("%d\n",y);
			tp=0;
			for(int z=y;z;z>>=1)st[++tp]=z;
			for(int i=tp;i>1;--i)if(dep[st[i]]>=dep[x])a[st[i]]=a[st[i-1]];
			a[st[1]]=0;dn[st[1]]=0;
			for(int i=2;i<=tp;++i)
			{
				to[st[i]]=a[st[i]*2]==0&&a[st[i]*2+1]==0?st[i]:a[st[i]*2]<a[st[i]*2+1]?to[st[i]*2+1]:to[st[i]*2];
				dn[st[i]]=a[dn[st[i]*2]]<a[dn[st[i]*2+1]]?dn[st[i]*2+1]:dn[st[i]*2];
				if(dep[to[st[i]]]>g)dn[st[i]]=st[i];
			}
		//	for(int i=0;i<1<<h;++i)printf("%d ",a[i]);printf("\n");
		//	for(int i=1;i<1<<h;++i)printf("%d ",to[i]);printf("\n");
		//	for(int i=1;i<1<<h;++i)printf("%d ",dn[i]);printf("\n");
		}
		long long sum=0;
		for(int i=1;i<1<<g;++i)sum+=a[i];
		printf("%lld\n",sum);
		for(int i=1;i<=tot;++i)printf("%d ",ans[i]);
		printf("\n");tot=0;
		for(int i=1;i<1<<h;++i)a[i]=to[i]=dn[i]=0;
	}
	return 0;
}