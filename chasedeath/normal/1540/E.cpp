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
const int N=310,INF=1e9+10,P=1e9+7;

int n,m,q;
int a[N],A[N][N],V[N][N],SV[N][N],C[N][N];
int F[N];
ll qpow(ll x,ll k=P-2){
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}
int D[N];
bitset <N> B[N],All;
struct Tree{
	int s[N],t[N];
	void clr(){ memset(t,0,(m+1)<<2); }
	void Build(){ rep(i,1,m) t[i]+=t[i-1],Mod1(t[i]),s[i]=t[i]-t[i&(i-1)],Mod2(s[i]); }
	void Add(int p,int x) {
		t[m]+=x,Mod1(t[m]);
		p++;
		while(p<=m) s[p]+=x,Mod1(s[p]),p+=p&-p;
	}
	int Que(int p) {
		int r=0;
		cmin(++p,m);
		if(p==m) return t[p];
		while(p) r+=s[p],Mod1(r),p-=p&-p;
		return r;
	}
} T[N];
int W[N][N],Inv[N][N],Pow1[N][1010],Pow2[N][1<<10];

void Make(){
	All.reset();
	rep(i,1,n) if(a[i]>0) D[i]=0,All[i]=1,All|=B[i];
	else D[i]=INF;
	m=0;
	rep(i,1,n) rep(j,1,n) if(D[j]==INF && All[j]) D[j]=i,All|=B[j];
	rep(i,1,n) if(D[i]<INF) cmax(m,D[i]);
	m++;
	rep(i,1,n) T[i].clr();
	rep(i,1,n) if(D[i]<INF) rep(j,1,n) W[i][j]=1ll*C[i][j]*Inv[j][D[i]]%P,T[j].t[D[i]+1]=(T[j].t[D[i]+1]+1ll*W[i][j]*(P+a[i]))%P;
	rep(i,1,n) T[i].Build();
}

bool Med;
int main() {
	n=rd();
	rep(i,1,n) {
		Inv[i][0]=1,Inv[i][1]=qpow(i);
		rep(j,2,n) Inv[i][j]=1ll*Inv[i][j-1]*Inv[i][1]%P;
	}
	rep(i,1,n) 	rep(j,*Pow1[i]=1,1000) Pow1[i][j]=1ll*Pow1[i][j-1]*i%P;
	rep(i,1,n) a[i]=rd();
	rep(i,1,n) rep(j,A[i][i]=1,rd()) A[i][rd()]=1;
	rep(i,1,n) rep(j,i+1,n) if(A[i][j]) B[j][i]=1;
	rep(i,1,n) rep(j,1,n) A[i][j]*=j;
	rep(i,1,n) drep(j,i-1,V[i][i]=1) {
		rep(k,j+1,i) V[i][j]=(V[i][j]+1ll*A[j][k]*V[i][k])%P;
		V[i][j]=V[i][j]*qpow(i-j)%P;
	}
	rep(i,1,n) rep(j,1,n) SV[i][j]=SV[i][j-1]+V[i][j],Mod1(SV[i][j]);
	rep(i,1,n) C[i][i]=1;
	rep(i,1,n) rep(j,1,i-1) rep(k,1,n) C[i][k]=(C[i][k]+1ll*(P-V[i][j])*C[j][k])%P;
	Make();
	rep(_,1,rd()) {
		int opt=rd();
		if(opt==2){
			int i=rd(),x=rd(); a[i]+=x;
			if(a[i]-x<=0 && a[i]>0) Make();
			else if(D[i]<INF && x) rep(j,1,n) T[j].Add(D[i],1ll*W[i][j]*x%P);
		} else {
			int k=rd(),l=rd(),r=rd();
			int ans=0;
			rep(j,1,n) ans=(ans+1ll*(SV[j][r]-SV[j][l-1]+P)*T[j].Que(k)%P*Pow1[j][k])%P;
				//rep(i,1,n) if(D[i]<=k) ans=(ans+1ll*w*C[i][j]%P*qpow(j,k-D[i])%P*(P+a[i]))%P;
			rep(i,l,r) if(D[i]>k) ans+=a[i],Mod2(ans);
			printf("%d\n",ans);
		}
	}
}