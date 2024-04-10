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

#define int __int128
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

const int N=2005;
int t,n,m,k,p,x,id[N];
char s1[N],s2[N*N];

struct Node
{
	int x,y;
}a[N];

inline int check(int y)
{
	if(!x) return 0;
	int now=1;
	for(int i=y+1;i<=p;++i)
		if(a[i].x==1)
		{
			now*=(k*a[i].y+1);
			if(now>x)
				return 0;
		}
	return now;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();x=read()-1;
		scanf("%s",s1+1);p=0;
		int now=1;m=0;
		for(int i=2;i<=n+1;++i)
			if(s1[i]!=s1[i-1])
				a[++p]=(Node){s1[i-1]=='a'?0:1,now},now=1;
			else ++now;
		for(int i=1;i<=p;++i)
			if(a[i].x==0)
			{
				for(int j=1;j<=a[i].y;++j)
					s2[++m]='a';
			}
			else
			{
				if(!check(i))
					continue;
				int tmp=check(i);
				for(int j=1;j<=k*a[i].y;++j)
					if(x>=tmp)
					{
						s2[++m]='b';
						x-=tmp;
					}
					else break;
			}
		for(int i=1;i<=m;++i)
			putchar(s2[i]);
		puts("");
	}
	return 0;
}