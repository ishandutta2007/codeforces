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

#define int unsigned long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define mid ((l+r)>>1)
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
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5;
int n,m,du[N],a[N],vis[N],A,B,C,s1,s2,s3,s4;

struct edge
{
	int u,v;
}ee[N];

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

struct Seg
{
	int v1[N*36],v2[N*36],lc[N*36],rc[N*36],rt[N],cnt;
	void update(int &x,int l,int r,int p)
	{
		if(!x) x=++cnt;
		if(l==r)
		{
			v1[x]=1;
			v2[x]=p-1;
			return;
		}
		if(p<=mid) update(lc[x],l,mid,p);
		else update(rc[x],mid+1,r,p);
		v1[x]=v1[lc[x]]+v1[rc[x]];
		v2[x]=v2[lc[x]]+v2[rc[x]];
	}
	int query1(int x,int l,int r,int L,int R)
	{
		if(!x||L>R) return 0;
		if(L<=l&&r<=R) return v1[x];
		int res=0;
		if(L<=mid) res+=query1(lc[x],l,mid,L,R);
		if(mid+1<=R) res+=query1(rc[x],mid+1,r,L,R);
		return res;
	}
	int query2(int x,int l,int r,int L,int R)
	{
		if(!x||L>R) return 0;
		if(L<=l&&r<=R) return v2[x];
		int res=0;
		if(L<=mid) res+=query2(lc[x],l,mid,L,R);
		if(mid+1<=R) res+=query2(rc[x],mid+1,r,L,R);
		return res;
	}
}sum;

inline int query(int l,int r)
{
	if(l>r) return 0;--l;--r;
	return (l+r)*(r-l+1)/2;
}

inline int query1(int x,int y,int l,int r)
{
	if(l>r) return 0;
	return sum.query1(sum.rt[x],1,n,l,r)+sum.query1(sum.rt[y],1,n,l,r);
}

inline int query2(int x,int y,int l,int r)
{
	if(l>r) return 0;
	return sum.query2(sum.rt[x],1,n,l,r)+sum.query2(sum.rt[y],1,n,l,r);
}

inline bool cmp(int x,int y)
{
	if(du[x]==du[y])
		return x<y;
	return du[x]<du[y];
}

signed main()
{
	n=read();m=read();
	A=read();B=read();C=read();
	for(int i=1;i<=m;++i)
	{
		int u=read()+1,v=read()+1;
		sum.update(sum.rt[u],1,n,v);
		sum.update(sum.rt[v],1,n,u);
		ee[i]=(edge){u,v};du[u]++;du[v]++;
	}
	for(int i=1;i<=n;++i)
	{
		s1+=(n-i)*(n-i-1)/2*(i-1)*A;
		s1+=(i-1)*(n-i)*(i-1)*B;
		s1+=(i-1)*(i-2)/2*(i-1)*C;
	}
	for(int i=1;i<=m;++i)
	{
		int u=ee[i].u,v=ee[i].v;
		if(u>v) swap(u,v);
		s2+=(query(1,u-1)+(u-1)*(n-u-1))*A;
		s2+=(query(u+1,v-1)+(u-1)*(u-1)+(v-1)*(n-v))*B;
		s2+=(query(v+1,n)+(v-1)*(v-2))*C;
	}
	int nm=0;
	for(int i=1;i<=m;++i)
	{
		int u=ee[i].u,v=ee[i].v;
		if(u>v) swap(u,v);
		int pre=s3;
		s3+=(query2(u,v,1,u-1)+(u-1)*(query1(u,v,u+1,v-1)+query1(u,v,v+1,n)))*A;
		s3+=(query2(u,v,u+1,v-1)+(u-1)*query1(u,v,1,u-1)+(v-1)*query1(u,v,v+1,n))*B;
		s3+=(query2(u,v,v+1,n)+(v-1)*(query1(u,v,1,u-1)+query1(u,v,u+1,v-1)))*C;
		if(s3<pre) nm++;
	}
	for(int i=1;i<=n;++i)
		a[i]=i;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;++i)
	{
		int u=ee[i].u,v=ee[i].v;
		if(cmp(u,v)) swap(u,v);
		add(u,v);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=head[i];j;j=e[j].ne)
			vis[e[j].v]=1;
		for(int j=head[i];j;j=e[j].ne)
			for(int k=head[e[j].v];k;k=e[k].ne)
				if(vis[e[k].v])
				{
					int a=i,b=e[j].v,c=e[k].v;
					if(a>b) swap(a,b);
					if(b>c) swap(b,c);
					if(a>b) swap(a,b);
					s4+=A*(a-1)+B*(b-1)+C*(c-1);
				}
		for(int j=head[i];j;j=e[j].ne)
			vis[e[j].v]=0;
	}
	for(int i=1;i<=63;++i)
		nm*=2;
	int ans=s1-s2+nm+s3/2-s4;
	write(ans);
	return 0;
}