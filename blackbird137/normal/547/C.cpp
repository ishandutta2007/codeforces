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
 
inline void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}
 
template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}
 
const int N=5e5+5;
int n,m,q,a[N],b[N],c[N],d[N],pri[N],vis[N],miu[N];
long long now;
 
vector<int> hav[N]; 
 
inline void init(int x)
{
	miu[1]=1;
	for(int i=2;i<=x;++i)
	{
		if(!vis[i])
			pri[++m]=i,miu[i]=-1;
		for(int j=1;j<=m;++j)
		{
			if(i*pri[j]>x)
				break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)
			{
				miu[i*pri[j]]=0;
				break;
			}
			miu[i*pri[j]]=-miu[i];
		}
	}
	for(int i=1;i<=x;++i)
		for(int j=i;j<=x;j+=i)
			if(miu[i]) hav[j].push_back(i);
}
 
inline void update(int x,int v)
{
	for(int i=0;i<hav[x].size();++i)
	{
		int u=hav[x][i];
		now-=miu[u]*1ll*c[u]*c[u];
		c[hav[x][i]]+=v;
		now+=miu[u]*1ll*c[u]*c[u];
	}
}
 
signed main()
{
	init(500000);
	n=read();q=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	while(q--)
	{
		int x=read();
		if(b[x]) b[x]=0,update(a[x],-1),d[a[x]]--;
		else b[x]=1,update(a[x],1),d[a[x]]++;
		write((now-d[1])/2);puts("");
	}
	return 0;
}