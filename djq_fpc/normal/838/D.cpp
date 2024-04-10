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
const int mod=1e9+7;
int n,m,i,j;
int qp(int x,int y)
{
	int z=1;
	while(y){
		if(y&1)z=1ll*z*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return z;
}
int main()
{
	read(n);read(m);
	cout<<1ll*qp(2,m)*(n-m+1)%mod*qp(n+1,m-1)%mod<<endl; 
	return 0;
}
/*int n,m,i,j,ans[10],vis[10];
void dfs(int x)
{
	ans[x-1]++;
	if(x>n){
		return;
	}
	int i,j;
	fz1(i,n){
		j=i;while(vis[j])j++;
		if(j<=n){
			vis[j]=1;
			dfs(x+1);
			vis[j]=0; 
		}
	}
	fz1(i,n){
		j=i;while(vis[j])j--;
		if(j>0){
			vis[j]=1;
			dfs(x+1);
			vis[j]=0; 
		}
	}
}
int main()
{
	fz1(n,6){
		memset(ans,0,sizeof(ans));
		dfs(1);
		int t=1;
		fz1(i,n){
			printf("%d ",ans[i]/t);
			t*=(n+1);
		}
		puts("");
	}
	return 0;
}*/