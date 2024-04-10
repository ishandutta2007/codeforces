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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,k,l,a[14][14],bt[1<<14];
long long ans[1<<14];
vector<long long> dp[14][1<<14];
int main()
{
	read(n);
	fz0k(i,n){
		char c;
		scanf(" ");
		fz0k(j,n){
			scanf("%c",&c);
			a[i][j]=(c&15);
		}
	}
	fz0k(i,(1<<n)){
		if(i) bt[i]=bt[i-(i&-i)]+1;
		fz0k(j,n)if((i>>j)&1) dp[j][i].resize(1<<bt[i]);
	}
	fz0k(i,n){
		dp[i][1<<i][0]=1;
	}
	fz0k(i,(1<<n))fz0k(j,n)if((i>>j)&1)fz0k(l,n)if(!((i>>l)&1)){
		fz0k(k,dp[j][i].size())if(dp[j][i][k]){
			dp[l][i|(1<<l)][k|(a[j][l]<<(bt[i]-1))]+=dp[j][i][k];
		}
	}
	fz0k(i,n){
		fz0k(j,(1<<(n-1))){
			ans[j]+=dp[i][(1<<n)-1][j];
		}
	}
//	cerr<<ans[(1<<(n-1))-1]<<endl;
	fz0k(i,(1<<(n-1))){
		printf("%I64d ",ans[i]);
	}
	return 0;
}