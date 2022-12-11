#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y,e) for (const int &y: e[x])

int n;
vector<int> a[300010],b[300010];

int id[300010],idtot,siz[300010];

void dfs0(int x){
	id[x]=++idtot; siz[x]=1;
	forall(x,y,b) dfs0(y),siz[x]+=siz[y];
}

ll tri[300010];
ll t2[300010];

void add(int x,int w,ll *tri){
	for (;x<=n;x+=x&-x) tri[x]+=w;
}

int ask(int x,ll *tri){
	ll z=0;
	for (;x;x-=x&-x) z+=tri[x];
	return z;
}

int z,g;

void dfs1(int x){
	int w=0;
	if (ask(id[x]+siz[x]-1,t2)-ask(id[x]-1,t2)) w=-1;
	else{
		w=ask(id[x],tri);
		if (w){
			add(id[w],-w,tri); add(id[w]+siz[w],w,tri);
			//add(id[w],-1,t2);
			--z;
		}
		add(id[x],x,tri); add(id[x]+siz[x],-x,tri);
		add(id[x],1,t2);
		++z;
	}
	g=max(g,z);
	forall(x,y,a) dfs1(y);
	if (~w){
		add(id[x],-x,tri); add(id[x]+siz[x],x,tri);
		add(id[x],-1,t2);
		--z;
		if (w){
			add(id[w],w,tri); add(id[w]+siz[w],-w,tri);
			//add(id[w],1,t2);
			++z;
		}
	}
}

void solve(){
	n=read();
	rep(i,1,n) a[i].clear(),b[i].clear();
	rep(i,2,n) a[read()].pb(i);
	rep(i,2,n) b[read()].pb(i);
	idtot=0; dfs0(1);
	z=g=0; dfs1(1);
	printf("%d\n",g);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}