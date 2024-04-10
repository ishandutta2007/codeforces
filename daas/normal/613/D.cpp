#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<map>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
map<pair<int,int>,int> Q;
int n,m,head[100001],tot,headn[100001],totn,z[100001],top,tim[100001],T,jump[100001][18],deep[100001],pd[100001],cnt[100001],dp[100001],NOW,flag,p[100001];
struct sb
{
	int to,nextn;
}a[200001],an[100001];
inline void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
inline int cmp(int x,int y)
{
	return tim[x]<tim[y];
}
inline void format(int u,int fa)
{
	tim[u]=++T;
	deep[u]=deep[fa]+1;
	jump[u][0]=fa;
	int LOG=log2(deep[u]);
	for(register int i=1;i<=LOG;++i)
		jump[u][i]=jump[jump[u][i-1]][i-1];
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		format(v,u);
	}
}
inline int LCA(int x,int y)
{
	if(deep[x]<deep[y])
		swap(x,y);
	int C=deep[x]-deep[y];
	int LOG=log2(C);
	for(register int i=0;i<=LOG;++i)
		if(C&(1<<i))
			x=jump[x][i];
	if(x==y)
		return x;
	LOG=log2(deep[x]);
	for(register int i=LOG;i>=0;--i)
		if(jump[x][i]!=jump[y][i])
		{
			x=jump[x][i];
			y=jump[y][i];
		}
	return jump[x][0];
}
inline void ADDn(int from,int to)
{
	if(pd[from]==NOW && pd[to]==NOW && Q[make_pair(from,to)])
	{
		flag=1;
		return;
	}
	an[++totn].to=to,an[totn].nextn=headn[from];
	headn[from]=totn;
}
inline void fun(int u)
{
	dp[u]=0,cnt[u]=0;
	for(register int i=headn[u];i!=0;i=an[i].nextn)
	{
		int v=an[i].to;
		fun(v);
		dp[u]+=dp[v];
		cnt[u]+=cnt[v];
	}
	if(pd[u]==NOW)
		dp[u]+=cnt[u],cnt[u]=1;
	else
		if(cnt[u]>=2)
			++dp[u],cnt[u]=0;
}
int main()
{
	n=read();
	for(register int i=1;i<n;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
		Q[make_pair(u,v)]=Q[make_pair(v,u)]=1;
	}
	format(1,0);
	//for(register int i=1;i<=n;++i)
	//	printf("%d\n",tim[i]);
	m=read();
	while(m--)
	{
		++NOW;
		int K=read();
		for(register int i=1;i<=K;++i)
			p[i]=read(),pd[p[i]]=NOW;
		sort(p+1,p+K+1,cmp);
		headn[1]=0;
		z[top=1]=1;
		flag=0;
		for(register int i=1;i<=K;++i)
		{
			if(p[i]==1)
				continue;
			//	cout<<"cnm "<<p[i]<<endl;
			//	for(register int j=1;j<=top;++j)
			//		cout<<z[j]<<" ";
			//	cout<<endl;
			int lca=LCA(z[top],p[i]);
			if(lca!=z[top])
			{
				while(tim[z[top-1]]>tim[lca])
				{
					ADDn(z[top-1],z[top]);
					--top;
				}
				if(tim[z[top-1]]<tim[lca])
				{
					headn[lca]=0;
					ADDn(lca,z[top]);
					z[top]=lca;
				}
				else
				{
					ADDn(lca,z[top]);
					--top;
				}
			}
			headn[p[i]]=0;
			z[++top]=p[i];
		}
		for(register int i=1;i<top;++i)
			ADDn(z[i],z[i+1]);
		if(flag)
		{
			puts("-1");
			continue;
		}
		fun(1);
		printf("%d\n",dp[1]);
	}
	return 0;
}