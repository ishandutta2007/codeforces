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
#define fls fflush(stdout)

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

const int N=1e5+5;
int n,a[N];

signed main()
{
	n=read();
	printf("AND 1 2\n");fls;
	int p1=read();
	printf("AND 1 3\n");fls;
	int p2=read();
	printf("XOR 1 2\n");fls;
	int p3=read();
	printf("XOR 1 3\n");fls;
	int p4=read();
	printf("AND 2 3\n");fls;
	int p5=read();
	a[1]=((p1|p2)|((p3&p4)^p5));
	a[2]=(a[1]^p3);
	a[3]=(a[1]^p4);
	for(int i=4;i<=n;++i)
	{
		printf("XOR 1 %lld\n",i);fls;
		int tmp=read();
		a[i]=(a[1]^tmp);
	}
	fls;
	printf("! ");
	for(int i=1;i<=n;++i)
	{
		printf("%lld",a[i]);
		if(i!=n) printf(" ");
	}
	return 0;
}