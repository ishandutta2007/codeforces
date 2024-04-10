#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,k;
vector<int> e[400010];

int f[400010];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
void merge(int x,int y){
	x=find(x),y=find(y);
	if (x^y) f[y]=x;
}
bool check(int x,int y){
	if (!x||!y) return 0;
	return find(x)==find(y);
}

int c[400010],d[400010];
void bfs(const vector<int> &S){
	static int que[400010],hd,tl;
	
	rep(i,1,n) d[i]=1e9;
	for (int x: S) d[x]=0,c[x]=x,que[++tl]=x;
	while (hd<tl){
		int u=que[++hd];
//		printf("test mrk %d by %d dis %d\n",u,c[u],d[u]);
		if (d[u]==k) continue;
//		puts("test");
		for (int v: e[u]){
			if (d[v]==1e9) d[v]=d[u]+1,c[v]=c[u],que[++tl]=v;
			else merge(c[u],c[v]);
		}
	}
}

int gnd[19][400010],dep[400010];
void dfs(int x,int f,int d){
	gnd[0][x]=f; dep[x]=d;
	for (int j=1;j<19&&gnd[j-1][x];++j) gnd[j][x]=gnd[j-1][gnd[j-1][x]];
	for (int y: e[x]){
		if (y==f) continue;
		dfs(y,x,d+1);
	}
}

int jump(int x,int d){
	rep(i,0,18) if (d>>i&1) x=gnd[i][x];
	return x;
}
int jump(int x,int y,int l,int d){
	if (dep[x]-dep[l]>=d) return jump(x,d);
	return jump(y,dep[y]-dep[l]-(d-dep[x]+dep[l]));
}
int getlca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	x=jump(x,dep[x]-dep[y]);
	if (x==y) return x;
	per(i,0,18) if (gnd[i][x]^gnd[i][y]) x=gnd[i][x],y=gnd[i][y];
	return gnd[0][x];
}

void solve(){
	int m=n=read(); k=read(); int tot=read();
	rep(i,1,n-1){
		int u=read(),v=read(),w=++m;
		e[u].pb(w),e[w].pb(u),e[w].pb(v),e[v].pb(w);
	}
	n=m;
//	rep(i,1,n) for (int j: e[i]) printf("%d - %d\n",i,j);
	vector<int> S;
	while (tot--) S.pb(read());
	bfs(S);
	dfs(1,0,1);
	int Q=read();
	while (Q--){
		int u=read(),v=read(),l=getlca(u,v);
		if (dep[u]+dep[v]-2*dep[l]<=k+k){puts("YES");continue;}
		puts(check(c[jump(u,v,l,k)],c[jump(v,u,l,k)])?"YES":"NO");
	}
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}