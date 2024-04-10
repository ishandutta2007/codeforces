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

const int N=5e5+5;
int n,a[N],dp1[N][2],dp2[N][2];

inline int _min(int x,int y)
{
	if(x==-1) return y;
	return min(x,y);
}

inline int _max(int x,int y)
{
	if(x==-1) return y;
	return max(x,y);
}

signed main()
{
	n=read();
	int mx=-1,ps=-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]>mx)
			mx=a[i],ps=i;
	}
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));
	if(ps==n)
		dp1[n][0]=0;
	else dp1[n][0]=dp1[n][1]=0;
	for(int i=n-1;i>=1;--i)
		if(i==ps)
		{
			if(dp1[i+1][0]!=-1)
				dp1[i][0]=_min(dp1[i][0],dp1[i+1][0]);
			if(dp1[i+1][1]!=-1)
				dp1[i][0]=_min(dp1[i][0],a[i+1]);
		}
		else if(i>ps)
		{
			if(dp1[i+1][0]!=-1&&a[i]>a[i+1])
				dp1[i][0]=_min(dp1[i][0],dp1[i+1][0]);
			if(dp1[i+1][1]!=-1&&a[i]>dp1[i+1][1])
				dp1[i][0]=_min(dp1[i][0],a[i+1]);
			
			if(dp1[i+1][1]!=-1&&a[i]>a[i+1])
				dp1[i][1]=_min(dp1[i][1],dp1[i+1][1]);
			if(dp1[i+1][0]!=-1&&a[i]>dp1[i+1][0])
				dp1[i][1]=_min(dp1[i][1],a[i+1]);
		}
		else
		{
			if(dp1[i+1][0]!=-1&&a[i]<a[i+1])
				dp1[i][0]=_min(dp1[i][0],dp1[i+1][0]);
			if(dp1[i+1][1]!=-1&&a[i]<dp1[i+1][1])
				dp1[i][0]=_min(dp1[i][0],a[i+1]);
			
			if(dp1[i+1][1]!=-1&&a[i]>a[i+1])
				dp1[i][1]=_max(dp1[i][1],dp1[i+1][1]);
			if(dp1[i+1][0]!=-1&&a[i]>dp1[i+1][0])
				dp1[i][1]=_max(dp1[i][1],a[i+1]);
		}
	
	if(ps==1)
		dp2[1][0]=0;
	else dp2[1][0]=dp2[1][1]=0;
	for(int i=2;i<=n;++i)
		if(i==ps)
		{
			if(dp2[i-1][0]!=-1)
				dp2[i][0]=_min(dp2[i][0],dp2[i-1][0]);
			if(dp2[i-1][1]!=-1)
				dp2[i][0]=_min(dp2[i][0],a[i-1]);
		}
		else if(i<ps)
		{
			if(dp2[i-1][0]!=-1&&a[i]>a[i-1])
				dp2[i][0]=_min(dp2[i][0],dp2[i-1][0]);
			if(dp2[i-1][1]!=-1&&a[i]>dp2[i-1][1])
				dp2[i][0]=_min(dp2[i][0],a[i-1]);
			
			if(dp2[i-1][1]!=-1&&a[i]>a[i-1])
				dp2[i][1]=_min(dp2[i][1],dp2[i-1][1]);
			if(dp2[i-1][0]!=-1&&a[i]>dp2[i-1][0])
				dp2[i][1]=_min(dp2[i][1],a[i-1]);
		}
		else
		{
			if(dp2[i-1][0]!=-1&&a[i]<a[i-1])
				dp2[i][0]=_min(dp2[i][0],dp2[i-1][0]);
			if(dp2[i-1][1]!=-1&&a[i]<dp2[i-1][1])
				dp2[i][0]=_min(dp2[i][0],a[i-1]);
			
			if(dp2[i-1][1]!=-1&&a[i]>a[i-1])
				dp2[i][1]=_max(dp2[i][1],dp2[i-1][1]);
			if(dp2[i-1][0]!=-1&&a[i]>dp2[i-1][0])
				dp2[i][1]=_max(dp2[i][1],a[i-1]);
		}
	int ans=0;
	for(int i=1;i<=n;++i)
		if(i!=ps&&dp1[i][1]!=-1&&dp2[i][1]!=-1)
		{
			if(i<ps)
			{
				if(dp2[i][1]<dp1[i][1])
					ans++;
			}
			else
			{
				if(dp2[i][1]>dp1[i][1])
					ans++;
			}
		}
	write(ans);
	return 0;
}