#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 305
#define ll long long 
#define mo 998244353
using namespace std;

int n,i,j,k;
int em,e[maxn*2],nx[maxn*2],ls[maxn];
ll ans,f[maxn][maxn],g[maxn][maxn];

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

int r;
ll f0[maxn],g0[maxn],s[maxn];
void dfs(int x,int p){
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p) dfs(e[i],x);
	f[x][0]=g[x][0]=1;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p){
		int y=e[i];
		for(int j=r+1;j>=1;j--)
			f[y][j]=f[y][j-1],g[y][j]=g[y][j-1];
		f[y][0]=g[y][0]=0;
		memset(f0,0,sizeof(ll)*(r+2));
		memset(g0,0,sizeof(ll)*(r+2));
		s[0]=g[y][0];for(int k=1;k<=r+1;k++) s[k]=(s[k-1]+g[y][k])%mo;
		for(int j=0;j<=r;j++) {
			(f0[j]+=f[x][j]*s[r-j])%=mo;
			(g0[j]+=g[x][j]*s[j])%=mo;
		}
		s[0]=g[x][0];for(int k=1;k<=r+1;k++) s[k]=(s[k-1]+g[x][k])%mo;
		for(int j=0;j<=r;j++) {
			(f0[j]+=f[y][j]*s[r-j])%=mo;
			if (j) (g0[j]+=g[y][j]*s[j-1])%=mo;
		}
		
		s[r+1]=f[y][r+1];for(int k=r;k>=0;k--) s[k]=(s[k+1]+f[y][k])%mo;
		for(int j=0;j<=r+1;j++) {
			(g0[j]+=g[x][j]*s[max(r-j+1,0)])%=mo;
			(f0[j]+=f[x][j]*s[j])%=mo;
		}
		s[r+1]=f[x][r+1];for(int k=r;k>=0;k--) s[k]=(s[k+1]+f[x][k])%mo;
		for(int j=0;j<=r+1;j++) {
			(g0[j]+=g[y][j]*s[max(r-j+1,0)])%=mo;
			if (j<=r) (f0[j]+=f[y][j]*s[j+1])%=mo;
		}
		
//		for(int j=0;j<=r+1;j++) for(int k=0;k<=r+1;k++){
//			if (j+k<=r) {
//				(f0[j]+=f[x][j]*g[y][k])%=mo;
//				(f0[k]+=g[x][j]*f[y][k])%=mo;
//			} else {
//				(g0[j]+=g[x][j]*f[y][k])%=mo;
//				(g0[k]+=f[x][j]*g[y][k])%=mo;
//			}
//			(f0[min(j,k)]+=f[x][j]*f[y][k])%=mo;
//			(g0[max(j,k)]+=g[x][j]*g[y][k])%=mo;
//		}
		memcpy(f[x],f0,sizeof(ll)*(r+2));
		memcpy(g[x],g0,sizeof(ll)*(r+2));
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++) scanf("%d%d",&j,&k),insert(j,k);
	ans=n*ksm(2,n)%mo;
	for(r=0;r<=n;r++) {
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		dfs(1,0);
		for(i=0;i<=r;i++) ans-=f[1][i];
	}
	printf("%lld\n",(ans%mo+mo)%mo*ksm(ksm(2,n),mo-2)%mo);
}