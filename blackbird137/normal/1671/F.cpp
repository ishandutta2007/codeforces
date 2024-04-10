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

const int N=23,mod=998244353;
int t,n,m,a[N],vis[N],vis2[N],nm[N][N][N],dp[N][N][N][N];

struct Node
{
	int a,b,c,w;
}B[500];

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

inline int C(int n,int m)
{
	if(n<m) return 0;
	int res=1;
	for(int i=1;i<=m;++i)
		res=res*(n-i+1)%mod*q_pow(i,mod-2)%mod;
	return res;
}

void dfs(int u,int lm,int s)
{
	if(s>11) return;
	if(u==lm+1)
	{
		int fflag=0;
		for(int i=1;i<=lm;++i)
			vis2[i]=0;
		for(int i=1;i<lm&&!fflag;++i)
		{
			vis2[a[i]]=1;
			int flag=1;
			for(int j=1;j<=i;++j)
				flag&=vis2[j];
			if(flag) fflag=1;
		}
		for(int i=1;i<=lm;++i)
			vis2[i]=0;
		for(int i=lm;i>1&&!fflag;--i)
		{
			vis2[a[i]]=1;
			int flag=1;
			for(int j=i;j<=lm;++j)
				flag&=vis2[j];
			if(flag) fflag=1;
		}
		if(fflag) return;
		int tmp=0;
		for(int i=1;i<lm;++i)
			tmp+=(a[i]>a[i+1]);
		nm[lm][s][tmp]++;
		return;
	}
	for(int i=lm,j=0;i>=1;--i)
		if(!vis[i])
		{
			vis[i]=1;a[u]=i;
			dfs(u+1,lm,s+j);
			vis[i]=0;a[u]=0;
		}
		else j++;
}

signed main()
{
	for(int i=2;i<=12;++i)
		dfs(1,i,0);
	for(int i=0;i<=20;++i)
		for(int j=0;j<=20;++j)
			for(int k=0;k<=20;++k)
				if(nm[i][j][k])
					B[++m]=(Node){i,j,k,nm[i][j][k]};
	dp[0][0][0][0]=1;
	for(int a=0;a<=11;++a)
		for(int b=0;b<=22;++b)
			for(int c=0;c<=11;++c)
				for(int d=0;d<=11;++d)
					if(dp[a][b][c][d])
						for(int i=1;i<=m;++i)
							if(c+B[i].b<=11&&d+B[i].c<=11)
								dp[a+1][b+B[i].a][c+B[i].b][d+B[i].c]=(dp[a+1][b+B[i].a][c+B[i].b][d+B[i].c]+dp[a][b][c][d]*B[i].w%mod)%mod;
	t=read();
	while(t--)
	{
		n=read();
		int p1=read(),p2=read(),ans=0;
		for(int i=0;i<=11;++i)
			for(int j=0;j<=22;++j)
				if(dp[i][j][p1][p2])
					ans=(ans+dp[i][j][p1][p2]*C(n-j+i,i)%mod)%mod;
		write(ans);puts("");
	}
	return 0;
}