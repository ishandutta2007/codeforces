#include<bits/stdc++.h>
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
#define reg register
#define pb push_back
#define mp make_pair
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,const T &b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,const T &b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,K=19,P=998244353;

int n,m,k;
ll qpow(ll x,ll k=P-2){
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}
ll d[60],e[60],dp[60],w[60][60],C[60][60];
namespace Enum{
	ll d[60],c;
	ll s[1<<14],t[1<<14];
	void Solve(ll *D){
		rep(i,0,m-1) if(D[i]) d[c++]=D[i];
		int m=c/2;
		rep(i,0,(1<<m)-1) rep(j,0,m-1) if(i&(1<<j)) s[i]^=d[j];
		rep(i,0,(1<<(c-m))-1) rep(j,m,c-1) if(i&(1<<(j-m))) t[i]^=d[j];
		int A=(1<<m)-1;
		rep(i,0,(1<<c)-1) dp[__builtin_popcountll(s[i&A]^t[i>>m])]++;
	}
}

int key[60],nonkey[60],c;

int main(){
	rep(i,0,56) rep(j,C[i][0]=1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	n=rd(),m=rd();
	rep(t,1,n) {
		ll x=rd<ll>();
		drep(i,m-1,0) if(x&(1ll<<i)) {
			if(!d[i]) {
				d[i]=x;
				n--,k++;
				break;
			} else x^=d[i];
		}
	}
	memset(key,-1,sizeof key);
	drep(i,m-1,0) if(d[i]) {
		drep(j,i-1,0) if(d[i]&(1ll<<j)) d[i]^=d[j];
	}
	c=k=0;
	rep(i,0,m-1) if(d[i]) {
		k++;
		e[m-k]|=1ll<<(m-k);
		rep(j,0,i-1) if(d[i]&(1ll<<j)) {
			if(key[j]==-1) key[j]=c++;
			e[m-k]|=1ll<<key[j];
		}
	}
	/*rep(i,0,m-1) {
		rep(j,0,m-1) cout<<((d[i]>>j)&1);
		puts("");
	}
	puts("------");
	rep(i,0,m-1) {
		rep(j,0,m-1) cout<<((e[i]>>j)&1);
		puts("");
	}*/
	memset(d,0,sizeof d),swap(d,e);
	n=qpow(2,n);
	if(k<=26){
		Enum::Solve(d);
		rep(i,0,m) printf("%d ",dp[i]*n%P);
		return 0;
	}
	drep(i,m-1,0) {
		if(!d[i]) e[i]|=1ll<<i;
		drep(j,i-1,0) if(d[i]&(1ll<<j)) e[j]|=1ll<<i;
	}
	Enum::Solve(e);


	rep(i,0,m) rep(j,0,m) {
		rep(k,0,min(i,j)) w[i][j]=(w[i][j]+C[j][k]*C[m-j][i-k]*(k&1?-1:1))%P;
		Mod2(w[i][j]);
	}
	//rep(i,0,m) cout<<dp[i]<<' '; puts("");
	// F^c * B
	n=n*qpow((P+1)/2,m-k)%P;
	rep(i,0,m) {
		ll ans=0;
		rep(j,0,m) ans=(ans+dp[j]*w[i][j])%P;
		printf("%lld ",ans*n%P);
	}
}