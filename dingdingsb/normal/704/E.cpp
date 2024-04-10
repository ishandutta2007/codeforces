#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e5+100;
struct frac{
	ll x,y;//
	frac(){x=0,y=1;};
	frac(ll a,ll b=1){int g=__gcd(a,b);x=a/g,y=b/g;if(y<0)x=-x,y=-y;}
	frac operator+(const frac rhs)const{return frac(x*rhs.y+y*rhs.x,y*rhs.y);}
	frac operator-(const frac rhs)const{return frac(x*rhs.y-y*rhs.x,y*rhs.y);}
	frac operator*(const frac rhs)const{return frac(x*rhs.x,y*rhs.y);}
	frac operator/(const frac rhs)const{return frac(x*rhs.y,y*rhs.x);}
	bool operator<(const frac rhs)const{return x*rhs.y<y*rhs.x;}
	bool operator>(const frac rhs)const{return x*rhs.y>y*rhs.x;}
	bool operator<=(const frac rhs)const{return x*rhs.y<=y*rhs.x;}
	bool operator>=(const frac rhs)const{return x*rhs.y>=y*rhs.x;}
	bool operator==(const frac rhs)const{return x*rhs.y==y*rhs.x;}
	bool operator!=(const frac rhs)const{return x*rhs.y!=y*rhs.x;}
	void print(){printf("%.5lf",1.*x/y);}
};
int n,m;vector<int>e[N];
int dep[N],sz[N],fa[N],top[N],son[N];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;sz[u]=1;
	for(auto v:e[u])if(v!=fa[u]){
		fa[v]=u;dfs1(v);sz[u]+=sz[v];
		if(sz[v]>=sz[son[u]])son[u]=v;
	}
}
void dfs2(int u){
	if(!top[u])top[u]=u;
	if(son[u])top[son[u]]=top[u];
	for(auto v:e[u])if(v!=fa[u])
		dfs2(v);
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
frac Ans=0x3f3f3f3f3f3fll,ans,tim;
struct seg{
	frac l,r,k,b;seg(){}
	seg(frac l,frac r,frac k,frac b):l(l),r(r),k(k),b(b){}
	bool operator<(const seg rhs)const{
		return mt(k*tim+b,l,r,k,b)<mt(rhs.k*tim+rhs.b,rhs.l,rhs.r,rhs.k,rhs.b);
	}
	void print(){k.print();pc('x');pc('+');b.print();printf("  x in [");l.print();pc(' ');r.print();puts("]");}
};
vector<seg>segs[N];
seg makeline(frac x1,frac y1,frac x2,frac y2){
	if(x1==x2){assert(y1==y2);return seg(x1,x1,0,y1);}
	frac l=min(x1,x2),r=max(x1,x2);
	frac k=(y2-y1)/(x2-x1),b=y1-x1*k;
	return seg(l,r,k,b);
}
void add(int x,int y,frac t,int c){
	int l=lca(x,y),dx=0,dy=dep[x]+dep[y]-2*dep[l];
	while(top[x]!=top[y]){
		if(dep[top[x]]>=dep[top[y]]){
			segs[top[x]].pb(makeline(t+frac(dx,c),dep[x],t+frac(dx+dep[x]-dep[fa[top[x]]],c),dep[fa[top[x]]]));
			dx+=dep[x]-dep[fa[top[x]]];x=fa[top[x]];
		}else{
			segs[top[y]].pb(makeline(t+frac(dy,c),dep[y],t+frac(dy-dep[y]+dep[fa[top[y]]],c),dep[fa[top[y]]]));
			dy+=dep[fa[top[y]]]-dep[y];y=fa[top[y]];
		}
	}
	segs[top[x]].pb(makeline(t+frac(dx,c),dep[x],t+frac(dy,c),dep[y]));
}
void calc(seg a,seg b){
	frac o=(a.k-b.k);if(!o.x){
		if(a.b!=b.b)return;
		if(max(a.l,b.l)<=min(a.r,b.r))chkmn(ans,max(a.l,b.l));
		return;
	}
	frac x=(b.b-a.b)/o;
	if(a.l<=x&&x<=a.r&&b.l<=x&&x<=b.r)chkmn(ans,x);
}
void work(vector<seg>&segs){
	vector<tuple<frac,bool,seg>>arr;ans=0x3f3f3f3f3f3f;
	///
	for(auto s:segs)arr.pb(mt(s.l,0,s)),arr.pb(mt(s.r,1,s));
	sort(arr.begin(),arr.end());
	multiset<seg>s;
	for(auto wyh:arr){
		frac now;bool op;seg se;tie(now,op,se)=wyh;
		if(now>=ans)break;
		tim=now;
		if(!op){
			auto it=s.insert(se);
			if(it!=s.begin())calc(*it,*prev(it));
			if(next(it)!=s.end())calc(*it,*next(it));
		}else{
			auto it=s.find(se);
			if(it!=s.begin()&&next(it)!=s.end())calc(*prev(it),*next(it));
			s.erase(it);
		}
	}
	chkmn(Ans,ans);
}
signed main(){
	//freopen("1.in","r",stdin);
	read(n,m);
	for(int i=1,u,v;i<n;i++)read(u,v),e[u].pb(v),e[v].pb(u);
	dfs1(1);dfs2(1);
	for(int i=1,u,v,t,c;i<=m;i++)read(t,c,u,v),add(u,v,t,c);
	for(int i=1;i<=n;i++)if(segs[i].size())work(segs[i]);
	if(Ans.x==0x3f3f3f3f3f3f)puts("-1");
	else printf("%.10lf",1.*Ans.x/Ans.y);
	cerr<<"More and more vegetable what should I do???";
}