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
const int mod=1e9+7;
int n,m,p,i,j,k,l,x,fac[105],inv[105],fi[105],dp[55][55][55][105],ans;
int c(int x,int y)
{
	return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;
}
int main()
{
	fac_init(100)
	read(n);read(m);read(p);
	n/=2;
	fz1(i,n) dp[i][i][1][1]=1;
	fz1(i,n){
		fz1(j,n){
			fz1(k,min(n,m)){
				fz1(l,p){
					if(!dp[i][j][k][l]) continue;
					ans=(ans+1ll*(m-k)*dp[i][j][k][l])%mod;
					fd1(x,n-i){
						if(1ll*l*c(j+x-1,x)<=p){
							inc(dp[i+x][x][k+1][l*c(j+x-1,x)],dp[i][j][k][l])
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}