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

const int N=4e5+5;
int t,n,m,a[N],b[N],ok1[N],ok2[N],vis[N],ans;

inline int check(int x);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=0;ans=0;
		for(int i=1;i<=n;++i)
		{
			b[i]=read();
			vis[b[i]]=1;
		}
		sort(b+1,b+1+n);
		for(int i=1;i<=n*2;++i)
			if(!vis[i]) a[++m]=i;
		int nr=1,nl=n;
		for(int i=1;i<=n;++i)
		{
			while(nr<=n&&a[nr]<b[i]) nr++;
			if(nr<=n) nr++,ok1[i]=1;
		}
			
		for(int i=n;i>=1;--i)
		{
			while(nl>=1&&a[nl]>b[i]) nl--;
			if(nl>=1) nl--,ok2[i]=1;
		}
			
		for(int i=1,fl=1;i<=n;++i)
		{
			if(ok1[i]==0) fl=0;
			ok1[i]=fl;
		}
		for(int i=n,fl=1;i>=1;--i)
		{
			if(ok2[i]==0) fl=0;
			ok2[i]=fl;
		}	
		for(int i=0;i<=n;++i)
			if((i==0||ok1[i])&&(i==n||ok2[i+1]))
				ans++;
		printf("%lld\n",ans);
		for(int i=1;i<=n*2;++i)
			vis[i]=0,a[i]=0,ok1[i]=0,ok2[i]=0;
	}
	return 0;
}

inline int check(int x)
{
	int nr=n;
	for(int i=x;i>=1;--i)
		if(a[nr]>b[i]) nr--;
		else return 0;
	int nl=1;
	for(int i=x+1;i<=n;++i)
		if(a[nl]<b[i]) nl++;
		else return 0;
	return 1;
}