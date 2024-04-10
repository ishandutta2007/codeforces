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

const int N=105;
int t,n,m,p,a[N][N],sum[N*N*10];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();p=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				a[i][j]=read();
				sum[++p]=a[i][j];
				sum[++p]=a[i][j]+1;
			}
		sort(sum+1,sum+1+p);
		for(int k=1;k<=p;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					if(a[i][j]==sum[k]&&(i+j)%2==sum[k]%2)
						a[i][j]++;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				printf("%lld ",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}