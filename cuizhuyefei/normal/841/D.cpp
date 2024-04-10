#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 300004;
int n,m,d[N],u[N],v[N],s[N],ans;

int head[N],edgenum=1;
struct Edge {
	int to,nxt,ans;
} edge[N<<1];
inline void add(int u, int v, int k) {
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	edge[edgenum].ans=k;
	head[u]=edgenum;
}

int f[N];
inline int find(int x){
	if (f[x]==x) return x;
	f[x]=find(f[x]); return f[x];
}
inline bool merge(int k, int x, int y) {
	int fx=find(x),fy=find(y);
	if (fx==fy) return 0;
	f[fx]=fy; add(x,y,k); add(y,x,k);
	return 1;
}

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int x=-1,Fa[N],val[N]; //val:cha fen
void dfs(int u, int fa) {
	Fa[u]=fa;
	if (d[u]==1&&x>0) {
		d[u]=0;
		val[x]++; val[u]++;
		val[find(x)]--;
		x=-1;
	} // "/ \" //
	L(i,u) if (edge[i].to!=fa) {
		int v=edge[i].to; dfs(v,u);
		// '/'
		if (d[u]==1&&x>0) {
			d[u]=0;
			val[x]++; val[u]--;
			x=-1;
		}
		f[v]=u;
	}
	if (d[u]==1&&x==-1) x=u;
}
/*void dfs1(int u, int fa, int e) {
	L(i,u) if (edge[i].to!=fa) {
		dfs1(edge[i].to,u,edge[i].ans);
		val[u]+=val[edge[i].to]; val[u]%=2;
	}
	if (val[u]&1) s[++ans]=e;
}*/
void dfs(int u, int fa, int e) {
	L(i,u) if (edge[i].to!=fa) {
		dfs(edge[i].to,u,edge[i].ans); 
		val[u]=(val[u]+val[edge[i].to])%2;
	}
	if (val[u]&1) s[++ans]=e;
}
bool judge() {
	bool exi=0;
	int cnt=0;
	rep(i,1,n) {
		if (d[i]==1) cnt++;
		if (d[i]==-1) exi=1;
	}
	if ((cnt&1) && (!exi)) return 0;
	int size=n;
	rep(i,1,n) f[i]=i;
	rep(i,1,m) {
		if (merge(i,u[i],v[i])) size--; //!!!!!!!!!!!!!!
		if (size==1) break;
	}
//	ans=(cnt+1)>>1;
	if (cnt&1) rep(i,1,n) if (d[i]==-1) {d[i]=1; break;}
	rep(i,1,n) if (d[i]==1) val[i]=1;
	dfs(1,-1,0);
//	rep(i,1,n) f[i]=i;
//	dfs(1,-1);
//	dfs1(1,-1,0);
	//
	return 1;
}
int main() {
//	freopen("1.in","r",stdin); /////////
	read(n); read(m);
	rep(i,1,n) read(d[i]);
	rep(i,1,m) {read(u[i]); read(v[i]);}
	if (!judge()) puts("-1");
	else {
		printf("%d\n",ans);
		rep(i,1,ans)
			printf("%d\n",s[i]);
	}
	return 0;
} // in order as they are given in the input