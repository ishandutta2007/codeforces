#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005;
int fa[N][20],d[N],in[N],out[N],cur[N];
pair<int,pii> T[N<<2];
int n,m,Q,clk,a,b;
vi e[N];

void dfs(int u,int f){
	cur[in[u]=++clk]=u;
	fa[u][0]=f;
	rep(j,1,18){
		fa[u][j]=fa[fa[u][j-1]][j-1];
	}
	for(auto v:e[u]){
		if(v==f) continue;
		d[v]=d[u]+1;
		dfs(v,u);
	}
	out[u]=clk;
}

int lca(int x,int y){
	if(d[y]>d[x]) swap(x,y);
	per(j,18,0){
		if(d[fa[x][j]]>=d[y]){
			x=fa[x][j];
		}
	}
	if(x==y) return x;
	per(j,18,0){
		if(fa[x][j]!=fa[y][j]){
			x=fa[x][j];
			y=fa[y][j];
		}
	}
	return fa[x][0];
}

int dist(int x,int y){
	return d[x]+d[y]-2*d[lca(x,y)];
}

pair<int,pii> merge(const pair<int,pii> x,const pair<int,pii> y){
	pair<int,pii> res=max(x,y);
	int a=x.se.fi,b=x.se.se;
	int c=y.se.fi,d=y.se.se;
	int tmp=dist(a,c);
	if(tmp>res.fi) res=mp(tmp,mp(a,c));
	tmp=dist(a,d);
	if(tmp>res.fi) res=mp(tmp,mp(a,d));
	tmp=dist(b,c);
	if(tmp>res.fi) res=mp(tmp,mp(b,c));
	tmp=dist(b,d);
	if(tmp>res.fi) res=mp(tmp,mp(b,d));
	return res;
}

void build(int o,int l,int r){
	if(l==r){
		T[o]=mp(0,mp(cur[l],cur[l]));
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	T[o]=merge(T[lc],T[rc]);
}

pair<int,pii> qry(int o,int l,int r,int x,int y){
	if(l==x&&y==r) return T[o];
	if(y<=mid) return qry(lc,l,mid,x,y);
	if(mid<x) return qry(rc,mid+1,r,x,y);
	return merge(qry(lc,l,mid,x,mid),qry(rc,mid+1,r,mid+1,y));
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(b),e[b].pb(a);
	}
	d[1]=1,dfs(1,0);
	build(1,1,n);
	read(Q);
	while(Q--){
		read(a),read(b);
		int c=lca(a,b);
		if(d[a]-d[c]<d[b]-d[c]){
			swap(a,b);
		}
		int p=a,aim=d[a]-(d[a]+d[b]-2*d[c])/2;
		if(d[a]-d[c]==d[b]-d[c]) aim++;
		per(j,18,0){
			if(d[fa[p][j]]>=aim){
				p=fa[p][j];
			}
		}
		int ans=0;
		pair<int,pii> ans1,ans2;
		ans1=qry(1,1,n,in[p],out[p]);
		ans=max(ans,dist(a,ans1.se.fi));
		ans=max(ans,dist(a,ans1.se.se));
		if(1<in[p]){
			ans2=qry(1,1,n,1,in[p]-1);
			ans=max(ans,dist(b,ans2.se.fi));
			ans=max(ans,dist(b,ans2.se.se));
		}
		if(out[p]<n){
			ans2=qry(1,1,n,out[p]+1,n);
			ans=max(ans,dist(b,ans2.se.fi));
			ans=max(ans,dist(b,ans2.se.se));
		}
		printf("%d\n",ans);
	}
	return 0;
}