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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=1e9+7;
int t,n,m,k,i,j,ans,fac[1000005],inv[1000005],fi[1000005];
int qp(int x,int y){int z=1;while(y){if(y&1){z=1ll*z*x%mod;}x=1ll*x*x%mod;y/=2;}return z;}
int c(int x,int y)
{
	if(x<y||x<0||y<0)return 0;
	return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;
}
int main()
{
	fac_init(1000002);
	read(t);
	while(t--){
		read(n);read(m);m=n-m;read(k);
		if(m==0){
			cout<<1ll*n*k%mod<<endl;
			continue;
		}
		ans=0;
		fz0k(i,n){
			ans=(ans+1ll*i*k%mod*qp((mod+1)/2,n-i)%mod*c(n-i-1,m-1))%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}