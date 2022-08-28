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
const int mod=998244353;
int n,m,i,j,a[7],b[7];
int dp[35][21][21][21][21][4];
int main()
{
	read(n);read(m);fz0k(i,n)read(a[i]),read(b[i]);
	dp[0][0][0][0][0][0]=1;
	int w,a,b,c,d,lim;
	fz0k(w,30){
		fz0g(a,n*4)fz0g(b,n*4)fz0g(c,n*4)fz0g(d,n*4){
			fz0k(lim,4)if(dp[w][a][b][c][d][lim]){
				fz0k(i,(1<<n)){
					int na=a,nb=b,nc=c,nd=d;
					fz0k(j,n)if((i>>j)&1){
						na+=(::a[j]>0?::a[j]:0);
						nc-=(::a[j]<0?::a[j]:0);
						nb+=(::b[j]>0?::b[j]:0);
						nd-=(::b[j]<0?::b[j]:0);
					}
					if(na%2!=nc%2)continue;
					if(nb%2!=nd%2)continue;
					int t=((m>>w)&1);
					int nlima=(lim&1),nlimb=(lim&2);
					if(na%2>t) nlima=1;
					if(na%2<t) nlima=0;
					if(nb%2>t) nlimb=2;
					if(nb%2<t) nlimb=0;
					int nlim=nlima+nlimb;
					na/=2;
					nb/=2;
					nc/=2;
					nd/=2;
					(dp[w+1][na][nb][nc][nd][nlim]+=dp[w][a][b][c][d][lim])%=mod;
				}
			}
		}
	}
	cout<<(dp[30][0][0][0][0][0]-1+mod)%mod<<endl;
	return 0;
}