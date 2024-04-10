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
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,mod,i,j,k,l,a,b,ans,c[405][405],dp[405][405];
void inc(int &x,int y)
{
	x+=y;
	if(x>=mod) x-=mod;
} 
int main()
{
	read(n);read(mod);
	c[0][0]=1;
	fz1(i,n){
		c[i][0]=1;
		fz1(j,i){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	dp[1][0]=1;
	fz1(i,n-1)fz0g(j,n)if(dp[i][j]){
		inc(dp[i+1][j+1],2ll*dp[i][j]%mod); //2+
		inc(dp[i+2][j],2ll*dp[i][j]%mod);  //1
		inc(dp[i+1][j],2ll*dp[i][j]%mod);  //0
		
		inc(dp[i+1][j+1],1ll*j*dp[i][j]%mod); //22
		inc(dp[i+2][j],2ll*j*dp[i][j]%mod); //21
		inc(dp[i+1][j],2ll*j*dp[i][j]%mod); //20
		if(j)inc(dp[i+3][j-1],1ll*j*dp[i][j]%mod); //11
		if(j)inc(dp[i+2][j-1],2ll*j*dp[i][j]%mod); //10
	}
	cout<<dp[n][0]<<endl;
	return 0;
}