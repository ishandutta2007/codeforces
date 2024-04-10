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

const int N=5e5+5,K=55;
int n,m,k,q,a[N],b[N],ls[N],c[N],fa[K][N<<1],siz[K][N<<1],top;

struct Edge
{
	int u,v;
}e[N];

struct Upd
{
	int x,p;
}st[N<<1];

vector<int> hav[N<<2];

inline int find(int x,int p)
{
	return fa[p][x]==x?x:find(fa[p][x],p);
}

inline void merge(int x,int y,int p)
{
	int f1=find(x,p),f2=find(y,p);
	if(f1==f2) return;
	if(siz[f1]<siz[f2]) swap(f1,f2);
	st[++top]=(Upd){f2,p};
	fa[p][f2]=f1;siz[p][f1]+=siz[p][f2];
}

void add(int x,int l,int r,int L,int R,int v)
{
	if(L>R||R<l||L>r)
		return;
	if(L<=l&&r<=R)
	{
		hav[x].push_back(v);
		return;
	}
	if(L<=mid) add(lc,l,mid,L,R,v);
	if(mid+1<=R) add(rc,mid+1,r,L,R,v);
}

void solve(int x,int l,int r)
{
	int pretop=top;
	for(int i=0;i<hav[x].size();++i)
	{
		int id=a[hav[x][i]];
		int col=b[hav[x][i]];
		if(!col) continue;
		int u=e[id].u,v=e[id].v;
		merge(u,v+n,col);merge(u+n,v,col);
	}
	if(l==r)
	{
		int id=a[l],col=b[l];
		int u=e[id].u,v=e[id].v;
		if(find(u,col)==find(v,col))
			puts("NO"),b[l]=c[id];
		else puts("YES"),c[id]=b[l];
	}
	else solve(lc,l,mid),solve(rc,mid+1,r);
	while(pretop^top)
	{
		int x=st[top].x;
		int p=st[top].p;
		siz[p][fa[p][x]]-=siz[p][x];
		fa[p][x]=x;--top;
	}
}

signed main()
{
	n=read();m=read();
	k=read();q=read();
	for(int i=1;i<=k;++i)
		for(int j=1;j<=(n<<1);++j)
			fa[i][j]=j,siz[i][j]=1;
	for(int i=1;i<=m;++i)
	{
		e[i].u=read();
		e[i].v=read();
		ls[i]=q+1;
	}
	for(int i=1;i<=q;++i)
		a[i]=read(),b[i]=read();
	for(int i=q;i>=1;--i)
	{
		if(i+1<=ls[a[i]]-1)
			add(1,1,q,i+1,ls[a[i]]-1,i);
		ls[a[i]]=i;
	}
	solve(1,1,q);
	return 0;
}