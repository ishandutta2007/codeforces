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

const int N=1005;
int n;

pair<int,int> a[N];
pair<pair<int,int> ,int> b[N];

vector<int> to[N];
vector<pair<int,int> > ans;

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=mp(read(),i);
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			if(a[j]>a[i])
				to[i].push_back(j);
	for(int i=n;i>=1;--i)
	{
		int m=0;
		for(int j=0;j<to[i].size();++j)
			b[++m]=mp(a[to[i][j]],to[i][j]);
		sort(b+1,b+1+m);
		for(int j=1;j<=m;++j)
		{
			ans.push_back(mp(b[j].se,i));
			swap(a[b[j].se],a[i]);
		}
	}
	write(ans.size());puts("");
	for(int i=0;i<ans.size();++i)
		printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}