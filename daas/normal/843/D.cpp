#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,q;
struct node
{
	int head[MAXN],tot;
	int to[MAXN],nextn[MAXN],l[MAXN];
	void ADD(int u,int v,int _l)
	{
		to[++tot]=v,nextn[tot]=head[u],l[tot]=_l;
		head[u]=tot;
	}
}Ed;
int pd[MAXN];
ll dis[MAXN];
struct data
{
	int id;
	ll dis;
	data(int _id=0,ll _dis=0) {id=_id,dis=_dis;}
	bool operator <(const data &Z) const {return dis>Z.dis;}
};
#include<queue>
priority_queue<data> Q;
void Dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0; Q.emplace(1,0);
	while(!Q.empty())
	{
		data u=Q.top(); Q.pop();
		if(pd[u.id]) continue;
		pd[u.id]=1;
		for(int i=Ed.head[u.id];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i];
			if(dis[v]>u.dis+Ed.l[i])
			{
				dis[v]=u.dis+Ed.l[i];
				Q.emplace(v,dis[v]);
			}
		}
	}
}
int del[MAXN],vis[MAXN];
vector<int> mem[MAXN];
void resolve()
{
	for(int i=0;i<=n;++i) mem[i].clear(),del[i]=0x3f3f3f3f,vis[i]=0;
	mem[0].emplace_back(1);
	del[1]=0;
	for(int p=0;p<=n;++p)
	{
		for(int q=0;q<(int)mem[p].size();++q)
		{
			int u=mem[p][q];
			if(vis[u]) continue;
			vis[u]=1;
			for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
			{
				int v=Ed.to[i];
				if(del[v]>dis[u]+del[u]+Ed.l[i]-dis[v])
				{
					del[v]=dis[u]+del[u]+Ed.l[i]-dis[v];
					if(del[v]>n) continue;
					mem[del[v]].emplace_back(v);
				}
			}
		}
	}
	for(int i=1;i<=n;++i) if(del[i]!=del[0]) dis[i]+=del[i];
}
int main()
{
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),l=read();
		Ed.ADD(u,v,l);
	}
	Dijkstra();
	while(q--)
	{
		int type=read();
		if(type==1)
		{
			int x=read();
			printf("%lld\n",dis[x]==dis[0]?-1:dis[x]);
		}
		else
		{
			int C=read();
			for(int i=1;i<=C;++i) ++Ed.l[read()];
			resolve();
		}
	}
	return 0;
}
//tetu no isi to hagane no tuyosa