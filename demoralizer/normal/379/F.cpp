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

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e6+1005;

vector<int> v[N];
int lvl[N];
int first[N];
vector<int> euler;
void dfs(int z, int p){
	lvl[z] = lvl[p] + 1;
	first[z] = sz(euler);
	euler.pb(lvl[z]);
	for(auto u:v[z]){
		if(u!=p){
			dfs(u,z);
			euler.pb(lvl[z]);
		}
	}
}

#define maxn N
#define max_logn 20
struct SparseMin{
    int log[maxn];
    int dp[max_logn][maxn];
    SparseMin(){
        log[1] = 0;
        for (int i = 2; i < maxn; i++)
            log[i] = log[i/2] + 1;
    }
    void build(vector<int> b)
    {
        int n=b.size();
        for (int i = 0; i < n; ++i){
            dp[0][i]=b[i];
        }
        for (int j = 1; j < max_logn; j++)
            for (int i = 0; i + (1 << j) < maxn; i++)
                dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
    }
    int query(int l,int r)
    {
        if(l>r)swap(l,r);
        int j=log[r-l+1];
        return min(dp[j][l],dp[j][r-(1<<j)+1]);
    }
}spmin;

int dist(int x,int y){
	return lvl[x]+lvl[y]-2*spmin.query(first[x],first[y]);
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
};
CentroidDecomposition ct;

struct mystruct{
	int val,left,right;
	mystruct(int v,int cnt){
		val=v;
		left=cnt;
		right=cnt+1;
	}
	
	operator int() const{
		return val;
	}
};
vector<mystruct> e;

int m[N],ans=0,ppp[N];bool on[N];
struct mset{
	int mx=0,mx2=0;
	void insert(int x){
		if(x>mx){
			mx2=mx;
			mx=x;
		}
		else if(x>mx2){
			mx2=x;
		}
	}
	void erase(int x){
		if(x==mx){
			mx=mx2;
			mx2=0;
		}
		else if(x==mx2){
			mx2=0;
		}
	}
	int operator* (){
		return mx;
	}
}s[N];

void activate(int i){
	on[i]=1;
	amax(ans,*s[i]);
	int y=i,z=i;
	while(y!=ct.root()){
		int d=dist(z,ct.par[y]);
		s[ct.par[y]].erase(m[y]);
		if(on[ct.par[y]])amax(ans,d+*s[ct.par[y]]);
		amax(m[y],d);
		s[ct.par[y]].insert(m[y]);
		y=ct.par[y];
	}
}

void solve(){
	ct.set(N);
	ppp[2]=1;
	ppp[3]=1;
	ppp[4]=1;
	int q;
	cin>>q;
	int cnt=5;
	rep(i,0,q){
		int x;
		cin>>x;
		v[ppp[x]].pb(x);
		v[x].pb(ppp[x]);
		ct.addEdge(ppp[x],x);
		e.pb({x,cnt});
		ppp[cnt++]=x;
		ppp[cnt++]=x;
	}
	dfs(1,1);
	ct.decompose(1);
	spmin.build(euler);
	
	rep(i,1,cnt+1){
		s[i].insert(0);
	}
	
	activate(1);
	
	for(mystruct x:e){
		activate(x);
		cout<<ans+2<<"\n";
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