#include<bits/stdc++.h>
using namespace std;

using u64=uint64_t;
using i64=int64_t;
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

const int N=180;
const u64 P1=(u64)9e18+41,P2=(u64)9e18+53;

int n;
int U[N],V[N];
int I[N],J[N],W[N];
template <const u64 P> struct Calc{
	struct Num{
		u64 x;
		Num(){}
		Num(u64 x):x(x){ ; }
		Num(int y){ x=y<0?y+P:y; }
		Num& operator += (const Num _) { return x+=_.x,x>=P&&(x-=P),*this; }
		Num& operator -= (const Num _) { return x-=_.x,i64(x)<0&&(x+=P),*this; }
		Num& operator *= (const Num _) { return x=(__int128)x*_.x%P,*this; }
		Num operator + (const Num _) const { return Num(x)+=_; }
		Num operator - (const Num _) const { return Num(x)-=_; }
		Num operator * (const Num _) const { return Num(x)*=_; }
	} A[N][N];
	Num qpow(Num x){
		i64 k=P-2;
		Num res(1);
		for(;k;k>>=1,x*=x) if(k&1) res*=x;
		return res;
	}
	void Init(){
		rep(i,1,n) {
			rep(j,i,n*3) if(A[j][i].x>0) {
				swap(A[i],A[j]);
				break;
			}
			Num Inv=qpow(A[i][i]);
			//cout<<A[i][i].x<<' '<<Inv.x<<endl;
			rep(j,i,n*3) A[i][j]*=Inv;
			//cout<<A[i][i].x<<endl;
			//assert(A[i][i].x==1);
			rep(j,1,n) if(i!=j && A[j][i].x) drep(k,n*3,i) A[j][k]-=A[j][i]*A[i][k];
		}
		//puts("Gauss");
		//rep(i,1,n) {
			//rep(j,1,n*3) cout<<A[i][j].x<<' ';
			//puts("");
		//}
	}
	Num S[N];
	void Evaluate() {
		rep(i,1,n) {
			S[i]=0;
			rep(j,n+1,n*3) S[i]+=A[i][j]*W[j];
		}
	}
	i64 operator [] (const int x){ return S[x].x; }
};
Calc <P1> X; Calc <P2> Y;
void Add(int x,int y,int z){ X.A[x][y]+=z,Y.A[x][y]+=z; }
i64 P[N],Q[N];

char s[N];
int vis[N],mk[N];
void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	dfs(s[u]=='R'?V[u]:U[u]);
}

// W[i+n*2] : out -in 
// W[i+n  ] : red - blue

int main(){
	n=rd()-1;
	rep(i,1,n) {
		U[i]=rd(),V[i]=rd();
		//Add(i,i,2),Add(i,i+n,1),Add(i,i+n*2,1);
		//if(U[i]<=n) Add(U[i],i,-1);
		//if(V[i]<=n) Add(V[i],i,-1),Add(V[i],i+n,-1);
		Add(i,i,-2),Add(i,i+n,1),Add(i,i+n*2,-1);
		if(U[i]<=n) Add(U[i],i,1),Add(U[i],i+n,-1);
		if(V[i]<=n) Add(V[i],i,1);
	}
	//puts("!");
	X.Init(),Y.Init();
	rep(_,1,rd()) {
		int u=rd(); scanf("%s",s+1);
		rep(i,1,n*3) W[i]=0;
		W[1+n*2]++,W[u+n*2]--;
		rep(i,1,n) W[i+n]=-(s[i]=='R');
		X.Evaluate(),Y.Evaluate();
		//rep(i,1,n) cout<<X[i]<<' ';
		//puts("");
		//rep(i,1,n) cout<<Y[i]<<' ';
		//puts("");
		int f=1;
		rep(i,1,n) {
			memset(vis,0,(n+1)<<2);
			dfs(i);
			mk[i]=vis[u];
		}
		rep(i,1,n) {
			f&=X[i]==Y[i];
			f&=(X[i]==0)||mk[i];
			f&=(X[i]+W[i+n]>=0);
		}
		if(!f){ puts("-1"); continue; }
		u64 ans=0;
		rep(i,1,n) ans+=X[i]*2+W[i+n];
		cout<<ans<<endl;
		//printf("%llu\n",ans);
	}
}