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

int t,n;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		int l1=2e9,c1=0,r1=-2e9,c2=0;
		int l2=2e9,r2=-2e9,c3=0;
		for(int i=1;i<=n;++i)
		{
			int x=read(),y=read(),z=read();
			
			if(x<l1) l1=x,c1=z;
			else if(x==l1&&z<c1) c1=z;
			
			if(y>r1) r1=y,c2=z;
			else if(y==r1&&z<c2) c2=z;
			
			if(x<l2) l2=x,r2=y,c3=z;
			else if(x==l2&&y>r2) r2=y,c3=z;
			else if(x==l2&&y==r2&&z<c3) c3=z;
			
			int res=c1+c2;
			if(l1==l2&&r1==r2)
				res=min(res,c3);
			write(res);puts("");
		}
	}
	return 0;
}