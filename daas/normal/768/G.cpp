#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<set>
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
int n,root,head[100001],tot,maxn[100001],sec[100001],minn[100001],size[100001],son[100001],ans[100001],id[100001],cnt,deg[100001];
multiset<int> Q[100001],anc,oth;
struct sb
{
	int to,nextn;
}a[200001];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void format(int u,int fa)
{
	size[u]=1;
	minn[u]=ans[u]=n;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		format(v,u);
		size[u]+=size[v];
		if(size[v]>size[son[u]])
			son[u]=v;
		minn[u]=min(minn[u],size[v]);
		if(size[v]>size[maxn[u]])
			sec[u]=maxn[u],maxn[u]=v;
		else
			if(size[v]>size[sec[u]])
				sec[u]=v;
	}
	if(u!=root)
	{
		minn[u]=min(minn[u],n-size[u]);
		if(n-size[u]>size[maxn[u]])
			sec[u]=maxn[u],maxn[u]=0;
		else
			if(n-size[u]>size[sec[u]])
				sec[u]=0;
	}
	oth.insert(2*size[u]);
}
void check(multiset<int> &T,int maxx,int minx,int &v,int redu)
{
	multiset<int> :: iterator ID=T.lower_bound(maxx-minx+redu);
	if(ID==T.end())
	{
		--ID;
		v=min(v,maxx-((*ID)-redu)/2);
	}
	else
	{
		v=min(v,minx+((*ID)-redu)/2);
		if(ID!=T.begin())
		{
			--ID;
			v=min(v,maxx-((*ID)-redu)/2);
		}
	}
}
void del(multiset<int> &T,int v){T.erase(T.lower_bound(v));}
int calc(int u,int bj){return bj?size[bj]:n-size[u];}
void dsu(int u,int fa)
{
	del(oth,2*size[u]);
	if(u!=root)
		anc.insert(2*size[fa]);
	if(!son[u])
	{
		ans[u]=n-1;
		id[u]=++cnt;
		Q[cnt].insert(2);
		return;
	}
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa || v==son[u])
			continue;
		dsu(v,u);
		for(multiset<int> :: iterator j=Q[id[v]].begin();j!=Q[id[v]].end();++j)
			oth.insert((*j));
	}
	dsu(son[u],u);
	id[u]=id[son[u]];
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa || v==son[u])
			continue;
		for(multiset<int> :: iterator j=Q[id[v]].begin();j!=Q[id[v]].end();++j)
			del(oth,(*j));
	}
	int MAX=calc(u,maxn[u]),SEC=calc(u,sec[u]);
	if(MAX==SEC)
		ans[u]=MAX;
	else
	{
		if(maxn[u])
			check(Q[id[maxn[u]]],MAX,minn[u],ans[u],0);
		else
		{
			check(anc,MAX,minn[u],ans[u],2*size[u]);
			check(oth,MAX,minn[u],ans[u],0);
		}
		ans[u]=max(ans[u],SEC);
	}
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa || v==son[u])
			continue;
		int NOW=id[v];
		if(Q[NOW].size()>Q[id[u]].size())
			swap(id[u],NOW);
		for(multiset<int> :: iterator j=Q[NOW].begin();j!=Q[NOW].end();++j)
			Q[id[u]].insert((*j));
		Q[NOW].clear();
	}
	if(u!=root)
		del(anc,2*size[fa]);
	Q[id[u]].insert(2*size[u]);
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int u=read(),v=read();
		if(!u || !v)
			root=u+v;
		else
		{
			ADD(u,v);
			ADD(v,u);
            ++deg[u];
            ++deg[v];
		}
	}
	format(root,0);
	dsu(root,0);
    if(deg[root]==1)
        ans[root]=n-1;
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
	return 0;
}