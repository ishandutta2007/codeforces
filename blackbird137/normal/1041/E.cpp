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
#define fan(x) (((x-1)^1)+1)
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

const int N=1e3+5;
int n,b[N],a[N],vis[N];

signed main()
{
	n=read();
	for(int i=1;i<=n-1;++i)
	{
		int u=read(),v=read();
		if(u>v) swap(u,v);
		if(v!=n)
		{
			printf("NO\n");
			return 0;
		}
		b[i]=u;
	}
	sort(b+1,b+n);
	for(int i=1;i<=n;++i)
	{
		if(b[i]!=b[i-1])
		{
			a[i]=b[i];
			vis[a[i]]=true;
		}
		else
		{
			int flag=0;
			for(int j=1;j<=b[i];++j)
				if(!vis[j])
				{
					a[i]=j;
					vis[j]=true;
					flag=1;break;
				}
			if(!flag)
			{
				printf("NO\n");
				return 0;	
			}
		} 
	}
	printf("YES\n");
	a[n]=n;
	for(int i=1;i<=n-1;++i)
		printf("%lld %lld\n",a[i],a[i+1]);
	return 0;
}