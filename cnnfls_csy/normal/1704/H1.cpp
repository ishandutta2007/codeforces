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
int mod;
int qp(int x,int y){int z=1;while(y){if(y&1){z=1ll*z*x%mod;}x=1ll*x*x%mod;y/=2;}return z;}
int fac[500005],inv[500005],fi[500005];
int binom(int x,int y){return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;}
int n,m,i,j;
int f[5005][5005];
int s[5005][5005];
int main()
{
	read(n);read(mod);fac_init(500002);
	f[0][0]=1;
	fz1(i,n){
		s[i-1][0]=f[i-1][0];
		fz1(j,n) s[i-1][j]=(s[i-1][j-1]+f[i-1][j])%mod;
		fz(j,2,n){
			f[i][j]=1ll*(n-1)*s[i-1][j-2]%mod;
		}
	}
	int ans=0;
	fz0g(i,n){
		fz0g(j,n)if(f[j][n-i]){
			ans=(ans+1ll*f[j][n-i]*fac[n]%mod*fi[i]%mod*qp(n-i-j,i)%mod*fi[j])%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}