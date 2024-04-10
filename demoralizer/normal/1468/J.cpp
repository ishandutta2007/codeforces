#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2*100005;


struct DSU{
	int par[N];
	int sz[N];
	int comps;
	void make(int v){
		par[v]=v;
		sz[v]=1;
		comps++;
	}
    

	int find(int v){
		if(par[v]==v)return v;
		return par[v]=find(par[v]);
	}
	bool unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return 0;
		if(sz[a]<sz[b])swap(a,b);
		sz[a]+=sz[b];
		par[b]=a;
		comps--;
		return 1;
	}
	void clear(int n){
		comps=0;
		for (int i = 0; i < n; ++i) {
			par[i+1]=sz[i+1]=0;
		}
	}
}dsu;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<pair<int,pii>> edges;
	dsu.clear(n);
	for (int i = 0; i < n; ++i) {
	 	dsu.make(i+1);
	}
    int max_gre = INF;
    int min_gre = -1;
	for (int i = 0; i < m; ++i) {
		int x,y,s;
		cin>>x>>y>>s;
		edges.pb({s,{x,y}});
        if(s>k) amin(max_gre,s);
        else amax(min_gre,s);
	}
	sort(all(edges));
	int ans=INF;
	int lst=-INF;
    bool cc=  false;
    vector <int> vv;
	for(auto u:edges){
	
       if( dsu.unite(u.sc.sc,u.sc.fr)){
           if(u.fr<=k){
			lst=u.fr;
		}
        else {
        cc=true;
        vv.pb(u.fr);
        }
       }
	}
    if(cc){
        int sum=0;
        for(auto u:vv){
            sum+=(u-k);
        }
        amin(ans,sum);
    }
    else{
        amin(ans,k-lst);
        if(max_gre!=INF){
            amin(ans,max_gre-k);
        }
        if(min_gre!=-1){
            amin(ans,k-min_gre);
        }
    }
    cout<<ans<<endl;
	// trace(ans);
	
	/*int wen=0;
	bool flag=0;
	for(auto u:edges){
		if(u.fr<k){
			dsu.unite(u.sc.sc,u.sc.fr);
		}else{
			if(dsu.comps==1){
				amin(ans,u.fr-k);
				// trace(ans);
			}
			if(dsu.unite(u.sc.sc,u.sc.fr)){
				flag=1;
				wen+=u.fr-k;
			}
		}
	}
	if(flag)
		amin(ans,wen);
	dsu.clear(n);
	cout<<ans<<"\n";*/
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}