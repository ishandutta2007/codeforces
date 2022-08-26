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
#define fzjn fz1(k,n)
#define fzjm fz1(k,m)
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
const int mod=1e9+7;
int qp(int x,int y){int z=1;while(y){if(y&1)z=1ll*z*x%mod;y>>=1;x=1ll*x*x%mod;}return z;}
int n,m,i,j,k,a[605],pw[605],c0,ans;
int suf[2][605],pre[2][605];
int f[2][605],g[2][605],h[605];
bool cmp(int x,int y){return abs(x)>abs(y);}
int main()
{
	pw[0]=1;fz1(i,602) pw[i]=2ll*pw[i-1]%mod;
	read(n);read(m);fz1(i,n)read(a[i]);sort(a+1,a+n+1,cmp);
	while(n>=1&&!a[n])n--,c0++;if(!n){puts("0");return 0;}
	fz1(i,n){
		pre[0][i]=pre[0][i-1];pre[1][i]=pre[1][i-1];
		pre[a[i]<0][i]++;
	}
	fd1(i,n){
		suf[0][i]=suf[0][i+1];suf[1][i]=suf[1][i+1];
		suf[a[i]<0][i]++;
	}
	f[0][0]=1;
	fz1(i,n){
		bool sgn=(a[i]<0);
		ans=(ans+1ll*pw[n-i+c0]*f[sgn][m-1]%mod*a[i])%mod;
		ans=(ans+1ll*f[!sgn][m-1]%mod*a[i])%mod;
		fd1(k,m){
			g[0][k]=f[sgn][k-1];
			g[1][k]=f[!sgn][k-1];
		}
		fz(j,i+1,n)if((a[j]<0)!=sgn){
			int x,y=j+1;
			fz(x,j+1,n)if((a[x]<0)!=sgn){
				while(y<=n&&abs(1ll*a[x]*a[j])<=abs(1ll*a[i]*a[y])) y++;
				ans=(ans+1ll*g[sgn][m-1]*a[j]%mod*a[x]%mod*pw[suf[sgn][y]+suf[!sgn][x+1]+c0])%mod;
			}
			y=j+1;
			fz(x,j+1,n)if((a[x]<0)==sgn){
				while(y<=n&&abs(1ll*a[x]*a[i])<abs(1ll*a[j]*a[y])) y++;
				ans=(ans+1ll*g[sgn][m-1]*a[i]%mod*a[x]%mod*pw[suf[!sgn][y]+suf[sgn][x+1]+c0])%mod;
			}
			fd1(k,m){
				g[0][k]=(g[0][k]+1ll*a[j]*g[!sgn][k-1])%mod;
				g[1][k]=(g[1][k]+1ll*a[j]*g[sgn][k-1])%mod;
			}
		}
		fd1(k,m){
			f[0][k]=(f[0][k]+1ll*a[i]*f[sgn][k-1])%mod;
			f[1][k]=(f[1][k]+1ll*a[i]*f[!sgn][k-1])%mod;
		}
	}
	if(m&1){
		memset(h,0,sizeof(h));h[0]=1;
		fd1(i,n)if(a[i]<0){
			ans=(ans+1ll*h[m-1]*a[i]%mod*(pw[pre[1][i-1]]-1))%mod;
			fd1(j,m) h[j]=(h[j]+1ll*h[j-1]*a[i])%mod;
		}
		memset(h,0,sizeof(h));h[0]=1;
		fz1(i,n)if(a[i]<0){
			fz(j,i+1,n)if(a[j]>0){
				ans=(ans+1ll*h[m-1]*a[j]%mod*(pw[suf[1][i+1]+suf[0][j+1]+c0]))%mod;
			}
			fd1(j,m) h[j]=(h[j]+1ll*h[j-1]*a[i])%mod;
		}
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}