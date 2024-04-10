#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=3e5+5;
int n,m,fa[N],siz[N],ans[N],sm,top,now;

struct Node
{
	int x,y,dlt;
}st[N];

int find(int x)
{
	return fa[x]==x?x:find(fa[x]);
}

inline void merge(int x,int y)
{
	int f1=find(x),f2=find(y);
	if(f1==f2) return;
	if(siz[f1]<siz[f2]) swap(f1,f2);
	st[++top]=(Node){f1,f2,0};
	if((siz[f1]&1)&&(siz[f2]&1))
		sm-=2,st[top].dlt=2;
	fa[f2]=f1,siz[f1]+=siz[f2];
}

struct Edge
{
	int u,v,w,id;
	bool operator < (const Edge &x)const
	{
		return w<x.w;
	}
}a[N];

vector<int> hav[N<<2];

void add(int x,int l,int r,int L,int R,int v)
{
	if(L>R||R<l||L>r) return;
	if(L<=l&&r<=R) return hav[x].pb(v),void();
	if(L<=mid) add(lc,l,mid,L,R,v);
	if(mid+1<=R) add(rc,mid+1,r,L,R,v);
}

void solve(int x,int l,int r)
{
	int pre=top;
	for(int i=0;i<hav[x].size();++i)
		merge(a[hav[x][i]].u,a[hav[x][i]].v);
	if(l==r)
	{
		while(sm&&now<m)
		{
			++now;
			if(a[now].id<=l)
			{
				merge(a[now].u,a[now].v);
				add(1,1,m,a[now].id,l-1,now);
			}
		}
		if(!sm) ans[l]=a[now].w;
		else ans[l]=-1;
	}
	else solve(rc,mid+1,r),solve(lc,l,mid);
	while(pre^top)
	{
		int x=st[top].x,y=st[top].y,dlt=st[top].dlt;
		fa[y]=y;siz[x]-=siz[y];sm+=dlt;--top;
	}
}

signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		a[i]=(Edge){u,v,read(),i};
	}
	sort(a+1,a+1+m);sm=n;
	for(int i=1;i<=n;++i)
		fa[i]=i,siz[i]=1;
	solve(1,1,m);
	for(int i=1;i<=m;++i)
		write(ans[i]),puts("");
	return 0;
}