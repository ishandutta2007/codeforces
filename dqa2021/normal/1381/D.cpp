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

int n,S,T,W;
vector<int> e[100010];
bool mrk[100010];

int maxd[100010],dep[100010];
int gnd[17][100010];
int dfn[100010],id[100010],siz[100010];

void dfs0(int x,int f,int d){
	dfn[++*dfn]=x,id[x]=++*id,siz[x]=1;
	gnd[0][x]=f;
	rep(j,1,16) gnd[j][x]=gnd[j-1][gnd[j-1][x]];
	maxd[x]=d; dep[x]=d; if (x==T) W=d-1;
	for (int y: e[x]){
		if (y==f) continue;
		dfs0(y,x,d+1);
		siz[x]+=siz[y];
		maxd[x]=max(maxd[x],maxd[y]);
	}
}
void dfs1(int x,int f,int L){
	int tot=L>=W;
	for (int y: e[x]){
		if (y==f) continue;
		if (maxd[y]-dep[x]>=W) tot++;
	}
	mrk[x]=tot>=3;
	int fi=L,se=0;
	for (int y: e[x]){
		if (y==f) continue;
		int t=maxd[y]-dep[x];
		if (t>fi) se=fi,fi=t;
		else if (t>se) se=t;
	}
	for (int y: e[x]){
		if (y==f) continue;
		int t=maxd[y]-dep[x];
		if (t==fi) dfs1(y,x,se+1);
		else dfs1(y,x,fi+1);
	}
}
int getlca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int t=dep[x]-dep[y];
	rep(j,0,16) if (t>>j&1) x=gnd[j][x];
	if (x==y) return x;
	per(j,0,16)
		if (gnd[j][x]^gnd[j][y])
			x=gnd[j][x],y=gnd[j][y];
	return gnd[0][x];
}
int jump(int x,int t){
	rep(j,0,16) if (t>>j&1) x=gnd[j][x];
	return x;
}
int getkth(int x,int y,int k){
	int l=getlca(x,y);
	assert(k<=dep[x]+dep[y]-2*dep[l]);
//	printf("test getkth %d %d  %d\n",x,y,k);
	if (k<=dep[x]-dep[l]) return jump(x,k);
	return jump(y,dep[x]+dep[y]-2*dep[l]-k);
}

struct C{
	int o,x,y;  //0: hd tl; 1: tl hd
}que[200010]; int hd,tl;
bool dp[2][100010];

set<int> st[2];

void work(const C &v,int l,int r){
//	printf("test %d %d %d:  %d %d\n",v.o,v.x,v.y,l,r);
	auto fst=st[v.o^1].lower_bound(l);
	auto lst=st[v.o^1].upper_bound(r);
	for (auto it=fst;it!=lst;++it){
		int x=dfn[*it];
//		printf("  find %d",x);
//		printf("  %d\n",getkth(x,v.x,W));
		dp[v.o^1][x]=1;
		que[++tl]=(C){v.o^1,x,getkth(x,v.x,W)};
	}
	st[v.o^1].erase(fst,lst);
}

void solve(){  //init
	n=read(),S=read(),T=read();
	
	st[0].clear(),st[1].clear();
	hd=tl=0;
	rep(i,1,n){
		e[i].clear(),mrk[i]=0;
		rep(j,0,16) gnd[j][i]=0;
		dp[0][i]=dp[1][i]=0;
	}
	*dfn=*id=0;
	
	rep(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs0(S,0,1); dfs1(S,0,0);
//	rep(i,1,n) printf("dfn %d = %d\n",i,dfn[i]);
	que[++tl]=(C){0,S,T}; que[++tl]=(C){1,T,S};
	dp[0][S]=dp[1][T]=1;
	rep(i,1,n) st[0].insert(i),st[1].insert(i);  //dfn
	st[0].erase(id[S]),st[1].erase(id[T]);
	while (hd<tl){
		const C &v=que[++hd];
		if (id[v.y]<=id[v.x]&&id[v.x]<id[v.y]+siz[v.y]){
			int z=jump(v.x,dep[v.x]-dep[v.y]-1);
			work(v,1,id[z]-1);
			work(v,id[z]+siz[z],n);
		}
		else{
			work(v,id[v.y],id[v.y]+siz[v.y]-1);
		}
	}
	rep(i,1,n) if (mrk[i]&&(dp[0][i]||dp[1][i])) return puts("YES"),void();
	puts("NO");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}