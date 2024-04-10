#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
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
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=60,INF=1e9+10;

int n,h,m;
int L[N],R[N],X[N],C[N];
int dp[N][N][N];
int S[N];

int main(){
	n=rd(),h=rd(),m=rd();
	rep(i,1,m) L[i]=rd(),R[i]=rd(),X[i]=rd(),C[i]=rd();
	rep(i,1,n) rep(j,0,h) {
		dp[i][i][j]=j*j;
		rep(k,1,m) if(L[k]==R[k] && L[k]==i && X[k]<j) dp[i][i][j]-=C[k];
	}
	drep(i,n,1) rep(j,i+1,n) {
		rep(k,i,j-1) {
			rep(d,0,h) S[d]=0;
			rep(d,1,m) if(i<=L[d] && L[d]<=k && k<R[d] && R[d]<=j) S[X[d]+1]+=C[d];
			rep(d,1,h) S[d]+=S[d-1];
			rep(a,0,h) rep(b,0,h) cmax(dp[i][j][max(a,b)],dp[i][k][a]+dp[k+1][j][b]-S[max(a,b)]);
		}
	}
	int ans=0;
	rep(i,0,h) cmax(ans,dp[1][n][i]);
	printf("%d\n",ans);
}