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
#define max Max
#define min Min
#define abs Abs

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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=1e6+5;
int k,l,r,t,x,y,fl=1,vis[N];

signed main()
{
	k=read();l=read();r=read();t=read();x=read();y=read();
	if(y<x)
	{
		int now=0;
		while(k+y>r&&now<t) k-=x,now++;
		if((k-l)/(x-y)>=t-now) printf("Yes\n");
		else printf("No\n");
		return 0;
	} 
	int now=(k-l)/x;
	k-=now*x;
	while(now<t)
	{
		if(vis[k-l])
			break;
		vis[k-l]=1;
		if(k+y>r)
		{
			printf("No\n");
			return 0;
		}
		k+=y;
		int tmp=(k-l)/x;
		now+=tmp;
		if(now>=t) break;
		k-=tmp*x;
	}
	printf("Yes\n");
	return 0;
}