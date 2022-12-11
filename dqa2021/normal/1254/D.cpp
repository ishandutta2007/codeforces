#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;
const int Mod=998244353;
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}

int n,m; int w[150010];
struct Edge{
	int to,nxt;
}edge[300010];
int cnt=1,last[150010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int fat[150010],son[150010],siz[150010],dep[150010];
int top[150010];
void dfs1(int cur,int fat,int dep)
{
	::fat[cur]=fat; ::dep[cur]=dep; siz[cur]=1;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (v=edge[i].to,v^fat)
		{
			dfs1(v,cur,dep+1);
			siz[cur]+=siz[v];
			if (!son[cur]||siz[son[cur]]<siz[v]) son[cur]=v;
		}
}
int id[150010];
void dfs2(int cur,int top)
{
	::top[cur]=top; id[cur]=++*id;
	if (siz[cur]==1) return;
	dfs2(son[cur],top);
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (v=edge[i].to,(v^fat[cur])&&(v^son[cur]))
			dfs2(v,v);
}
int tri[150010];
void add(int x,int val)
{
	for (;x<=n;x+=x&-x) tri[x]=(tri[x]+val)%Mod;
}
int ask(int x)
{
	int res=0;
	for (;x;x-=x&-x) res=(res+tri[x])%Mod;
	return res;
}
int main()
{
	n=read(),m=read(); int invn=qpow(n,Mod-2);
	for (int i=1;i<n;i++) addedge(read(),read());
	dfs1(1,0,1); dfs2(1,1);
	int opt,x,y,z;
	while (m--)
	{
		opt=read(),x=read();
		if (opt==1)
		{
			y=read(); w[x]=(w[x]+y)%Mod;
			z=1LL*siz[x]*y%Mod;
			add(1,z); add(id[x],-z); add(id[x]+siz[x],z);
			if (!son[x]) continue;
			z=1LL*(n-siz[son[x]])*y%Mod;
			add(id[son[x]],z); add(id[son[x]]+siz[son[x]],-z);
			continue;
		}
		int res=ask(id[x]);
		res=(res+1LL*w[x]*n)%Mod;
		for (int i=top[x];fat[i];i=top[fat[i]]) res=(res+1LL*(n-siz[i])*w[fat[i]])%Mod;
		res=1LL*res*invn%Mod;
		printf("%d\n",(res+Mod)%Mod);
	}
	return 0;
}