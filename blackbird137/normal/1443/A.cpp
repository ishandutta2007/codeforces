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

const int N=1005;
int t,n,a[N];

bool check(int x);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		int sum=0;
		memset(a,0,sizeof(a));
		for(int i=n*2;sum<=n-1;++i)
			if(!a[i]&&i%2==0)
			{
				printf("%lld ",i);
				for(int j=2;j*i<=4*n;++j)
					a[j*i]=1;
				sum++;
			}
		printf("\n");
	}
	return 0;
}