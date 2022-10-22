#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int Mod=998244353;
int K,D[22],P[22],dc;

int cnt[22][1024],dp[22][1024];
void dfs(int n,int u,int z,int b,int& c,int& v)
{
	if(__builtin_popcount(b)>K)return;
	if(!n){c=1;return;}
	if(!u&&!z&&cnt[n][b]!=-1){c=cnt[n][b],v=dp[n][b];return;}
	int h=u?D[n]:9;
	Fr(i,0,h)
	{
		int z_=z&&!i,c_=0,v_=0;
		dfs(n-1,u&&i==h,z_,b|!z_<<i,c_,v_);
		c=(c+c_)%Mod,v=(v+v_+(ll)c_*i%Mod*P[n-1])%Mod;
	}
	if(!u&&!z)cnt[n][b]=c,dp[n][b]=v;
}

int Query(ll x)
{
	dc=0;
	while(x)D[++dc]=x%10,x/=10;
	int c=0,v=0;
	dfs(dc,1,1,0,c,v);
	return v;
}

int main()
{
	P[0]=1;
	Fr(i,1,21)P[i]=(ll)P[i-1]*10%Mod;
	memset(cnt,0xff,sizeof(cnt));
	ll l,r;
	scanf("%lld%lld%d",&l,&r,&K);
	printf("%d\n",(Query(r)-Query(l-1)+Mod)%Mod);
	return 0;
}