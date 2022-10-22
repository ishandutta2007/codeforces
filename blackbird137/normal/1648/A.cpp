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

const int N=1e5+5,M=1e5;
int n,m,k,ans;

struct Node
{
	int x,y;
}a[N];

inline bool cmp1(Node a,Node b)
{
	return a.x<b.x;
}

inline bool cmp2(Node a,Node b)
{
	return a.y<b.y;
}

vector<Node> hav[N];

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			hav[read()].push_back((Node){i,j});
	for(int i=1;i<=M;++i)
	{
		int k=hav[i].size();
		if(k==0) continue;
		for(int j=0;j<k;++j)
			a[j+1]=hav[i][j];
		sort(a+1,a+1+k,cmp1);
		int now=0;
		for(int j=1;j<=k;++j)
		{
			ans+=a[j].x*(j-1)-now;
			now+=a[j].x;
		}
		now=0;
		sort(a+1,a+1+k,cmp2);
		for(int j=1;j<=k;++j)
		{
			ans+=a[j].y*(j-1)-now;
			now+=a[j].y;
		}
	}
	write(ans);
	return 0;
}