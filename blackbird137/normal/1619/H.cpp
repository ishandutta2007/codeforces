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

const int N=1e5+5,BLOCK=144;
int n,q,up1[N],up2[N],dn[N];

inline int climb(int x)
{
	for(int i=1;i<=BLOCK;++i)
		x=up1[x];
	return x;
}

signed main()
{
	n=read();q=read();
	for(int i=1;i<=n;++i)
	{
		up1[i]=read();
		dn[up1[i]]=i;
	}
	for(int i=1;i<=n;++i)
		up2[i]=climb(i);
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read(),y=read();
			swap(dn[up1[x]],dn[up1[y]]);
			swap(up1[x],up1[y]);
			int px=climb(x),py=climb(y);
			for(int i=0;i<=BLOCK;++i)
			{
				up2[x]=px,up2[y]=py;
				x=dn[x],px=dn[px];
				y=dn[y],py=dn[py];
			}
		}
		else
		{
			int x=read(),k=read();
			while(k>=BLOCK)
				x=up2[x],k-=BLOCK;
			while(k)
				x=up1[x],--k;
			write(x);puts("");
		}
	}
	return 0;
}