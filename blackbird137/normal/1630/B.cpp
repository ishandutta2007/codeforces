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

const int N=2e5+5;
int t,n,k,a[N];

vector<int> b[N];
vector<pair<int,int> > ans;

inline int check(int x)
{
	int now=-n;
	for(int i=1;i<=x;++i)
		now+=b[i].size()*2;
	for(int i=1;i+x-1<=n;++i)
	{
		if(now>=k) return i;
		now-=b[i].size()*2;
		now+=b[i+x].size()*2;
	}
	return -1;
}

inline void work(int x,int y)
{
	int now=0,lim=0,ls=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>=x&&a[i]<=y)
			now++;
		else now--;
		if(now>lim)
		{
			ans.push_back(mp(ls+1,i));
			lim=now;ls=i;
		}
	}
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1;i<=n;++i)
			b[i].clear();
		for(int i=1;i<=n;++i)
			a[i]=read(),b[a[i]].push_back(i);
		int l=1,r=n,p1=-1,p2=-1;
		while(l<=r)
		{
			int tmp=check(mid);
			if(tmp!=-1)
				p1=mid,p2=tmp,r=mid-1;
			else l=mid+1;
		}
		ans.clear();
		work(p2,p2+p1-1);
		printf("%d %d\n",p2,p2+p1-1);
		for(int i=1;i<=k-1;++i)
			printf("%d %d\n",ans[i-1].fi,ans[i-1].se);
		printf("%d %d\n",ans[k-1].fi,n);
	}
	return 0;
}