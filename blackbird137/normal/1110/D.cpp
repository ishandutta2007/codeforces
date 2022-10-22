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
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)

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

inline int Abs(int a){return a>0?a:-a;};
inline int Min(int a,int b){return a>b?b:a;}
inline int Max(int a,int b){return a>b?a:b;}

const int N=1e6+5;
int n,m,a[N],dp[N][3][3];

signed main()
{
	//freopen("ggame11.in","r",stdin);
	//freopen("ggame11.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i)
    {
    	int p=read();
    	//if(a[p]) printf("no\n");
    	m=max(m,p);a[p]++;
	}
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=m;++i)
		for(int j=0;j<=2;++j)
			for(int k=0;k<=2;++k)
				for(int l=0;l<=2;++l)
					if(a[i]>=j+k+l)
						dp[i][k][l]=max(dp[i][k][l],dp[i-1][j][k]+(a[i]-j-k-l)/3+j);
    printf("%lld\n", dp[m][0][0]);
	return 0;
}