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
int t,n,m,a[N],vis[N];

vector<pair<int,int> > dol;

inline void insert(int x,int c)
{
	dol.push_back(mp(x,c));
	for(int i=m;i>=x;--i)
		a[i+2]=a[i];
	m+=2;a[x+1]=a[x+2]=c;
}

vector<int> ans;
map<int,int> hav;

signed main()
{
	t=read();
	while(t--)
	{
		n=m=read();
		hav.clear();
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			hav[a[i]]^=1;
		}
		int flag=1;
		for(int i=1;i<=n;++i)
			if(hav[a[i]])
				flag=0;
		if(!flag)
		{
			puts("-1");
			continue;
		}
		ans.clear();dol.clear();
		int ls=1;
		for(int i=2;i<=m;++i)
		{
			while(vis[ls]) ls++;
			if(a[i]==a[ls])
			{
				for(int j=ls+1;j<i;++j)
					insert(i+j-ls-1,a[j]);
				ans.push_back((i-ls)*2);
				for(int j=ls;j<=i+i-ls-1;++j)
					vis[j]=1;
				i+=i-ls;
			}
		}
			
		write(dol.size());puts("");
		for(int i=0;i<dol.size();++i)
			printf("%d %d\n",dol[i].fi,dol[i].se);
		write(ans.size());puts("");
		for(int i=0;i<ans.size();++i)
			printf("%d ",ans[i]);
		puts("");
		for(int i=1;i<=m;++i)
			a[i]=0,vis[i]=0;
	}
	return 0;
}