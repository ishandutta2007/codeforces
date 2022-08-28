//My rating is 1064.
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
const int mod=998244353;
int n,m,i,j,fac[4045],inv[4045],fi[4045],ans;
int c(int x,int y){return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;}
int f(int x,int y){return c(x+y,x);}
int main()
{
	fac_init(4042)
//	freopen("magic.in","r",stdin);
//	freopen("magic.out","w",stdout);
	read(n);read(m);
	fz1(i,m-1){
		int sum=0;
		fz1(j,n-1){
			sum=(sum+1ll*f(i,j-1)*f(i-1,n-j))%mod;
			ans=(ans+2ll*f(m-i-1,j)*f(m-i,n-j-1)%mod*sum)%mod;
		}
	}
	swap(n,m);
	fz1(i,m-1){
		int sum=0;
		fz1(j,n-1){
			ans=(ans+2ll*f(m-i-1,j)*f(m-i,n-j-1)%mod*sum)%mod;
			sum=(sum+1ll*f(i,j-1)*f(i-1,n-j))%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}