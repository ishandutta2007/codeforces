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
int t,n,m,k,a[N],b[N];

struct Node
{
	int x,y;
	bool operator < (const Node &p)const
	{
		return y>p.y;
	}
 }c[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=k=read();m=0;
		for(int i=2;i*i<=n;++i)
		{
			if(n%i==0) a[++m]=i;
			while(n%i==0){n/=i,++b[m];}
		}
		if(n>1)a[++m]=n,b[m]=1;
		for(int i=1;i<=m;++i)
			c[i]=(Node){a[i],b[i]};
		sort(c+1,c+1+m);
		int res=c[1].y;
		printf("%lld\n",res);
		for(int i=1;i<=c[1].y-1;++i)
			printf("%lld ",c[1].x),k/=c[1].x;
		printf("%lld\n",k);
		//printf("\n");
		for(int i=1;i<=m;++i)
			a[i]=0,b[i]=0;
	}
	return 0;
}