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

const int N=2010,P=998244353;

int n;
int A[N],B[N];
int F[N],G[N][N];
ll qpow(ll x,ll k=P-2) {
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

struct BIT{
	int s[N];
	void clear(){ memset(s,0,sizeof s); }
	void Add(int p,int x) { while(p<=n) s[p]+=x,p+=p&-p; }
	int Que(int p) {
		int res=0;
		while(p) res+=s[p],p-=p&-p;
		return res;
	}
	int Que(int l,int r){ return Que(r)-Que(l-1); }
} T,T2;
int X[N],Y[N];
void Add(int &x,ll y){ x=(x+y)%P; }

int main(){
	n=rd(),F[0]=F[2]=1;
	rep(i,3,n) F[i]=1ll*(i-1)*(F[i-1]+F[i-2])%P;
	//puts("\n---");
	//rep(i,1,n) cout<<F[i]<<' ';
	//puts("");
	drep(t,n-1,0) {
		if(t<n-1) rep(i,1,n) X[i]=1;
		rep(i,1,n) Y[i]=1;
		T.clear(),T2.clear();
		rep(i,1,n) T2.Add(i,1);
		rep(i,1,n) if(X[i] && Y[i]) T.Add(i,1);
		int w=qpow(F[n],t);
		rep(i,1,n) {
			if(X[A[i]] && Y[A[i]]) T.Add(A[i],-1);
			X[A[i]]=0;
			
			B[i]=rd();
			int c=T2.Que(B[i]-1)-(A[i]<B[i] && Y[A[i]]);
			int all=T.Que(n),d=T.Que(B[i]-1);
			if(c-d) {
				//cout<<"Add# "<<t<<' '<<i<<' '<<c-d<<' '<<all<<endl;
				Add(G[n-i-all][all],1ll*w*(c-d));
			}
			if(d) {
				//cout<<"Add% "<<t<<' '<<i<<' '<<d<<' '<<all-1<<endl;
				Add(G[n-i-all+1][all-1],1ll*w*d);
			}
			
			if(X[B[i]] && Y[B[i]]) T.Add(B[i],-1);
			T2.Add(B[i],-1),Y[B[i]]=0;
		}
		swap(A,B);
	}
	drep(i,n,1) rep(j,0,n-i) {
		G[i-1][j]+=G[i][j],Mod1(G[i-1][j]); // let A[i]=i
		G[i-1][j+1]+=G[i][j],Mod1(G[i-1][j+1]); // let A[i]!=i
	}
	int ans=0;
	rep(i,0,n) ans=(ans+1ll*F[i]*G[0][i])%P;
	printf("%d\n",ans);
}