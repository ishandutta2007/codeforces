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

const int N=410,P=1e9+7;

int n,m;
ll qpow(ll x,ll k=P-2){
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}
int C[N][N],F[N],D[N],I[N],J[N];
int dp[N][N];

int main(){
	n=rd(),m=rd();
	rep(i,0,N-1) rep(j,*C[i]=1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	I[0]=I[1]=J[0]=J[1]=1;
	rep(i,2,N-1) {
		J[i]=1ll*J[i-1]*i%P;
		I[i]=1ll*(P-P/i)*I[P%i]%P;
	}
	D[0]=1;
	rep(i,1,min(m*2,n)) D[i]=1ll*D[i-1]*(n-i+1)%P*I[i]%P;
	rep(i,1,N-1) I[i]=1ll*I[i-1]*I[i]%P;
	dp[0][0]=1;
	rep(i,0,m) rep(j,0,i*2) if(dp[i][j]) rep(k,1,m-i) {
		// k+1
		// C[j+k+1][j] 
		// J[k] 
		dp[i+k][j+k+1]=(dp[i+k][j+k+1]+1ll*dp[i][j]*C[j+k][j]%P*J[k])%P;
	}
	rep(i,0,m) rep(j,0,i*2) if(dp[i][j]) {
		//cout<<"$"<<i<<' '<<j<<' '<<dp[i][j]<<' '<<D[j]<<endl;
		F[i]=(F[i]+1ll*D[j]*dp[i][j])%P;
	}
	rep(i,2,m) F[i]+=F[i-2],Mod1(F[i]);
	rep(i,1,m) printf("%d ",F[i]);
}