#include<bits/stdc++.h>
#define pb emplace_back
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
typedef pair<ll,ll> P;
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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
const ll INF=1e18;

int n,m;
vector<P> e[100010];
int fat[100010],son[100010];
ll dis[100010];

void dfs0(int x,int f){
	fat[x]=f; son[x]=e[x].empty()?0:e[x].back().fi;
	for (const auto &[y,w]: e[x])
		dis[y]=dis[x]+w,dfs0(y,x);
}

P g[1<<23]; int gtop;
ll h[1<<23]; int htop;

struct C{
	C *f,*ch[2];
	ll cv;
	ll t;
	
	bool isroot(){return f->ch[0]!=this&&f->ch[1]!=this;}
	bool which(){return f->ch[1]==this;}
	void pushdown(){
		if (!~cv) return;
		ch[0]->cv=cv,ch[1]->cv=cv;
		ch[0]->t=cv,ch[1]->t=cv;
		cv=-1;
	}
	void rotate(){
		bool e=which()^1;
		C *y=f; f=y->f;
		if (!y->isroot()) f->ch[y->which()]=this;
		y->ch[e^1]=ch[e]; ch[e]->f=y;
		y->f=this; ch[e]=y;
	}
	void flash(){
		if (!isroot()) f->flash();
		pushdown();
	}
	void splay(){
		flash();
		while (!isroot())
			if (f->isroot()) rotate();
			else if (which()^f->which()) rotate(),rotate();
			else f->rotate(),rotate();
	}
	
	C* access(C*,const ll&);
}c[100010],*null;

C* C::access(C *z,const ll &b){
	splay(); pushdown();
	if (z!=null){
		//printf("(%lld, %lld] change %d from %d to %d\n",t+dis[this-c],b+dis[this-c],int(this-c),int(ch[1]-c),int(z-c));
		g[++gtop]=P(t+dis[this-c]+1,b+dis[this-c]);
		ch[1]=z;
	}
	if (f==null) return this;
	return f->access(this,b);
}

void print(ll T){
	if (T==ll(1e18)) printf("-1 ");
	else printf("%lld ",T);
	int tot=0;
	rep(i,1,htop) tot+=h[i]<T;
	printf("%d\n",tot);
}

void solve(){
	n=read(),m=read();
	rep(i,2,n){
		int u=read(),v=read(),d=read();
		e[u].pb(v,d);
	}
	dfs0(1,0);
	
	null=new C();
	*null=(C){null,{null,null},-1,0};
	rep(i,1,n) c[i]=*null,c[i].t=-dis[i];
	rep(i,2,n) c[i].f=c+fat[i];
	rep(i,1,n){
		if (!son[i]) continue;
		int j=son[i];
		c[i].ch[1]=c+j;
	}
	
	rep(i,1,m){
		int x=read(); ll t=read();
		C *v=c+x;
		v->access(null,t);
		v->splay();
		v->pushdown();
		v->ch[0]->t=v->ch[0]->cv=t;
	}
	
	sort(g+1,g+gtop+1);
	reverse(g+1,g+gtop+1);
	
	priority_queue<ll,vector<ll>,greater<ll> > que;
	
	for (ll T=1;;T++){
		while (gtop&&g[gtop].fi<=T)
			que.push(g[gtop--].se);
		if (que.empty()){
			if (!gtop) break;
			T=g[gtop].fi-1;
			continue;
		}
		if (que.top()<T) return print(que.top()),void();
		h[++htop]=que.top(); que.pop();
	}
	print(ll(1e18));
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}