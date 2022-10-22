#include<bits/stdc++.h>
using namespace std;

typedef __int128 i128;
typedef long long ll;
typedef unsigned long long ull;
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

const int N=2e5+10,INF=1e9+10;

int n,m;
struct Edge{
	int to,nxt,a,b;
} e[N*4];
int head[N],ecnt=1;
void AddEdge(int u,int v,int a,int b) {
	e[++ecnt]=(Edge){v,head[u],a,b};
	head[u]=ecnt;
}
void Link(int u,int v,int a,int b){ AddEdge(u,v,a,b),AddEdge(v,u,a,b); }

int fa[N],fb[N];
void pre_dfs(int u,int f) {
	vector <int> son;
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to;
		if(v==f) continue;
		son.pb(v);
		fa[v]=e[i].a,fb[v]=e[i].b;
		pre_dfs(v,u);
	}
	head[u]=0;
	int cur=u;
	for(int v:son) {
		Link(cur,v,fa[v],fb[v]);
		Link(cur,++n,0,0),cur=n;
	}
}

struct Node{
	ll a,b;
	Node(){}
	Node(ll a,ll b):a(a),b(b){}
	int operator < (const Node __) const { return a<__.a || (a==__.a && b>__.b); }
	ll operator [] (const ll x){ return a*x+b; }
	Node operator - (const Node __) const { return Node(a-__.a,b-__.b); }
	Node operator + (const Node __) const { return Node(a+__.a,b+__.b); }
	i128 operator ^ (const Node __) const { return (i128)a*__.b-(i128)b*__.a; }
};

int vis[N*4],sz[N],ma,X,Y,I;
void FindRt(int n,int u,int f) {
	//cout<<"FindRt "<<u<<' '<<f<<' '<<e[f].to<<endl;
	sz[u]=1;
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to;
		if(i==f || vis[i]) continue;
		FindRt(n,v,i^1),sz[u]+=sz[v];
	}
	if(sz[u]<=n/2 && sz[u]>ma) ma=sz[u],X=u,Y=e[f].to,I=f;
	if(n-sz[u]<=n/2 && n-sz[u]>ma) ma=n-sz[u],X=u,Y=e[f].to,I=f;
}

ll da[N],db[N];
Node L[N*20]; int C;
void dfs(int u,int f) {
	//cout<<u<<' '<<f<<' '<<da[u]<<' '<<db[u]<<endl;
	L[++C]=Node(da[u],db[u]);
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to;
		if(vis[i] || v==f) continue;
		//cout<<"Go "<<i<<endl;
		da[v]=da[u]+e[i].a,db[v]=db[u]+e[i].b;
		dfs(v,u);
	}
}
int Convex(Node *S) {
	sort(L+1,L+C+1);
	int T=0;
	rep(i,1,C) {
		while(T>1 && ((L[i]-S[T])^(S[T-1]-S[T]))>=0) T--;
		S[++T]=L[i];
	}
	return T;
}

Node A[N],B[N],D[N*20];
int CA,CB,CD;

void Div(int n,int u) {
	//cout<<"Div "<<n<<' '<<u<<endl;
	if(n==1) return;
	ma=0,FindRt(n,u,0),vis[I]=vis[I^1]=1;
	//cout<<"Find "<<X<<' '<<Y<<' '<<I<<endl;
	C=0,da[X]=db[X]=0,dfs(X,Y),CA=Convex(A);
	//rep(i,1,C) cout<<L[i].a<<','<<L[i].b<<' ';
	//puts("");
	C=0,da[Y]=e[I].a,db[Y]=e[I].b,dfs(Y,X),CB=Convex(B);
	//rep(i,1,C) cout<<L[i].a<<','<<L[i].b<<' ';
	//puts("");
	Node Now=A[1]+B[1];
	//cout<<"Go "<<A[1].b<<' '<<B[1].b<<endl;
	//rep(i,1,CA) cout<<A[i].a<<','<<A[i].b<<' ';
	//puts("");
	//rep(i,1,CB) cout<<B[i].a<<','<<B[i].b<<' ';
	//puts("");
	D[++CD]=Now;
	int p1=2,p2=2;
	drep(i,CA,2) A[i]=A[i]-A[i-1];
	drep(i,CB,2) B[i]=B[i]-B[i-1];
	while(p1<=CA || p2<=CB) {
		if(p1<=CA && (p2>CB || (A[p1]^B[p2])<=0)) Now=Now+A[p1++];
		else Now=Now+B[p2++];
		D[++CD]=Now;
	}
	int x=X;
	//cout<<"Divson "<<n-sz[X]<<' '<<sz[X]<<endl;
	Div(n-sz[x],Y);
	//assert(sz[X]==t);
	Div(sz[x],x);
}

int main() {
	n=rd(),m=rd();
	rep(i,2,n) {
		int u=rd(),v=rd(),a=rd(),b=rd();
		Link(u,v,a,b);
	}
	pre_dfs(1,0),Div(n,1);
	rep(i,1,C=CD) L[i]=D[i];
	C=Convex(D);
	//puts("!");
	//rep(i,1,C) cout<<D[i].a<<' '<<D[i].b<<endl;
	reverse(D+1,D+C+1);
	rep(i,0,m-1) {
		while(C>1 && D[C-1][i]>=D[C][i]) C--;
		printf("%lld ",D[C][i]);
	}
}