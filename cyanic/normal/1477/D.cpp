#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=500005;
int p[N],q[N],mark[N],n,m,x,y,cnt;
set<int> e[N],que;
vi g[N];

void dfs(int u){
	for(auto v:que){
		if(e[u].find(v)==e[u].end()){
			g[u].pb(v);
		}
	}
	for(auto v:g[u]){
		que.erase(v);
	}
	for(auto v:g[u]){
		dfs(v);
	}
}

void pre(int u){
	if(g[u].empty()){
		mark[u]=1;
		return;
	}
	mark[u]=3;
	for(auto v:g[u]){
//		printf("# %d -> %d\n",u,v);
		pre(v);
		if(mark[v]==1) mark[u]=2;
	}
}

void solve(int u,int fa){
	if(fa){
		if(mark[u]==2){
			q[u]=cnt+1;
			p[fa]=++cnt,q[fa]=cnt+1;
			for(auto v:g[u]){
				if(mark[v]==1){
					p[v]=++cnt,q[v]=cnt+1;
				}
			}
			p[u]=++cnt;
		}
		else{
			p[fa]=cnt+1,p[u]=cnt+2;
			q[fa]=cnt+2,q[u]=cnt+1;
			cnt+=2;
		}
		for(auto v:g[u]){
			if(mark[v]!=1) solve(v,0);
		}
	}
	else{
		if(mark[u]==2){
			q[u]=cnt+1;
			for(auto v:g[u]){
				if(mark[v]==1){
					p[v]=++cnt,q[v]=cnt+1;
				}
			}
			p[u]=++cnt;
			for(auto v:g[u]){
				if(mark[v]!=1) solve(v,0);
			}
		}
		else{
			int fir=1;
			for(auto v:g[u]){
				if(mark[v]!=1){
					if(fir) solve(v,u);
					else solve(v,0);
					fir=0;
				}
			}
		}
	}
}

void rmain(){
	read(n),read(m);
	que.clear();
	rep(i,1,n){
		e[i].clear();
		g[i].clear();
		que.insert(i);
		mark[i]=0;
	}
	rep(i,1,m){
		read(x),read(y);
		e[x].insert(y);
		e[y].insert(x);
	}
	cnt=0;
	for(;!que.empty();){
		int x=*que.begin();
		que.erase(x),dfs(x);
		if(g[x].empty()){
			p[x]=q[x]=++cnt;
			continue;
		}
		pre(x),solve(x,0);
	}
	rep(i,1,n){
		printf("%d ",p[i]);
	}
	puts("");
	rep(i,1,n){
		printf("%d ",q[i]);
	}
	puts("");
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();
	return 0;
}