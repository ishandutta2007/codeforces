#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
typedef long long ll;
template<class T> void chmax(T& x,T y){ y>x?x=y:T(); }
namespace IO{
	const int sz=1<<20;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
		return getchar();
		return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
	}
	template<class T> void gi(T& x){
		x=0; char c=gc();
		for(;c<'0'||c>'9';c=gc());
		for(;c>='0'&&c<='9';c=gc())
			x=x*10+(c-'0');
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush();}
	template<class T> void pi(T x,char c='\n'){
		if(x<0) pc('-'),x=-x;
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush();}}f;
}
using IO::gi;
using IO::pi;
struct S{
	vector<pair<int,ll> > a;
	vector<ll> s;
	void init(vector<pair<int,ll> > _a){
		a=_a; sort(a.begin(),a.end()); 
		s.resize(a.size());
		s[0]=a[0].second;
		for(int i=1;i<a.size();++i)
			s[i]=s[i-1]+a[i].second;
	}
	inline int search(int x){
		int p=upper_bound(a.begin(),a.end(),make_pair(x,(ll)1e18))-a.begin();
		return p-1;
	}
	inline pair<ll,int> query(int x){ //the first element means sum, the second element means number
		int p=search(x);
//		for(auto x:a) printf("/%d %lld/",x.first,x.second);
//		printf("{%d %d}",x,p);
		if(p==-1) return make_pair(0ll,0);
		else return make_pair(s[p],p+1);
	}
	inline pair<ll,int> query(int l,int r){
		pair<ll,int> a=query(r),b=query(l-1);
		return make_pair(a.first-b.first,a.second-b.second);
	}
	inline void change(int x){ //*
		int p=search(x),p1;
		p1=min(p+1,(int)a.size()-1);
		if(p==-1||a[p].first!=x) p=-1;
		if(p1==-1||a[p1].first!=x+1) p1=-1;
		if(p!=-1) a[p].first++;
		if(p1!=-1) a[p1].first--;
		if(p!=-1&&p1!=-1){
			s[p]+=a[p1].second-a[p].second;
			swap(a[p],a[p1]);
		}
	}
};
struct Graph{
	struct Edge{ int to,nxt,k; bool mark; }edge[N*2];
	int head[N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y,int k){
		edge[++top]=(Edge){y,head[x],k,false};
		head[x]=top;
	}
	inline void add2(int x,int y,int k){add(x,y,k),add(y,x,k);}
}G;
namespace T{
	int dfn[N],dep[N],ti=0;
	ll s[N];
	inline int merge(int x,int y){ return dep[x]<dep[y]?x:y; }
	struct ST{
		int st[23][N+N],p[N+N];
		int& operator[](int x){ return st[0][x]; }
		void build(int n){
			for(int l=1;1<<l<=n;++l)
				for(int i=1;i+(1<<l)-1<=n;++i)
					st[l][i]=T::merge(st[l-1][i],st[l-1][i+(1<<l-1)]);
			p[1]=0; for(int i=2;i<=n;++i) p[i]=p[i>>1]+1;
		}
		int query(int x,int y){
			int l=p[y-x+1];
			return T::merge(st[l][x],st[l][y-(1<<l)+1]);
		}
	}st;
	void dfs(int x,int pre){
		st[dfn[x]=++ti]=x;
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(y!=pre){
				dep[y]=dep[x]+1;
				s[y]=s[x]+G.edge[j].k;
				dfs(y,x);
				st[++ti]=x;
			}
		}
	}
	void init(int n){
		dep[1]=s[1]=0;
		dfs(1,0);
		st.build(n+n+1);
	}
	inline int lca(int x,int y){
		if(dfn[x]>dfn[y]) swap(x,y);
		return st.query(dfn[x],dfn[y]);
	}
	inline ll dis(int x,int y){
		return s[x]+s[y]-(s[lca(x,y)]<<1);
	}
}
int sz[N],val[N];
void get_sz(int x,int pre){
	sz[x]=1; val[x]=0;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre&&!G.edge[j].mark){
			get_sz(y,x); sz[x]+=sz[y];
			chmax(val[x],sz[y]);
		}
	}
}
int get_rt(int x,int pre,int size){
	int rt=x; chmax(val[x],size-sz[x]);
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre&&!G.edge[j].mark){
			int k=get_rt(y,x,size);
			if(val[k]<val[rt]) rt=k;
		}
	}
	return rt;
}
int revp[N],p[N],dc_fa[N],dc_id[N];
S f[N];
vector<S> f2[N];
void dfs(int x,int pre,ll dis,vector<pair<int,ll> >& g){
	g.push_back(make_pair(revp[x],dis));
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre&&!G.edge[j].mark)
			dfs(y,x,dis+G.edge[j].k,g);
	}
}
void dc(int x,int pre,int id){
	get_sz(x,0);
	x=get_rt(x,0,sz[x]);
	get_sz(x,0);
	dc_fa[x]=pre;
	dc_id[x]=id;
	vector<pair<int,ll> > g;
	g.reserve(sz[x]);
	dfs(x,0,0,g);
	f[x].init(g);
//	for(int i=0;i<g.size();++i) printf("[%d %lld]",g[i].first,g[i].second); puts("");
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(!G.edge[j].mark){
			vector<pair<int,ll> > g; g.reserve(sz[y]);
			dfs(y,x,G.edge[j].k,g);
			S s2; s2.init(g);
			f2[x].push_back(s2);
			G.edge[j].mark=G.edge[j^1].mark=1;
			dc(y,x,(int)f2[x].size()-1);
		}
	}
}
ll query(int l,int r,int x){
	ll ret=f[x].query(l,r).first;
	int sx=x;
	for(int y=dc_fa[x];y!=0;x=y,y=dc_fa[y]){
		ll d=T::dis(sx,y);
//		printf("<%d %d %lld>",sx,y,d);	
		pair<ll,int> k=f[y].query(l,r),k2=f2[y][dc_id[x]].query(l,r);
		ret+=k.first-k2.first+(k.second-k2.second)*d;
	}
	return ret;
}
vector<int> tim[N];
int ti;
void change1(int x,int t,int i){
	if(tim[x][t+1]!=ti){
		if(t==-1) f[x].change(i);
		else f2[x][t].change(i);
		tim[x][t+1]=ti;
	}
}
void change(int i){
	++ti;
	change1(p[i],-1,i);
	for(int x=p[i],y=dc_fa[x];y!=0;x=y,y=dc_fa[y]){
		change1(y,dc_id[x],i);
		change1(y,-1,i);
	}
	change1(p[i+1],-1,i);
	for(int x=p[i+1],y=dc_fa[x];y!=0;x=y,y=dc_fa[y]){
		change1(y,dc_id[x],i);
		change1(y,-1,i);
	}
	swap(p[i],p[i+1]);
	swap(revp[p[i]],revp[p[i+1]]);
}
int main(){
	int n,q; gi(n); gi(q);
	for(int i=1;i<=n;++i) gi(p[i]),revp[p[i]]=i;
	for(int i=1;i<n;++i){
		int x,y,w; gi(x); gi(y); gi(w);
		G.add2(x,y,w);
	}
	T::init(n);
	dc(1,0,0);
	for(int i=1;i<=n;++i) tim[i].resize(f2[i].size()+1);
	ll ans=0;
	int G=(1<<30)-1;
	while(q--){
		int op; gi(op);
		if(op==1){
			int l,r,v;
			gi(l); gi(r); gi(v);
			l=(ans&G)^l;
			r=(ans&G)^r;
			v=(ans&G)^v;
			pi(ans=query(l,r,v));
		}else{
			int x; gi(x);
			x^=(ans&G);
			change(x);
		}
	}
	return 0;
}