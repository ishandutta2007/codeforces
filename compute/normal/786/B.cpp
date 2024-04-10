#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
template <typename T>
bool scan_d(T &num)
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
template <typename T>
void o(T p) {
    static int stk[70], tp;
    if (p == 0) { putchar('0'); return; }
    if (p < 0) { p = -p; putchar('-'); }
    while (p) stk[++tp] = p % 10, p /= 10;
    while (tp) putchar(stk[tp--] + '0');
}
const int maxn=1e5+7;
const int maxm=3e6+7;
struct Edge{
	int to,w,nxt;
}edge[maxm*2];
int head[maxm],cnt;
void addedge(int u,int v,int w)
{
	edge[cnt]={v,w,head[u]};
	head[u]=cnt++;
}
int id[maxn*4][2];
int n;
int tot;
#define Lson L,mid,o*2
#define Rson mid+1,R,o*2+1
void build(int d,int l=1,int r=n,int o=1)
{
	id[o][d]=tot++;
	if(l==r)
	{
		if(d)
			addedge(l,id[o][d],0);
		else addedge(id[o][d],l,0);
		return;
	}
	int mid=l+r>>1;
	build(d,l,mid,o*2);
	if(!d)
		addedge(id[o][d],id[o*2][d],0);
	else addedge(id[o*2][d],id[o][d],0);
	build(d,mid+1,r,o*2+1);
	if(!d)
		addedge(id[o][d],id[o*2+1][d],0);
	else addedge(id[o*2+1][d],id[o][d],0);
}
void update(int d,int p,int l,int r,int w,int L=1,int R=n,int o=1)
{
	dbg(o,L,R);
	dbg(w);
	if(l<=L&&r>=R)
	{
		if(!d)
			addedge(p,id[o][d],w);
		else addedge(id[o][d],p,w);
		return;
	}
	int mid=L+R>>1;
	if(l<=mid) update(d,p,l,r,w,Lson);
	if(r>mid) update(d,p,l,r,w,Rson);
}
ll dis[maxm];
struct Heap_node{
	int num;
	ll dis;
	bool operator<(const Heap_node& a)const{
		return dis>a.dis;
	}
};
void init()
{
	cnt=0;memset(head,-1,sizeof(head));
}
int s;
bool vis[maxm];
void dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<Heap_node> q;
	q.push(Heap_node {s,0});
	while(!q.empty())
	{
		auto u=q.top();q.pop();
		dbg(u.num,u.dis);
		if(vis[u.num]) continue;
		vis[u.num]=1;
		for(int i=head[u.num];i!=-1;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(dis[v]>dis[u.num]+edge[i].w)
			{
				dis[v]=dis[u.num]+edge[i].w;
				q.push(Heap_node {v,dis[v]});
			}
		}
	}
}
const ll INF=0x3f3f3f3f3f3f3f3f;
int main()
{
	init();
	int q;
	scanf("%d%d%d",&n,&q,&s);
	tot=n+1;
	build(0);build(1);
	while(q--)
	{
		int t;
		scan_d(t);
		if(t==1)
		{
			int u,v,w;
			scan_d(u);
			scan_d(v);
			scan_d(w);
			addedge(u,v,w);
		}
		else{
			int u,l,r,w;
			scan_d(u);scan_d(l);scan_d(r);scan_d(w);
			update(t==3,u,l,r,w);
		}
	}
	dijkstra();
	for(int i=1;i<=n;i++)
	{
		o(dis[i]==INF?-1:dis[i]);
		putchar(' ');
	}
	puts("");
}