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

bool Mbe;
const int N=2e5+10,M=2e5,INF=1e9+10,P=998244353;

int n,m,A[N];
struct BIT{
	int s[N],c[N];
	void Add(int p,int x) {
		c[p]+=x;
		while(p<=M) s[p]+=x,p+=p&-p;
	}
	int Que(int p) {
		int res=0;
		while(p) res+=s[p],p-=p&-p;
		return res;
	}
} T;

ll qpow(ll x,ll k=P-2) {
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

int I[N],J[N];

bool Med;
int main() {
	n=rd(),m=rd();
	rep(i,1,n) T.Add(rd(),1);
	rep(i,*J=1,n) J[i]=1ll*J[i-1]*i%P;
	I[n]=qpow(J[n]);
	drep(i,n,1) I[i-1]=1ll*I[i]*i%P;
	int ans=0,now=1;
	rep(i,1,M) if(T.c[i]>1) now=1ll*now*I[T.c[i]]%P;
	rep(i,1,min(n,m)) {
		int x=rd();
		ans=(ans+1ll*T.Que(x-1)*now%P*J[n-i])%P;
		int c=T.c[x];
		if(!c) break;
		T.Add(x,-1),now=1ll*now*c%P;
		if(n<m && i==n) ans++,Mod1(ans);
	}
	printf("%d\n",ans);
}