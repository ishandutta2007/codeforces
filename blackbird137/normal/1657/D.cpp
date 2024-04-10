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

#define int long long
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

const int N=2e6+5;
int n,m,q,upd[N],ans[N],suc[N];

struct Qus
{
	int x,id;
	bool operator < (const Qus &p)const
	{
		return x<p.x;
	}
}b[N];

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		int c=read();
		int x=read()*read();
		upd[c]=max(upd[c],x);
	}
	q=read();
	for(int i=1;i<=q;++i)
		b[i]=(Qus){read()*read(),i};
	sort(b+1,b+1+q);
	for(int i=0;i<=q+1;++i)
		suc[i]=4e18;
	for(int i=1;i<=m;++i)
		if(upd[i])
		{
			for(int j=i;j<=m;j+=i)
			{
				int tmp=j/i*upd[i];
				int ps=lower_bound(b+1,b+1+q,(Qus){tmp,0})-b-1;
				suc[ps]=min(suc[ps],j);
			}
		}
	for(int i=q;i>=1;--i)
	{
		suc[i]=min(suc[i+1],suc[i]);
		ans[b[i].id]=suc[i];
	}
	for(int i=1;i<=q;++i)
		if(ans[i]==4e18)
			write(-1),putchar(' ');
		else write(ans[i]),putchar(' ');
	return 0;
}