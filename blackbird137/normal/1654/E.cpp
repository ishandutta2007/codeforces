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

const int N=1e5+5,B=300;
int n,a[N],b[N],fa[N],siz[N],mx,ans;

inline int query1(int x)
{
	for(int i=1;i<=n;++i)
		b[i]=a[i]-i*x;
	sort(b+1,b+1+n);
	int res=0,ls=-1e18,now=0;
	for(int i=1;i<=n;++i)
	{
		if(b[i]!=ls)
			ls=b[i],now=1;
		else now++;
		res=max(res,now);
	}
	return res;
}

vector<pair<int,int> > upd[N];

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	fa[x]=y;siz[y]+=siz[x];
	ans=max(ans,siz[y]);
}

void work()
{
	for(int i=0;i<=B;++i)
		ans=max(ans,query1(i));
	for(int i=1;i<=100000;++i)
		upd[i].clear();
	int lim=100000/B+10;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n&&j<=i+lim-1;++j)
			if(a[j]>=a[i]&&(a[j]-a[i])%(j-i)==0)
				upd[(a[j]-a[i])/(j-i)].push_back(mp(i,j));
	for(int i=1;i<=n;++i)
		fa[i]=i,siz[i]=1;
	for(int i=B+1;i<=100000;++i)
	{
		for(int j=0;j<upd[i].size();++j)
			merge(upd[i][j].fi,upd[i][j].se);
		for(int j=0;j<upd[i].size();++j)
		{
			siz[upd[i][j].fi]=1;
			siz[upd[i][j].se]=1;
			fa[upd[i][j].fi]=upd[i][j].fi;
			fa[upd[i][j].se]=upd[i][j].se;
		}
	}
}

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	work();
	reverse(a+1,a+1+n);
	work();
	write(n-ans);
	return 0;
}