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

const int N=3e5+10;

int n;
int A[N],F[N];
vector <int> G[N];
ll ans;
int X[N],Y[N],Z[N],C1,C2,C3,D[N];

int I[N],J[N];
void dfs1(int u){
	I[u]=A[u];
	for(int v:G[u]) D[v]=D[u]+1,dfs1(v),cmin(I[u],I[v]);
}
void dfs2(int u){
	J[X[u]=++C1]=u;
	sort(G[u].begin(),G[u].end(),[&](int x,int y){ return I[x]<I[y]; });
	for(int v:G[u]) dfs2(v);
	Y[u]=++C2;
}
int vis[N];
void dfs3(int u){
	if(vis[u]) return;
	Z[u]=++C3;
	for(int v:G[u]) dfs3(v);
}

int main(){
	n=rd();
	rep(i,1,n) A[i]=rd();
	int p=n+1; A[n+1]=n+1;
	rep(i,2,n) {
		int u=rd(),v=rd();
		G[u].pb(v),F[v]=u;
		if(A[u]<A[v] && A[p]>A[u]) p=u;
	}
	int f=1;
	//int val=A[p];
	if(p<=n) while(F[p]) {
		//puts("!");
		int f=F[p];
		// illgal
		//cout<<"Up"<<A[f]<<' '<<A[p]<<endl;
		if(A[f]<A[p]) return puts("NO"),0;
		swap(A[p],A[F[p]]);
		
		// not optimal
		if(F[f] && A[F[f]]<A[f]) return puts("NO"),0;
		for(int v:G[f]) if(A[v]>A[f] && A[v]<A[p]) return puts("NO"),0;
		//for(int v:G[p]) if(A[v]<A[p]) return puts("NO"),0;
		p=F[p],ans++;
	}
	//cout<<f<<endl;
	dfs1(1),dfs2(1);
	rep(i,1,n) if(A[i]<A[p]) f&=A[i]==Y[i],vis[i]=1,ans+=D[i];
	dfs3(1);
	rep(i,1,n) if(A[i]>=A[p]) f&=Z[i]+A[p]-1==A[i];
	//cout<<f<<endl;
	if(!f) puts("NO");
	else {
		//return 0;
		puts("YES");
		printf("%lld\n",ans);
		rep(i,1,n) printf("%d ",X[i]);
		puts("");
	}
}