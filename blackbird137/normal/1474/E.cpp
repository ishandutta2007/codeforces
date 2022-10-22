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
#include<assert.h>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
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

const int N=1e5+5;
int t,n,p[N],q[N],Ans;

vector<pair<int,int> > ans; 

inline void work(int x,int y)
{
	assert(x!=y);
	assert(p[y]==x);
	ans.push_back(mp(x,y));
	swap(p[x],p[y]);
	Ans+=(x-y)*(x-y);
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		if(n==2)
		{
			puts("1\n2 1\n1\n2 1");
			continue;
		}
		if(n==3)
		{
			puts("5\n2 3 1\n2\n1 3\n3 2");
			continue;
		}
		ans.clear();Ans=0;
		int md=n/2;
		p[1]=q[1]=md+1;p[n]=q[n]=md;
		for(int i=2;i<=md;++i) p[i]=q[i]=i-1;
		for(int i=md+1;i<=n-1;++i) p[i]=q[i]=i+1;
		for(int i=md;i>=2;--i) work(i,n);
		for(int i=md+1;i<=n-1;++i) work(i,1);
		work(1,n);
		write(Ans);puts("");
		for(int i=1;i<=n;++i)
			write(q[i]),putchar(' ');
		puts("");
		write(ans.size());puts("");
		for(int i=0;i<ans.size();++i)
			write(ans[i].fi),putchar(' '),write(ans[i].se),puts("");
	}
	return 0;
}