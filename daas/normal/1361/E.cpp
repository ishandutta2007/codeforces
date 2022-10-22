#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<random>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
const int MAXM=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int Test,n,m,flag,flag2;
mt19937 gen(time(NULL));
struct node
{
	int head[MAXN],tot;
	int to[MAXM*2],nextn[MAXM*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
	void init()
	{
		for(int i=1;i<=n;++i) head[i]=0;
		tot=0;
	}
}Ed;
int vis[MAXN],pd[MAXN],F,mem[MAXM];
void dfs(int u,int fa)
{
	vis[u]=pd[u]=1;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(!vis[v]) dfs(v,u),mem[i]=0;
		else if(!pd[v]) F=1;
		else mem[i]=1;
	}
	pd[u]=0;
}
#include<set>
multiset<int> T[MAXN];
int id[MAXN],deep[MAXN],ans[MAXN];
void merge(int u,int v)
{
	if(T[id[u]].size()>T[id[v]].size())
	{
		for(auto it=T[id[v]].begin();it!=T[id[v]].end();++it) T[id[u]].insert(*it);
	}
	else
	{
		for(auto it=T[id[u]].begin();it!=T[id[u]].end();++it) T[id[v]].insert(*it);
		id[u]=id[v];
	}
}
int z[MAXN],top;
void fun(int u,int fa)
{
	z[++top]=u;
	deep[u]=deep[fa]+1;
	id[u]=u;
	T[u].clear();
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(mem[i]) T[u].insert(deep[v]);
		else fun(v,u);
	}
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(!mem[i]) merge(u,v);
	}
	if(!T[id[u]].size()) ans[u]=0;
	else
	{
		auto it=T[id[u]].begin();
		if(*it>=deep[u]) ans[u]=0;
		else
		{
			auto it2=it; ++it2;
			if(it2==T[id[u]].end()) ans[u]=z[*it];
			else if(*it2>=deep[u]) ans[u]=z[*it];
			else ans[u]=0;
		}
	}
	--top;
}
void push(int u,int fa)
{
	if(ans[u] && ans[ans[u]]) ans[u]=1;
	else ans[u]=0;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		if(!mem[i]) push(v,u);
	}
}
void solve()
{
	uniform_int_distribution<int> dcd(1,n);
	int rt=dcd(gen);
	for(int i=1;i<=n;++i) vis[i]=0;
	F=0;
	dfs(rt,0);
	if(F) return;
	flag=1;
	fun(rt,0);
	ans[rt]=rt;
	push(rt,0);
	int num=0;
	for(int i=1;i<=n;++i) if(ans[i]) ++num;
	if(num*5<n) {flag2=0;return;}
	flag2=1;
	for(int i=1;i<=n;++i) if(ans[i]) printf("%d ",i);
	putchar('\n');
}
int main()
{
	Test=read();
	while(Test--)
	{
		n=read(),m=read();
		Ed.init();
		for(int i=1;i<=m;++i)
		{
			int u=read(),v=read();
			Ed.ADD(u,v);
		}
		flag=flag2=0;
		int test_case=100;
		while(test_case-- && !flag) solve();
		if(!flag2) puts("-1");
	}
	return 0;
}
//ore no turn,draw!