#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])


char s[100010]; int n;
int p[100010];

struct C{
	int f,p,l; bool e;
	int tr[26];
}c[200010];
int ctot=1;
int ins(int g,int d,int p){
	int x=++ctot;
	c[x].p=p,c[x].l=c[g].l+1,c[x].e=1;
	for (;g&&!c[g].tr[d];c[g].tr[d]=x,g=c[g].f);
	if (!g) return c[x].f=1,x;
	int h=c[g].tr[d];
	if (c[h].l==c[g].l+1) return c[x].f=h,x;
	int w=++ctot;
	c[w].f=c[h].f,c[w].p=p,c[w].l=c[g].l+1,c[w].e=0;
	memcpy(c[w].tr,c[h].tr,26<<2);
	c[x].f=c[h].f=w;
	for (;g&&c[g].tr[d]==h;c[g].tr[d]=w,g=c[g].f);
	return x;
}

int dfn[200010],id[200010];
int st[18][200010],bt[200010];
int dep[200010],tot[200010];
vector<int> e[200010];

inline int chk(int x,int y){
	return dep[x]<dep[y]?x:y;
}

inline int getlca(int x,int y){
	if (x==y) return x;
	x=id[x],y=id[y];
	if (x>y) swap(x,y);
	--y;
	const int &lg=bt[y-x+1];
	return chk(st[lg][x],st[lg][y-(1<<lg)+1]);
}

void dfs0(int x,int f,int d){
	dep[x]=d; dfn[++*dfn]=x,id[x]=++*id;
	st[0][-1+*id]=f; tot[x]=c[x].e;
	forall(x,y) dfs0(y,x,d+1),tot[x]+=tot[y];
}

int D;

inline int getlen(int x,int y){
	x+=D,y+=D;
	return D+c[getlca(p[x],p[y])].l;
}

struct Cmp{
	bool operator()(int x,int y)const{
		x+=D,y+=D;
		int l=c[getlca(p[x],p[y])].l;
		return s[x+l]<s[y+l];
	}
};

struct B{
	set<int,Cmp> st;
	ll w;
	
	void ins(int x){
		auto it=st.insert(x).fi,pre=it,suf=it;
		w+=c[p[x]].l;
		if (++suf!=st.end()) w-=getlen(x,*suf);
		if (it!=st.begin()){
			w-=getlen(x,*--pre);
			if (suf!=st.end()) w+=getlen(*pre,*suf);
		}
	}
	
	void del(int x){
		auto it=st.find(x),pre=it,suf=it; assert(it!=st.end());
		w-=c[p[x]].l;
		if (++suf!=st.end()) w+=getlen(x,*suf);
		if (it!=st.begin()){
			w+=getlen(x,*--pre);
			if (suf!=st.end()) w-=getlen(*pre,*suf);
		}
		st.erase(it);
	}
}b[200010];

ll ans;

ll getsum(ll l,int t){
	return 1LL*(l+l+t-1)*t/2;
}

void dfs1(int x){
	if (e[x].size()){
		int z=-1;
		forall(x,y){
			dfs1(y);
//			debug("edge %d - %d: %lld\n",x,y,getsum(b[y].w-c[y].l+1,c[y].l-c[x].l-1));
			ans+=getsum(b[y].w-c[y].l+1,c[y].l-c[x].l-1);
			if (!~z||tot[y]>tot[z]) z=y;
		}
		D=c[x].l+1;
		swap(b[x],b[z]); B &g=b[x];
		forall(x,y) if (y^z){
			for (const auto &x: b[y].st)
				g.ins(x);
		}
//		debug("test st' %d  w %lld\n",x,g.w);
//		for (auto x: g.st) debug("%d ",x);
//		debug("\n");
//		debug("key %d: %lld\n",x,g.w-D+1);
		ans+=g.w-D+1;
		forall(x,y) if (y^z){
			for (const auto &x: b[y].st)
				g.del(x);
		}
		--D;
		forall(x,y) if (y^z){
			for (const auto &x: b[y].st)
				g.ins(x);
			b[y].st.clear();
		}
		if (c[x].e) g.ins(c[x].p);
//		debug("test st %d  w %lld\n",x,g.w);
//		for (auto x: g.st) debug("%d ",x);
//		debug("\n");
	}
	else{
		B &g=b[x];
		D=c[x].l;
		g.ins(c[x].p);
	}
}

void solve(){
	scanf("%s",s+1); n=strlen(s+1);
	int lst=1; p[n+1]=1;
	per(i,1,n) p[i]=lst=ins(lst,s[i]-'a',i);
	rep(i,2,ctot) e[c[i].f].pb(i);
	dfs0(1,0,1);
	bt[0]=-1; rep(i,1,ctot) bt[i]=bt[i>>1]+1;
	rep(j,1,17)
		rep(i,1,ctot-(1<<j))
			st[j][i]=chk(st[j-1][i],st[j-1][i+(1<<j-1)]);
	dfs1(1);
//	debug("outer: %lld\n",b[1].w+1);
	ans+=b[1].w+1;
	printf("%lld\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}