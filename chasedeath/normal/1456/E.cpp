#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO; 
template <class T=ll> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=55,INF=1e9+10;

int n,k;
ll L[N],R[N],C[N];
ll dp[N][N][N][2][2][2][2];
ll dfs(int p,int l,int r,int f,int x,int g,int y){
	if(p==k) return r-l==1?0:1e18;
	ll &res=dp[p][l][r][f][x][g][y];
	if(~res) return res;
	res=dfs(p+1,l,r,f,0,g,0)+(l && r<=n && (x^y^((((f?R[l]:L[l])^(g?R[r]:L[r]))>>p)&1)))*C[p];
	rep(k,l+1,r-1) {
		ll t=(L[k]^R[k])>>p;
		if(!p) rep(j,0,1) cmin(res,dfs(p,l,k,f,x,j,0)+dfs(p,k,r,j,0,g,y));
		if(t>>1) { // L,R has some different bits before
			if((R[k]>>p)&1) cmin(res,dfs(p,l,k,f,x,1,1)+dfs(p,k,r,1,1,g,y));
			if((~L[k]>>p)&1) cmin(res,dfs(p,l,k,f,x,0,1)+dfs(p,k,r,0,1,g,y));
		}
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%lld%lld",L+i,R+i);
	rep(i,0,k-1) scanf("%lld",C+i);
	memset(dp,-1,sizeof dp);
	printf("%lld\n",dfs(0,0,n+1,0,0,0,0));
}