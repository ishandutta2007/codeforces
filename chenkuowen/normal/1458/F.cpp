#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+4e5;
struct Graph{
	struct Edge{ int to,nxt; bool mark; };
	vector<int> head;
	vector<Edge> edge;
	Graph(int n=0,int m=0){
		head=vector<int>(n+1,-1);
		edge.clear(); edge.reserve(m);
	}
	inline void add(int x,int y){
		edge.push_back((Edge){y,head[x],false});
		head[x]=edge.size()-1;
	}
}G;
namespace T{
	int dep[N],dfn[N],ti,fa[23][N],e[N];
	struct ST{
		int st[23][N+N],lg[N+N];
		int merge(int x,int y){ return T::dep[x]<T::dep[y]?x:y; }
		int& operator[](int x){ return st[0][x]; }
		void build(int n){
			lg[1]=0; for(int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
			for(int l=1;l<=lg[n];++l)
				for(int i=1;i+(1<<l)-1<=n;++i)
					st[l][i]=merge(st[l-1][i],st[l-1][i+(1<<l-1)]);
		}
		int query(int x,int y){
			int l=lg[y-x+1];
			return merge(st[l][x],st[l][y-(1<<l)+1]);
		}
	}st;
	void dfs(int x,int pre){
		fa[0][x]=pre;
		for(int l=1;l<=18;++l) fa[l][x]=fa[l-1][fa[l-1][x]];
		dep[x]=dep[pre]+1,st[dfn[x]=++ti]=x;
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(y!=pre) dfs(y,x),st[++ti]=x;
		}
		e[x]=ti;
	}
	void init(int n){
		dep[0]=ti=0; dfs(1,0);
		st.build(n+n-1);
	}
	int lca(int x,int y){
		if(dfn[x]>dfn[y]) swap(x,y);
		return st.query(dfn[x],dfn[y]);
	}
	bool is_an(int x,int y){ return dfn[x]<=dfn[y]&&e[y]<=e[x]; }
	int dis(int x,int y){ return dep[x]+dep[y]-2*dep[lca(x,y)]; }
	int jump(int x,int d){
		for(int l=st.lg[d];l>=0;--l)
			if((d>>l)&1) x=fa[l][x];
		return x;
	}
	int get_near(int x,int y){
		return jump(y,dep[y]-dep[x]-1);
	}
}
struct Circle{  
	int x,r; 
	Circle(int _x=0,int _r=0){x=_x,r=_r;}
	void add(int y){
		int len=(T::dis(x,y)-r+1)/2; 
		if(len<=0) return;
		r+=len;
		int d=T::lca(x,y);
		if(T::dis(x,d)>=len) x=T::jump(x,len);
		else x=T::jump(y,T::dis(x,y)-len);
	}
};
namespace DC{
	ll q[N],cnt[N];
	vector<ll> q1[N],cnt1[N];
	int sz[N],val[N],dis[23][N],dc_fa[N],dc_type[N],dc_lev[N];
	void get_sz(int x,int pre){
		sz[x]=1; val[x]=0;
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(!G.edge[j].mark&&y!=pre){
				get_sz(y,x),sz[x]+=sz[y];
				val[x]=max(val[x],sz[y]);
			}
		}
	}
	int get_rt(int x,int pre,int size){
		val[x]=max(val[x],size-sz[x]); int rt=x;
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(!G.edge[j].mark&&y!=pre){
				int k=get_rt(y,x,size);
				if(val[k]<val[rt]) rt=k;
			}
		}
		return rt;
	}
	void dfs(int x,int pre,int dis[],int d){
		dis[x]=d;
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(!G.edge[j].mark&&y!=pre)
				dfs(y,x,dis,d+1);
		}
	}
	void dc(int x,int pre,int type,int lev){
		get_sz(x,0);
		x=get_rt(x,0,sz[x]);
		dc_fa[x]=pre,dc_type[x]=type; dc_lev[x]=lev;
//		printf("[%d %d]",x,dc_fa[x]);
		q[x]=0; cnt[x]=0;
		dfs(x,0,dis[lev],0);
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(!G.edge[j].mark){
				G.edge[j].mark=G.edge[j^1].mark=1;
				dc(y,x,q1[x].size(),lev+1);
				q1[x].push_back(0);
				cnt1[x].push_back(0);
			}
		}
	}
	void add(int x,int k){
		int sx=x; cnt[x]+=k; 
		for(int y=dc_fa[x];y!=0;x=y,y=dc_fa[y]){
			int d=dis[dc_lev[y]][sx];
			q1[y][dc_type[x]]+=k*d;
			cnt1[y][dc_type[x]]+=k;
			q[y]+=k*d;
			cnt[y]+=k;
		}
	}
	ll query(int x){
		int sx=x; ll ret=q[x];
		for(int y=dc_fa[x];y!=0;x=y,y=dc_fa[y]){
			int d=dis[dc_lev[y]][sx];
			ret+=1ll*(cnt[y]-cnt1[y][dc_type[x]])*d+q[y]-q1[y][dc_type[x]];
		}
		return ret;
	}
}
ll ans=0;
void solve(int l,int r){
	if(l==r) return;
	int m=l+r>>1;
	vector<Circle> g;
	Circle cc;
	for(int i=m;i>=l;--i){
		if(i==m) cc=Circle(i,0);
		else cc.add(i);
		g.push_back(cc);
	}
//	for(int i=0;i<g.size();++i) printf("[%d %d]",g[i].x,g[i].r);
	int p1=0,p2=0;
	ll sum1=0,sum2=0;
	for(int i=0;i<g.size();++i) sum2+=g[i].r;
	for(int i=m+1;i<=r;++i){
		if(i==m+1) cc=Circle(i,0);
		else cc.add(i);
		for(;p2<g.size()&&T::dis(cc.x,g[p2].x)+cc.r>g[p2].r;++p2) {
			sum2-=g[p2].r;
			sum1+=g[p2].r;
			DC::add(g[p2].x,1);
		}
		for(;p1<g.size()&&T::dis(cc.x,g[p1].x)+g[p1].r<=cc.r;++p1){
			sum1-=g[p1].r;
			DC::add(g[p1].x,-1);
		}
		ans+=2ll*p1*cc.r+(sum1+ll(p2-p1)*cc.r+DC::query(cc.x))+sum2*2;
	}
	for(;p2<g.size();++p2) 
		DC::add(g[p2].x,1);
	for(;p1<g.size();++p1)
		DC::add(g[p1].x,-1);
	solve(l,m);
	solve(m+1,r);
}
int main(){
	int n; scanf("%d",&n);
	G=Graph(n+n,n+n);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,n+i); G.add(n+i,x);
		G.add(y,n+i); G.add(n+i,y);
	}
	T::init(n+n-1);
	DC::dc(1,0,0,0);
	solve(1,n);
	printf("%lld\n",ans/2);
	return 0;
}