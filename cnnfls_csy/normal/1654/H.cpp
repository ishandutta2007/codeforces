#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int maxn=524288;
const int mod=998244353;
int fac[maxn+5],inv[maxn+5],fi[maxn+5],rev[maxn+5],w[maxn+5],ta[maxn+5],tb[maxn+5];
int qp(int x,int y)
{
	int z=1;
	while(y){
		if(y&1)z=1ll*z*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return z;
}
void init()
{
	fac[0]=fac[1]=fi[0]=fi[1]=inv[1]=w[0]=1;w[1]=qp(3,(mod-1)/maxn);
	int i;
	fz(i,2,maxn){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fi[i]=1ll*fi[i-1]*inv[i]%mod;
		w[i]=1ll*w[i-1]*w[1]%mod;
	}
}
int getrev(int x)
{
	int len=1,i;
	while(len<=x){
		len<<=1; 
	}
	fz0k(i,len){
		rev[i]=(rev[i/2]/2)+((len/2)*(i&1)); 
	}
	return len; 
}
void ntt(int *a,int len,int op)
{
	int i,j,k;
	fz0k(i,len)if(rev[i]<i) swap(a[i],a[rev[i]]);
	for(i=1;i<len;i<<=1){
		int ys=maxn/i/2;
		for(j=0;j<len;j+=i+i){
			int t=(op==1?0:maxn);
			fz0k(k,i){
				int x=a[j+k],y=a[j+k+i]*1ll*w[t]%mod;
				a[j+k]=(x+y)%mod;a[j+k+i]=(x-y+mod)%mod;
				t+=op*ys;
			}
		}
	}
	if(op==-1){
		fz0k(i,len) a[i]=1ll*a[i]*inv[len]%mod;
	}
}
int binom(int x,int y){return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;}
int n,m,i,j,ans,pw[200005],f[200005],g[200005],dp[105][200005];
char a[105];
void solve1(int l,int r)
{
	if(l==r) return;int mid=(l+r)/2,i,j;
	solve1(l,mid);
	// fz(i,l,mid)fz(j,mid+1,r) f[j]=(f[j]+1ll*f[i]*pw[max(0,j-i-2)]%mod*binom(j-2,i-1))%mod;
	int len=getrev(r-l+mid-l+3);
	fz0k(i,len) ta[i]=tb[i]=0;
	fz(i,l,mid) ta[i-l]=1ll*f[i]*fi[i-1]%mod;
	fz1(i,r-l) tb[i]=1ll*pw[max(0,i-2)]*fi[i-1]%mod;
	ntt(ta,len,1);ntt(tb,len,1);
	fz0k(i,len) ta[i]=1ll*ta[i]*tb[i]%mod;
	ntt(ta,len,-1);
	fz(i,mid+1,r) f[i]=(f[i]+1ll*ta[i-l]*fac[i-2])%mod;
	solve1(mid+1,r);
}
void solve2(int l,int r)
{
	if(l==r) return;int mid=(l+r)/2,i,j;
	solve2(mid+1,r);
//	fz(i,mid+1,r)fz(j,l,mid) g[j]=(g[j]+1ll*g[i]*pw[max(0,i-j-2)]%mod*binom(n-j-1,n-i))%mod;
	int len=getrev(r-l+r-mid+3);
	fz0k(i,len) ta[i]=tb[i]=0;
	fz(i,mid+1,r) ta[r-i]=1ll*g[i]*fi[n-i]%mod;
	fz1(i,r-l) tb[i]=1ll*pw[max(0,i-2)]*fi[i-1]%mod;
	ntt(ta,len,1);ntt(tb,len,1);
	fz0k(i,len) ta[i]=1ll*ta[i]*tb[i]%mod;
	ntt(ta,len,-1);
	fz(i,l,mid) g[i]=(g[i]+1ll*ta[r-i]*fac[n-i-1])%mod;
	solve2(l,mid);
}
int main()
{
//	cerr<<sizeof(dp)/1048576<<endl;
	init();pw[0]=1;fz1(i,200002) pw[i]=2ll*pw[i-1]%mod;
	read(n);read(m);fz1(i,m)while((a[i]=getchar())!='<'&&a[i]!='>');

	fz1(i,m+1) dp[i][i]=dp[i][i-1]=1;
	fz(i,m+2,n) dp[m+1][i]=pw[i-m-1];
	fd1(i,m)fz(j,i+1,n){
		if(a[i]=='<') dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;
		if(j>m+1||a[j-1]=='>') dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
	}

	f[1]=1;
	fz1(i,m)if(a[i]=='<'){
		fz(j,i+1,n)if(j>m+1||a[j-1]=='>'){
			f[j]=(f[j]+1ll*f[i]*dp[i+1][j-1]%mod*binom(j-2,i-1))%mod;
		}
	}
	else f[i+1]=(f[i+1]+f[i])%mod;
	solve1(m+1,n);

	g[n]=1;
	solve2(m+1,n);
	fd1(i,m)if(a[i]=='<'){
		fz(j,i+1,n)if(j>m+1||a[j-1]=='>'){
			g[i]=(g[i]+1ll*g[j]*dp[i+1][j-1]%mod*binom(n-i-1,n-j))%mod;
		}
		else if(j==i+1) g[i]=(g[i]+g[i+1])%mod;
	}

	fz1(i,n) ans=(ans+1ll*f[i]*g[i]%mod*binom(n-1,i-1))%mod;
	printf("%d\n",ans);
	return 0;
}