#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
using namespace std;
const int maxp=1000005,maxe=2000005,inf=(1<<25)-1;
int head[maxp],adj[maxe],f[maxe],next[maxe],tot=1;
int S,T,dn,level[maxp],q[maxp],qh,qt,mf;

inline void addedge(const int &u,const int &v,const int &w)
{tot++;adj[tot]=v;f[tot]=w;next[tot]=head[u];head[u]=tot;
tot++;adj[tot]=u;f[tot]=0;next[tot]=head[v];head[v]=tot;}
bool bfs()
{
	qh=0,q[qt=1]=S;
	memset(level,-1,dn+1<<2),level[S]=0;
	for(int u,v,i;qh<qt;)
	{
		u=q[++qh];
		for(i=head[u];i;i=next[i])
			if(level[v=adj[i]]==-1&&f[i]>0)
			{
				level[v]=level[u]+1;
				if(v==T)return 1;
				q[++qt]=v;
			}
	}
	return 0;
}

int aug(int u,int flow)
{
	if(u==T)return flow;
	int left=flow;
	for(int t,i=head[u];i&&left;i=next[i])
		if(level[adj[i]]==level[u]+1&&f[i]>0)
		{
			t=aug(adj[i],min(f[i],left));
			left-=t;
			f[i]-=t,f[i^1]+=t;
		}
	if(left==flow)level[u]=-1;
	return flow-left;
}

void solve()
{
	mf=0;
	while(bfs())
		mf+=aug(S,inf);
	printf("%d\n",mf);
}
const int maxn=100005;
int n,m;

vector<pair<int,pair<int,int> > > L,R;
int Llc[maxn],Lrc[maxn],Rlc[maxn],Rrc[maxn];
int Lroot,Rroot;

int build(int l,int r,int *lc,int *rc,char tp)
{
	int x=++dn;
	if(l==r)
	{
		if(tp=='S')addedge(l,x,1);
		else addedge(x,n+l,1);
		return x;
	}
	lc[x]=build(l,l+r>>1,lc,rc,tp);
	rc[x]=build(l+r+2>>1,r,lc,rc,tp);
	if(tp=='S')addedge(lc[x],x,inf),addedge(rc[x],x,inf);
	else addedge(x,lc[x],inf),addedge(x,rc[x],inf);
	return x;
}

void init()
{
	scanf("%d%d",&n,&m);
	int x1,x2,y1,y2;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		L.push_back(make_pair(x1-1,make_pair(y1,y2)));
		R.push_back(make_pair(x2,make_pair(y1,y2)));
	}
	dn=n+n;
	S=++dn;
	T=++dn;
	for(int i=1;i<=n;i++)
		addedge(S,i,1),addedge(n+i,T,1);
	Lroot=build(1,n,Llc,Lrc,'S');
	Rroot=build(1,n,Rlc,Rrc,'T');
}

void merge(int x,int l,int r,int *lc,int *rc,int a,int b,int p,char tp)
{
	if(l>=a&&r<=b)
	{
		if(tp=='S')addedge(x,p,inf);
		else addedge(p,x,inf);
		return;
	}
	int mid=l+r>>1;
	if(a<=mid)merge(lc[x],l,mid,lc,rc,a,b,p,tp);
	if(b>mid)merge(rc[x],mid+1,r,lc,rc,a,b,p,tp);
}

void connect(int a,int b,int c,int d)
{
	if(a>b||c>d)return;
	//printf("[%d,%d]*[%d,%d]\n",a,b,c,d);
	int p=++dn,q=++dn;
	merge(Lroot,1,n,Llc,Lrc,a,b,p,'S');
	merge(Rroot,1,n,Rlc,Rrc,c,d,p,'T');
	addedge(p,q,inf);
}

int TM[maxn];

void Ins(pair<int,int> rr,int t)
{
	//printf("Ins: %d [%d,%d]\n",t,rr.first,rr.second);
	int l=rr.first,r=rr.second;
	for(int i=l;i<=r;i++)
		TM[i]=t;
}

void Del(pair<int,int> rr,int t)
{
	//printf("Del: %d [%d,%d]\n",t,rr.first,rr.second);
	int l=rr.first,r=rr.second,a=-1,b=-1,las=-1,aa,bb;
	for(int i=l;i<=r+1;i++)
	{
		if(i<=r)
		{
			aa=TM[i]+1,bb=t;
			TM[i]=-1;
		}
		if(a!=aa||b!=bb||i==r+1)
		{
			if(las!=-1)connect(a,b,las,i-1);
			a=aa,b=bb,las=i;
		}
	}
}


void work()
{
	Ins(make_pair(1,n),0);
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	for(int i=0,j=0;i<L.size()||j<R.size();)
	{
		if(i==L.size())Ins(R[j].second,R[j].first),j++;
		else if(j==R.size())Del(L[i].second,L[i].first),i++;
		else if(L[i].first<R[j].first)Del(L[i].second,L[i].first),i++;
		else Ins(R[j].second,R[j].first),j++;
	}
	Del(make_pair(1,n),n); 
}

int main()
{
	init();
	work();
	solve();
	return 0;
}