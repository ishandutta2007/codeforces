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

// ct.set(SIZE+2);
// ct.addEdge(x,y);
// ct.decompose(v);
// ct.root();
// ct[x] - vector with vertices adjacent to x in the decomposed tree
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

char ans[N];

void solve(){
	int n;
	cin>>n;
	ct.set(n+5);
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		ct.addEdge(x,y);
	}
	ct.decompose(1);
	int r=ct.root();
	queue<int> q;
	q.push(r);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(x==r)ans[x]='A';
		else ans[x]=ans[ct.par[x]]+1;
		for(int y:ct[x]){
			q.push(y);
		}
	}
	rep(i,1,n+1){
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