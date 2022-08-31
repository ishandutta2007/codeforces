#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
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
int mod;
long long _,g[105][55];
int f[105][55],n,m,k,i,j;
int c[105][105];
int lg(int x)
{
	int s=1,t=1;
	while(s<x){
		s<<=1;t++;
	}
	return t;
}
int main()
{
	read(n);read(m);read(k);read(mod);_=1ll*mod*mod;
	c[0][0]=1;fz1(i,102){c[i][0]=1;fz1(j,i)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;}
	if(k*2-1>n-max(0,m-1-lg(k))){puts("0");return 0;}
	f[1][1]=1;f[0][0]=1;
	fz(i,2,n) f[i][1]=1ll*f[i-1][1]*i%mod;
	fz1(i,m-1){
		memset(g,0,sizeof(g));
		f[0][0]=1;
		int a,b,c,d;
		fz0g(a,n)fz0g(b,k)if(f[a][b]){
			fz0g(c,n-a-1)fz0g(d,k-b)if(f[c][d]){
				g[a+c+1][b+d]=(g[a+c+1][b+d]+((long long)f[a][b])*f[c][d]%mod*::c[a+c][a]);
				if(g[a+c+1][b+d]>=_)g[a+c+1][b+d]-=_;
			}
		}
		fz0g(a,n)fz0g(b,k) f[a][b]=(g[a][b]%mod);
	}
	cout<<f[n][k]<<endl;
	return 0;
}