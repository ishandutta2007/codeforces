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
int t,n,d[N],d2[N],mx[N],ans[N],sm[N],fl,st[N][23],pre[N],tg[N],suc[N];

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

vector<int> pah;

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u,int fa)
{
	mx[u]=d[u];
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		d[v]=d[u]+1;dfs(v,u);
		mx[u]=max(mx[u],mx[v]);
	}
}

void dfs2(int u,int fa)
{
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
		sm[u]+=sm[v];
	}
}

void dfs3(int u,int fa,int ed)
{
	pah.push_back(u);
	if(u==ed) return fl=1,void();
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs3(v,u,ed);
		if(fl) return;
	}
	pah.pop_back();
}

int dfs4(int u,int fa)
{
	int res=0;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa||tg[v])
			continue;
		res=max(res,dfs4(v,u)+1);
	}
	return res;
}

inline int Query(int l,int r)
{
	int k=log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}

inline int query(int x,int y)
{
	int res=0,ps=(x+1)/2+y/2;
	if(ps>=x) return INF;
	res=max(res,pre[ps]);
	res=max(res,Query(ps+1,x)+x+y);
	res=max(res,suc[x]-x+y);
	return res;
}

signed main()
{
	//freopen("yangli.in","r",stdin);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n-1;++i)
		{
			int u=read(),v=read();
			add(u,v);add(v,u);
		}
		dfs(1,0);
		for(int i=1;i<=n;++i)
			if(d[i]==mx[1])
				sm[i]=1;
		int MX=mx[1];
		dfs2(1,0);
		int mx=-1,ps=-1;
		for(int i=1;i<=n;++i)
			if(sm[i]==sm[1]&&d[i]>mx)
				mx=d[i],ps=i;
		pah.clear();fl=0;
		dfs3(1,0,ps);
		int ll=pah.size();suc[ll+1]=0;
		for(int i=1;i<=ll;++i)
			tg[pah[i-1]]=1;
		for(int i=1;i<=ll;++i)
		{
			d2[i]=dfs4(pah[i-1],0);
			st[i][0]=d2[i]-i;
			pre[i]=max(pre[i-1],d2[i]+i-1);
		}
		for(int i=ll;i>=1;--i)
			suc[i]=max(suc[i+1],d2[i]+i);
		for(int j=1;j<=19;++j)
			for(int i=1;i+(1<<j)-1<=n;++i)
				st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		for(int i=1,j=2;i<=n;++i)
		{
			int now=query(j,i);
			query(5,3);
			while(j+1<=ll)
			{
				int tmp=query(j+1,i);
				if(tmp>=now) break;
				now=tmp;++j;
			}
			write(min(now,MX));putchar(' ');
		}
		puts("");tot=0;
		for(int i=1;i<=n;++i)
			head[i]=0,d[i]=0,sm[i]=0,tg[i]=0;
	}
	return 0;
}