#include <bits/stdc++.h>
using namespace std;
#define int               long long
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

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;

set<int> v[N];int vis[N];
vector<int> stk;
vector<vector<int>> r;
void dfs(int z){
	vis[z]=1;
	stk.pb(z);
	auto it=v[z].lower_bound(z);
	while(it!=v[z].begin()){
		it--;
		r.emplace_back();
		while(stk.back()!=*it){
			r.back().pb(stk.back());
			stk.ppb();
		}
		r.back().pb(*it);
		stk.pb(z);
	}
	it=v[z].lower_bound(z);
	while(it!=v[z].end()){
		if(!vis[*it])dfs(*it);
		it++;
	}
}

map<pii, vector<int>> edg;


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
};
CentroidDecomposition ct;

int ans[N];

void dfs2(int z,int c){
	ans[z]=c;
	for(int x:ct[z]){
		dfs2(x,c+1);
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		v[x].insert(y);
		v[y].insert(x);
	}
	
	rep(i,1,n+1){
		v[i].insert(i%n+1);
	}
	
	dfs(1);
	
	sort(all(r));
	
	rep(i,0,sz(r)){
		rep(j,0,sz(r[i])){
			int a=r[i][j],b=r[i][(j+1)%sz(r[i])];
			if(a>b)swap(a,b);
			edg[{a,b}].pb(i);
		}
	}
	
	ct.set(sz(r)+5);
	
	for(auto x:edg){
		if(sz(x.sc)==2){
			ct.addEdge(x.sc.front(),x.sc.back());
		}
	}
	
	ct.decompose(0);
	
	dfs2(ct.root(),1);
	
	rep(i,0,sz(r)){
		cout<<ans[i]<<" ";
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