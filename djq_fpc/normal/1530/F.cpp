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
const int mod=31607;
int n,m,i,j,a[25][25],b[25][25],inv[31607],ans,c[25];
void dfs(int x,int coef)
{
	if(x>n){
		int i;
		fz1(i,n) coef=coef*(mod+1-c[i])%mod;
		ans=(ans+coef)%mod;return;
	}
	dfs(x+1,coef);
	int i;
	coef=(mod-coef)%mod;
	fz1(i,n){
		c[i]=c[i]*inv[b[x][i]]%mod;
		coef=coef*b[x][i]%mod;
	}
	dfs(x+1,coef);
	fz1(i,n){
		c[i]=c[i]*b[x][i]%mod;
	}
}
void solve(int coef)
{
	int i,j;
	fz1(i,n){
		c[i]=1;
		fz1(j,n) c[i]=c[i]*b[j][i]%mod;
	}
	dfs(1,coef);
}
int main()
{
	inv[1]=1;fz(i,2,mod-1)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod; 
	read(n);fz1(i,n)fz1(j,n){read(a[i][j]);a[i][j]=a[i][j]*inv[10000]%mod;}
	fz1(i,n)fz1(j,n) b[i][j]=a[i][j];
	solve(1);
	int coef=mod-1;
	fz1(i,n)fz1(j,n) if(i==j) {b[i][j]=1;coef=coef*a[i][j]%mod;} else b[i][j]=a[i][j];
	solve(coef);
	coef=mod-1;
	fz1(i,n)fz1(j,n) if(i+j==n+1) {b[i][j]=1;coef=coef*a[i][j]%mod;} else b[i][j]=a[i][j];
	solve(coef);
	coef=1;
	fz1(i,n)fz1(j,n) if(i==j||i+j==n+1) {b[i][j]=1;coef=coef*a[i][j]%mod;} else b[i][j]=a[i][j];
	solve(coef);
	cout<<(mod+1-ans)%mod<<endl;
	return 0;
}