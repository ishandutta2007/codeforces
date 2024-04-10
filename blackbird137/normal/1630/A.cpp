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

const int N=1e5+5;
int t,n,m,k,vis[N];

inline int query(int x)
{
	int res=0;
	for(int i=0;i<m;++i)
		if(((x>>i)&1)==0)
			res|=(1<<i);
	return res;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		if(n==4&&k==3)
		{
			puts("-1");
			continue;
		}
		m=-1;
		for(int i=1;i<=n;i<<=1) ++m;
		if(k==0)
		{
			for(int i=0;i<(n>>1);++i)
				printf("%d %d\n",i,query(i));
			continue;
		}
		if(k==n-1)
		{
			for(int i=0;i<=n;++i)
				vis[i]=0;
			printf("%d %d\n",1,3);
			printf("%d %d\n",n-1,n-2);
			printf("%d %d\n",0,query(3));
			vis[1]=vis[3]=1;
			vis[n-1]=vis[n-2]=1;
			vis[0]=vis[query(3)]=1;
			for(int i=1;i<n-1;++i)
				if(!vis[i])
				{
					int x=query(i);
					printf("%d %d\n",i,x);
					vis[x]=1;
				}
			continue;
		}
		printf("%d %d\n",n-1,k);
		printf("%d %d\n",query(k),0);
		for(int i=0;i<=n;++i)
			vis[i]=0;
		vis[0]=vis[n-1]=1;
		vis[k]=vis[query(k)]=1;
		for(int i=1;i<n-1;++i)
			if(!vis[i])
			{
				int x=query(i);
				printf("%d %d\n",i,x);
				vis[x]=1;
			}
	}
	return 0;
}