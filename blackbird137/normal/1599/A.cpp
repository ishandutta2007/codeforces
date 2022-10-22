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

const int N=2e5+5;
int n,a[N],b[N];
char s[N];

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+1+n);
	scanf("%s",s+1);
	int l=1,r=n;
	for(int i=n;i>=1;--i)
		if(s[i]!=s[i-1])
			b[i]=r--;
		else b[i]=l++;
	for(int i=1;i<=n;++i)
	{
		write(a[b[i]]);
		putchar(' ');
		if(n%2==1)
		{
			if(b[i]%2==(s[n]=='R'))
				putchar('R');
			else putchar('L');
		}
		else
		{
			if(b[i]%2!=(s[n]=='R'))
				putchar('R');
			else putchar('L');
		}
		puts("");
	}
	return 0;
}