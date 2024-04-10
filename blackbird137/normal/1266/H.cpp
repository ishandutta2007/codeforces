#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define Int __int128
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

const Int mod1=999999999999999989;
const Int mod2=999999999999999967;
const int N=155;
int n,q,x[N],a[N],b[N],w[N],c[N][N],st;
Int d1[N][N],d2[N][N],e1[N],e2[N];
char opt[N];

vector<int> p1[N],p2[N];

inline Int q_pow(Int a,Int b,Int p)
{
	Int c=1;
	while(b)
	{
		if(b&1) c=a*c%p;
		a=a*a%p;b>>=1;
	}
	return c;
}

inline void gauss(Int p[N][N],int n,Int mod)
{
	for(int i=1;i<=n;++i)
	{
		int ps=i;
		for(int j=i;j<=n;++j)
			if(p[j][i])
			{
				ps=j;
				break;
			}
		if(ps!=i) swap(p[i],p[ps]);
		Int inv=q_pow(p[i][i],mod-2,mod);
		for(int j=1;j<=n;++j)
			if(j!=i)
			{
				Int tmp=mod-p[j][i]*inv%mod;
				for(int k=1;k<=n*2;++k)
					p[j][k]=(p[j][k]+p[i][k]*tmp%mod)%mod;
			}
	}
	for(int i=1;i<=n;++i)
	{
		Int tmp=q_pow(p[i][i],mod-2,mod);
		for(int j=n+1;j<=n*2;++j)
			p[i][j]=p[i][j]*tmp%mod;
	}
}

inline void init()
{
	for(int i=1;i<=n;++i)
	{
		p1[a[i]].push_back(i);
		p2[b[i]].push_back(i);
	}
	for(int i=1;i<=n;++i)
	{
		c[i][i]=2;
		for(int j=0;j<p1[i].size();++j)
			c[i][p1[i][j]]--;
		for(int j=0;j<p2[i].size();++j)
			c[i][p2[i][j]]--;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			d1[i][j]=(c[i][j]+mod1)%mod1;
			d2[i][j]=(c[i][j]+mod2)%mod2;
			d1[i][j+n]=(i==j);
			d2[i][j+n]=(i==j);
		}
	gauss(d1,n,mod1);
	gauss(d2,n,mod2);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			d1[i][j]=d1[i][j+n];
			d2[i][j]=d2[i][j+n];
		}
}

inline int query()
{
	for(int i=1;i<=n;++i)
		e1[i]=e2[i]=0,w[i]=0;
	for(int i=1;i<=n;++i)
		if(opt[i]=='R')
			w[b[i]]++,w[a[i]]--;
	w[1]+=2;w[st]-=2;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			e1[i]=(e1[i]+d1[i][j]*w[j]%mod1+mod1)%mod1;
			e2[i]=(e2[i]+d2[i][j]*w[j]%mod2+mod2)%mod2; 
		}
	for(int i=1;i<=n;++i)
	{
		if(e1[i]!=e2[i]) return -1;
		if(e1[i]%2!=(opt[i]=='R')) return -1;
	}
	for(int i=1;i<=n;++i)
	{
		if(!e1[i]) continue;
		int now=i,flag=0;
		for(int j=1;j<=n;++j)
		{
			if(now==st)
			{
				flag=1;
				break;
			}
			if(opt[now]=='B')
				now=a[now];
			else now=b[now];
		}
		if(!flag) return -1;
	}
	Int ans=0;
	for(int i=1;i<=n;++i)
		ans+=e1[i];
	return (int)ans;
}

signed main()
{

	n=read();
	for(int i=1;i<n;++i)
		a[i]=read(),b[i]=read();
	init();
	q=read();
	while(q--)
	{
		st=read();
		scanf("%s",opt+1);
		write(query());puts("");
	}
	return 0;
}