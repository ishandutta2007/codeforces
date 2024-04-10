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

const int N=1e6+5;
int n,m,pri[N],vis[N];

inline void init(int x)
{
	for(int i=2;i<=x;++i)
	{
		if(!vis[i])
			pri[++m]=i;
		for(int j=1;j<=m;++j)
		{
			if(i*pri[j]>x)
				break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)
				break;
		}
	}
}

vector<pair<int,int> > ans;

signed main()
{
	n=read();
	init(3000);
	for(int i=1;i<=n-1;++i)
		ans.push_back(mp(i,i+1));
	ans.push_back(mp(n,1));
	int ne=0;
	for(int i=n;;++i)
		if(!vis[i])
		{
			ne=i;
			break;
		}
	for(int i=1;i<=ne-n;++i)
		ans.push_back(mp(i,i+n/2));
	write(ans.size());
	puts("");
	for(int i=0;i<ans.size();++i)
		printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}