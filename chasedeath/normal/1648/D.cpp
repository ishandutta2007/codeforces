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
const int N=5e5+10,INF=1e9+10;
const ll LINF=1e18;

int n,q;
ll A[N],B[N],C[N];
struct Node{
	ll s,a,b;
	Node operator + (const Node __) const {
		Node res;
		res.a=max(a,__.a);
		res.b=max(b,__.b);
		res.s=max(a+__.b,max(s,__.s));
		return res;
	}
};
vector <Pii> G[N];
ll dp[N];

struct BIT{
	Node s[N];
	void Init() {
		rep(i,1,n) s[i]=(Node){-LINF,-LINF,-LINF};
	}
	void Upd(int p) {
		Node t=(Node){dp[p]+C[p],max(dp[p],A[p+1]-B[p]),C[p]};
		p=n-p;
		while(p<=n) s[p]=s[p]+t,p+=p&-p;
	}
	Node Que(int p) {
		p=n-p;
		Node res=(Node){-LINF,-LINF,-LINF};
		while(p) res=res+s[p],p-=p&-p;
		return res;
	}
} T;

bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	n=rd(),q=rd();
	rep(i,1,n) A[i]=rd()+A[i-1];
	rep(i,1,n) B[i]=rd()+B[i-1];
	rep(i,1,n) C[i]=rd();
	drep(i,n,1) C[i]+=C[i+1];
	rep(i,1,n) C[i]+=B[i];
	while(q--) {
		int l=rd(),r=rd(),k=rd();
		G[r].pb(mp(l,k));
	}
	T.Init();
	ll ans=-LINF;
	dp[0]=-LINF;
	rep(i,1,n) {
		T.Upd(i-1),dp[i]=-LINF;
		for(auto [l,k]:G[i]) {
			Node t=T.Que(l-1);
			cmax(t.s,t.a+C[i]);
			//cout<<"#"<<l<<' '<<i<<' '<<k<<' '<<t.s<<endl;
			cmax(ans,t.s-k);
			cmax(dp[i],t.a-k);
		}
	}
	printf("%lld\n",ans);
}