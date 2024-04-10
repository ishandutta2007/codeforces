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
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

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
int n,n1,n2,ans,a[3][N],b[3][N];

signed main()
{
	n=read();
	for(int i=1;i<=2;++i)
		for(int j=1;j<=n;++j)
			a[i][j]=read();
	for(int i=1;i<=2;++i)
		for(int j=1;j<=n;++j)
			b[i][j]=read();
	for(int i=1;i<=n;++i)
	{
		
		if(a[1][i]&&b[1][i]) a[1][i]=b[1][i]=0;
		if(a[2][i]&&b[2][i]) a[2][i]=b[2][i]=0;
		
		if(n1<0&&a[1][i]) n1++,a[1][i]=0;
		if(n1>0&&b[1][i]) n1--,b[1][i]=0;
		if(n2<0&&a[2][i]) n2++,a[2][i]=0;
		if(n2>0&&b[2][i]) n2--,b[2][i]=0;
		
		if(n1<0&&a[2][i]) ans++,n1++,a[2][i]=0;
		if(n1>0&&b[2][i]) ans++,n1--,b[2][i]=0;
		if(n2<0&&a[1][i]) ans++,n2++,a[1][i]=0;
		if(n2>0&&b[1][i]) ans++,n2--,b[1][i]=0;
		
		if(a[1][i]&&b[2][i]) a[1][i]=0,b[2][i]=0,ans++;
		if(a[2][i]&&b[1][i]) a[2][i]=0,b[1][i]=0,ans++;
		
		if(a[1][i]) n1++;if(a[2][i]) n2++;
		if(b[1][i]) n1--;if(b[2][i]) n2--;
		
		ans+=abs(n1);ans+=abs(n2);
	}
	if(n1||n2)
	{
		puts("-1");
		return 0;
	}
	write(ans);
	return 0;
}