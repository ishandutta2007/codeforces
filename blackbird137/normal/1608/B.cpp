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

const int N=1e5+5;
int t,n,a,b;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		a=read();b=read();
		if(abs(a-b)>1||a+b>n-2)
		{
			puts("-1");
			continue;
		}
		int ls=0,l=1,r=n;
		if(a<=b)
		{
			write(n);putchar(' ');
			ls=n,--r;
			while(a||b)
			{
				if(b) ls=l,write(l++),putchar(' '),--b;
				if(a) ls=r,write(r--),putchar(' '),--a;
			}
		}
		else
		{
			write(1);putchar(' ');
			ls=1,++l;
			while(a||b)
			{
				if(a) ls=r,write(r--),putchar(' '),--a;
				if(b) ls=l,write(l++),putchar(' '),--b;
			}
		}
		if(ls<l)
		{
			for(int i=l;i<=r;++i)
				write(i),putchar(' ');
		}
		else
		{
			for(int i=r;i>=l;--i)
				write(i),putchar(' ');
		}	 
		puts("");
	}
	return 0;
}