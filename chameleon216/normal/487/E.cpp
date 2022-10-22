#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <functional>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
#define Ft(i,x) for(int i=I[x];i;i=G[i].nx)
using namespace std;
typedef long long ll;
const int MX=220000;
const int Inf=0x3f3f3f3f;
int N,M,Q,X[MX];

struct Edge{int y,nx;}E[MX<<1],G[MX<<1];
int H[MX],I[MX],ec,gc;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}
void Bee(int x,int y){G[++gc].y=y,G[gc].nx=I[x],I[x]=gc;}


#define y E[i].y
int B[MX],Dfn[MX],Low[MX],dc;
int stk[MX],tp,tc;
void Tarjan(int x)
{
	B[x]=1,Dfn[x]=Low[x]=++dc,stk[++tp]=x;
	Fe(i,x)
	{
		if(B[y]==0)
		{
			Tarjan(y),Low[x]=min(Low[x],Low[y]);
			if(Low[y]>=Dfn[x])
			{
				int z=0;++tc;
				while(z!=y)
					z=stk[tp--],Bee(z,tc),Bee(tc,z);
				Bee(x,tc),Bee(tc,x);
			}
		}
		else Low[x]=min(Low[x],Dfn[y]);
	}
}
#undef y


#define y G[i].y
int D[MX],F[MX],sz[MX],son[MX];
int U[MX],id[MX],Y[MX],ic;
void dfs1(int x,int f,int d)
{
	D[x]=d,F[x]=f,sz[x]=1;
	int mx=0;
	Ft(i,x)if(y!=f)
	{
		dfs1(y,x,d+1),sz[x]+=sz[y];
		if(sz[y]>mx)mx=sz[y],son[x]=y;
	}
}
void dfs2(int x,int u)
{
	U[x]=u,id[x]=++ic;
	if(son[x])dfs2(son[x],u);
	Ft(i,x)if(y!=F[x]&&y!=son[x])dfs2(y,y); 
}
#undef y



struct Seg{int v,L,R;}T[MX<<2];
#define li (i<<1)
#define ri (i<<1|1)
void pushup(int i){T[i].v=min(T[li].v,T[ri].v);}
void Build(int i,int l,int r)
{
	if(l==r){T[i].v=Y[l];return;}
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
	pushup(i);
}
void Modify(int i,int l,int r,int a,int x)
{
	if(l==r){T[i].v=x;return;}
	int m=(l+r)>>1;
	if(a<=m)Modify(li,l,m,a,x);
	else Modify(ri,m+1,r,a,x);
	pushup(i);
}
int Ask(int i,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)return T[i].v;
	int m=(l+r)>>1;
	if(b<=m)return Ask(li,l,m,a,b);
	if(a>m)return Ask(ri,m+1,r,a,b);
	return min(Ask(li,l,m,a,b),Ask(ri,m+1,r,a,b));
}

struct Heap
{
	priority_queue<int,vector<int>,greater<int> > h,d;
	void push(int x){h.push(x);}
	void del(int x){d.push(x);}
	int top()
	{
		while(!d.empty()&&h.top()==d.top())
			h.pop(),d.pop();
		return h.top();
	}
}hp[MX];


void NodeModify(int x,int a)
{
	int f=F[x];
	if(f)
	{
		hp[f].del(X[x]);
		hp[f].push(a);
		Modify(1,1,tc,id[f],hp[f].top());
	}
	X[x]=a;
}

int PathAsk(int x,int y)
{
	int ans=Inf;
	while(U[x]!=U[y])
	{
		if(D[U[x]]<D[U[y]])swap(x,y);
		ans=min(ans,Ask(1,1,tc,id[U[x]],id[x]));
		x=F[U[x]];
	}
	if(D[x]>D[y])swap(x,y);
	ans=min(ans,Ask(1,1,tc,id[x],id[y]));
	if(x<=N)ans=min(ans,X[x]);
	else ans=min(ans,X[F[x]]);
	return ans;
}


int main()
{
	scanf("%d%d%d",&N,&M,&Q);
	Fr(i,1,N)scanf("%d",X+i);
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y),Add(y,x);
	}
	tc=N;
	Fr(i,1,N)if(B[i]==0)Tarjan(i),tp=0;
	dfs1(1,0,1);
	dfs2(1,1);
	Fr(x,1,N)if(F[x])hp[F[x]].push(X[x]);
	Fr(x,1,N)Y[id[x]]=Inf;
	Fr(x,N+1,tc)Y[id[x]]=hp[x].top();
	Build(1,1,tc);
	Fr(i,1,Q)
	{
		char o;
		int x,y;
		scanf(" %c%d%d",&o,&x,&y);
		if(o=='A')printf("%d\n",PathAsk(x,y));
		else NodeModify(x,y);
	}
	return 0;
}