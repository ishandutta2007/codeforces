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

const int N=5010,P=998244353;

int n;
int F[N][N];
int S[N],I[N],J[N];
ll qpow(ll x,ll k=P-2) {
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

int main() {
	n=rd();
	rep(i,*J=1,n) J[i]=1ll*J[i-1]*i%P;
	I[n]=qpow(J[n]);
	drep(i,n,1) I[i-1]=1ll*I[i]*i%P;
	rep(i,**F=1,n) rep(j,1,i) {
		F[i][j]=(1ll*F[i-1][j]*j+1ll*(i-j+1)*F[i-1][j-1])%P;
		S[j]=(S[j]+1ll*F[i][j]*I[i])%P;
	}
	rep(i,1,n) printf("%d ",(int)(1ll*S[i]*J[n]%P));
}