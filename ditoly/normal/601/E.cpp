#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 15000
#define N 32768
#define X 10000019
#define MOD 1000000007
int k,cnt,v[MN+5],w[MN+5],u[MN+5],Q[N+5],f[20][N*2+5];
vector<int> t[N*2+5];
void ins(int l,int r,int x)
{
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)t[l+1].push_back(x);
		if( r&1)t[r-1].push_back(x);
	}
}
void solve(int x,int dep)
{
	for(int i=0;i<=k;++i)f[dep][i]=f[dep-1][i];
	for(int i=0;i<t[x].size();++i)for(int j=k;j>=w[t[x][i]];--j)
			f[dep][j]=max(f[dep][j],f[dep][j-w[t[x][i]]]+v[t[x][i]]);
	if(x<N)solve(x<<1,dep+1),solve(x<<1|1,dep+1);
	else if(Q[x-N]>2)
	{
		int ans=0,i;
		for(i=k;i;--i)ans=(1LL*ans*X+f[dep][i])%MOD;
		printf("%d\n",ans);
	}
}
int main()
{
	int n,q,i;
	cnt=n=read();k=read();
	for(i=1;i<=n;++i)v[i]=read(),w[i]=read(),u[i]=1;
	for(q=read(),i=1;i<=q;++i)
	{
		Q[i]=read();
		if(Q[i]==1)v[++cnt]=read(),w[cnt]=read(),u[cnt]=i;
		if(Q[i]==2)n=read(),ins(u[n],i,n),u[n]=0;
	}
	for(i=1;i<=cnt;++i)if(u[i])ins(u[i],q,i);
	solve(1,1);
}