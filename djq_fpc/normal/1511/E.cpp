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
const int mod=998244353,inv2=(mod+1)/2;
int n,m,i,j,ans,f[300005],r[300005];
char mp[300005];
int id(int x,int y)
{
	if(x<1||y<1) return 0;
	return (x-1)*m+y;
}
int main()
{
	f[0]=inv2;f[1]=0;
	for(i=2;i<=300000;i++){
		f[i]=1ll*inv2*inv2%mod*(1ll*(f[i-2]+inv2)%mod)%mod;
	}
	ios_base::sync_with_stdio(0);
	cin>>n>>m;fz1(i,n)fz1(j,m)cin>>mp[id(i,j)];
	fz1(i,n)fz1(j,m){
		if(mp[id(i,j)]=='o'){
			r[id(i,j)]=r[id(i-1,j)]+1;
			ans=(ans+f[r[id(i,j)]])%mod;
		}
	}
	fz1(i,n)fz1(j,m){
		if(mp[id(i,j)]=='o'){
			r[id(i,j)]=r[id(i,j-1)]+1;
			ans=(ans+f[r[id(i,j)]])%mod;
		}
	}
	fz1(i,n)fz1(j,m)if(mp[id(i,j)]=='o') ans=2ll*ans%mod;
	cout<<ans<<endl;
	return 0;
}