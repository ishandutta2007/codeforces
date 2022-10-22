#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int mod=998244353;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,minn[110],x[110],y[110],sum[110],inv[110],vis[110];
int calc(int a,int b) {return abs(x[a]-x[b])+abs(y[a]-y[b]);}
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1) z=(ll)z*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return z;
}
inline int C(int n,int m) {return (n<0 || m<0 || n<m)?0:(ll)sum[n]*inv[m]%mod*inv[n-m]%mod;}
vector<int> mem;
int dp[110];
int dl[110],h,t,pd[110];
void solve(int x)
{
	h=t=0;
	memset(pd,0,sizeof(pd));
	dl[++t]=x;
	vis[x]=pd[x]=1;
	while(h!=t)
	{
		int u=dl[++h];
		for(int i=1;i<=n;++i) if(!pd[i] && calc(i,u)==minn[u])
		{
			if(minn[u]!=minn[i]) return;
			dl[++t]=i;
			vis[i]=pd[i]=1;
		}
	}
	for(int i=1;i<=t;++i)
		for(int j=i+1;j<=t;++j)
			if(calc(dl[i],dl[j])!=minn[dl[i]])
				return;
	//for(int i=1;i<=t;++i) cout<<dl[i]<<" "<<minn[dl[i]]<<" | ";
	//cout<<endl;
	mem.push_back(t);
}
int main()
{
	n=read();
	sum[0]=inv[0]=1;
	for(int i=1;i<=n;++i) sum[i]=(ll)sum[i-1]*i%mod;
	inv[n]=ksm(sum[n],mod-2);
	for(int i=n-1;i>=1;--i) inv[i]=(ll)inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i) x[i]=read(),y[i]=read();
	for(int i=1;i<=n;++i)
	{
		minn[i]=0x3f3f3f3f;
		for(int j=1;j<=n;++j) if(i!=j) minn[i]=min(minn[i],calc(i,j));
	}
	for(int i=1;i<=n;++i) if(!vis[i]) solve(i);
	int N=mem.size();
	dp[n]=1;
	for(int i=0;i<N;++i)
		for(int j=1;j+mem[i]-1<=n;++j)
			dp[j]=MOD(dp[j]+dp[j+mem[i]-1]-mod);
	int ans=0;
	for(int i=1;i<=n;++i) ans=MOD(ans+(ll)dp[i]*C(n,i)%mod*sum[i]%mod-mod);
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw!