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
int n,m,r,i,j,a[35][35],b[35],k[35],p[35];
long long ans=-0x3f3f3f3f3f3f3f3fll;
long long calc(int m)
{
	long long s=0;int i;
	fz1(i,n) s+=1ll*a[m][i]*k[i];
	return s;
}
void dfs(int x,int lst)
{
	if(x%2!=m%2) ans=max(ans,calc(x-1));
	if(x>m){
		return;
	}
	if(!lst){
		int i;
		fz1(i,n){
			a[x][i]=a[x-1][i]^b[i];
		}
		dfs(x+1,1);
	}
	fz1(i,n){
		a[x][i]=a[x-1][p[i]]+r;
	}
	dfs(x+1,0);
}
int main()
{
	read(n);read(m);read(r);
	fz1(i,n){
		read(a[0][i]);
	}
	fz1(i,n){
		read(b[i]);
	}
	fz1(i,n){
		read(k[i]);
	}
	fz1(i,n){
		read(p[i]);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}