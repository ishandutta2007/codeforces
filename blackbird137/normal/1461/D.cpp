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

const int N=1e5+5;
int t,n,q,a[N],sum[N];

map<int,int> mp;

inline void binary(int l,int r);
inline int bin(int l,int r,int x);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();q=read();
		mp.clear();
		for(int i=1;i<=n;++i)
			a[i]=read();
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)
			sum[i]=sum[i-1]+a[i];
		binary(1,n);
		while(q--)
		{
			int x=read();
			if(mp[x]) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}

inline void binary(int l,int r)
{
	if(l>r) return;
	int mid=(a[l]+a[r])>>1;
	mp[sum[r]-sum[l-1]]=1;
	if(l==r) return;
	int pos=bin(l,r,mid);
	if(pos!=r) binary(l,pos);
	binary(pos+1,r);
}

inline int bin(int l,int r,int x)
{
	int res=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<=x)
		{
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return res;
}