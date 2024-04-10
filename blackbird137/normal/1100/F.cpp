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
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
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

const int N=5e5+5,M=22;
int n,a[N],q,dp1[N][M],dp2[N][M],ans[N],tmp[M];

struct Node
{
	int l,r;
}b[N];

vector<int> ps[N],hav;

inline void solve(int l,int r)
{
	if(l>r) return;
	solve(l,mid-1);
	solve(mid+1,r);
	for(int i=0;i<=20;++i)
		dp1[mid+1][i]=dp2[mid][i]=0;
	for(int i=mid;i>=l;--i)
	{
		int tmp=a[i];
		for(int j=20;j>=0;--j)
			dp1[i][j]=dp1[i+1][j];
		for(int j=20;j>=0;--j)
			if((tmp>>j)&1)
			{
				if(!dp1[i][j])
				{
					dp1[i][j]=tmp;
					break;
				}
				tmp^=dp1[i][j];
			}
	}
	for(int i=mid+1;i<=r;++i)
	{
		int tmp=a[i];
		for(int j=20;j>=0;--j)
			dp2[i][j]=dp2[i-1][j];
		for(int j=20;j>=0;--j)
			if((tmp>>j)&1)
			{
				if(!dp2[i][j])
				{
					dp2[i][j]=tmp;
					break;
				}
				tmp^=dp2[i][j];
			}
	}
	hav.clear();
	for(int i=l;i<=mid;++i)
		for(int j=0;j<ps[i].size();++j)
			if(b[ps[i][j]].r>=mid&&b[ps[i][j]].r<=r)
				hav.push_back(ps[i][j]);
	for(int i=0;i<hav.size();++i)
	{
		int l=b[hav[i]].l,r=b[hav[i]].r;
		for(int j=0;j<=20;++j)
			tmp[j]=dp1[l][j];
		for(int j=0;j<=20;++j)
		{
			int lol=dp2[r][j];
			for(int k=20;k>=0;--k)
				if((lol>>k)&1)
				{
					if(!tmp[k])
					{
						tmp[k]=lol;
						break;
					}
					lol^=tmp[k];
				}
		}
		int res=0;
		for(int j=20;j>=0;--j)
			if(res<(res^tmp[j]))
				res^=tmp[j];
		ans[hav[i]]=res;
	}
}

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	q=read();
	for(int i=1;i<=q;++i)
	{
		b[i].l=read();b[i].r=read();
		ps[b[i].l].push_back(i);
	}
	solve(1,n);
	for(int i=1;i<=q;++i)
		write(ans[i]),puts("");
	return 0;
}