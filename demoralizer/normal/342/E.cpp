#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int INF=1e9;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;
const int H = 17;

int dis[N];
int c[N];
int par[N][H+1], lvl[N];
vector<int> v[N];

void dfs0(int z,int p){
	lvl[z]=lvl[p]+1;
	par[z][0]=p;
	for (int i = 1; i <= H; ++i)
		par[z][i] = par[par[z][i-1]][i-1];
	for(int x:v[z]){
		if(x==p)continue;
		dfs0(x,z);
	}
}

int lca(int x, int y) {
	if (lvl[x] < lvl[y])
		swap(x, y);
	for (int i = H; i >= 0; i--)
		if (lvl[x] - (1<<i) >= lvl[y])
			x = par[x][i];
	if (x == y) return x;
	for (int i = H; i >= 0; i--)
		if (par[x][i] != par[y][i])
			x = par[x][i], y = par[y][i];
	return par[x][0];
}

struct CentroidDecomposition{
    int N;
    vector<vector<int>>G;
    vector<vector<int>>T;
    vector<int>used,sz,par;
    int r;
    void set(int n){
        N=n;
        G.resize(N);
        T.resize(N);
        par.resize(N);
        fill(all(par),-1);
    }
    void addEdge(int a,int b){
        G[a].push_back(b);
        G[b].push_back(a);
    }
 
    int calcSubtreeSize(int v,int p){
        sz[v]=1;
        for(auto u:G[v]){
            if(u==p||used[u])continue;
            sz[v]+=calcSubtreeSize(u,v);
        }
        return sz[v];
    }
 
    pair<int,int>findCentroid(int v,int p,int ov){
        pair<int,int>ret(N,-1);
        int mx=ov-sz[v];
        for(auto u:G[v]){
            if(u==p||used[u])continue;
            ret=min(ret,findCentroid(u,v,ov));
            mx=max(mx,sz[u]);
        }
        ret=min(ret,pair<int,int>(mx,v));
        return ret;
    }
 
    void dfs(int v,int p){
        calcSubtreeSize(v,-1);
        v=findCentroid(v,-1,sz[v]).second;
        used[v]=true;
        if(p==-1)r=v;
        else{
            par[v]=p;
            T[p].push_back(v);
        }
        for(auto u:G[v])if(!used[u])dfs(u,v);
    }
 
    void decompose(int v){
        used.resize(N);
        sz.resize(N);
        dfs(v,-1);
    }
 
    inline int root()const{
        return r;
    }
    vector<int>&operator[](int i){
        return T[i];
    }
    int operator() (int x){
    	return par[x];
    }
};
CentroidDecomposition ct;

void solve(){
	int n,m;
	cin>>n>>m;
	ct.set(n+2);
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
		ct.addEdge(x,y);
	}
	c[1]=1;
	ct.decompose(1);
	dfs0(ct.root(),ct.root());
	
	rep(i,1,n+1){
		dis[i]=INF;
	}
	
	rep(i,0,m+1){
		int t,v;
		if(i)cin>>t>>v;
		else t=1,v=1;
		if(t==1){
			int x=v;
			while(x!=-1){
				int l=lca(x,v);
				amin(dis[x],lvl[x]+lvl[v]-2*lvl[l]);
				x=ct(x);
			}
		}
		else{
			int ans=INF;
			int x=v;
			while(x!=-1){
				int l=lca(x,v);
				amin(ans,lvl[x]+lvl[v]-2*lvl[l] + dis[x]);
				x=ct(x);
			}
			cout<<ans<<"\n";
		}
	}
	
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}