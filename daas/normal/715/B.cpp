#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int MAXN=1010;
const int MAXM=1e4+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,L,S,T,chk[MAXM];
struct node
{
	int head[MAXN],tot;
	int to[MAXM*2],nextn[MAXM*2],l[MAXM*2];
	void ADD(int u,int v,int _l)
	{
		to[++tot]=v,nextn[tot]=head[u],l[tot]=_l;
		head[u]=tot;
	}
}Ed;
struct data
{
	ll dis;
	int id;
	data(int _id=0,ll _dis=0) {id=_id,dis=_dis;}
	bool operator <(const data &Z) const {return dis>Z.dis;}
};
priority_queue<data> Q;
int pd[MAXN];
ll dis[MAXN],mem[MAXN],del;
void Dijkstra()
{
	memset(pd,0,sizeof(pd));
	memset(dis,0x3f,sizeof(dis));
	dis[S]=0;
	Q.push(data(S,0));
	while(!Q.empty())
	{
		data u=Q.top();
		Q.pop();
		if(pd[u.id]) continue;
		pd[u.id]=1;
		for(int i=Ed.head[u.id];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i];
			if(dis[v]>u.dis+Ed.l[i])
			{
				dis[v]=u.dis+Ed.l[i];
				Q.push(data(v,dis[v]));
			}
		}
	}
}
void solve()
{
	memset(dis,0x3f,sizeof(dis));
	memset(pd,0,sizeof(pd));
	dis[S]=0;
	Q.push(data(S,0));
	while(!Q.empty())
	{
		data u=Q.top();
		Q.pop();
		if(pd[u.id]) continue;
		pd[u.id]=1;
		for(int i=Ed.head[u.id];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i];
			if(chk[i>>1] && u.dis+Ed.l[i]<mem[v]+del) Ed.l[i]=Ed.l[i^1]=mem[v]+del-u.dis;
			if(dis[v]>u.dis+Ed.l[i])
			{
				dis[v]=u.dis+Ed.l[i];
				Q.push(data(v,dis[v]));
			}
		}
	}
}
int main()
{
	n=read(),m=read(),L=read(),S=read()+1,T=read()+1;
	Ed.tot=1;
	for(int i=1;i<=m;++i)
	{
		int u=read()+1,v=read()+1,l=read();
		if(!l) chk[i]=1,l=1;
		Ed.ADD(u,v,l);
		Ed.ADD(v,u,l);
	}
	Dijkstra();
	if(dis[T]>L) {puts("NO");return 0;}
	del=L-dis[T];
	for(int i=1;i<=n;++i) mem[i]=dis[i];
	solve();
	if(dis[T]!=L) {puts("NO");return 0;}
	puts("YES");
	for(int i=1;i<=m;++i) printf("%d %d %d\n",Ed.to[i<<1|1]-1,Ed.to[i<<1]-1,Ed.l[i<<1]);
	return 0;
}
//ore no turn,draw!