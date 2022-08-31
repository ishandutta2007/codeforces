#include "bits/stdc++.h"
using namespace std;
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

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=5e5+5;

int par[N];
int par2[N];
int find(int x,int *par){
	if(par[x] == x) return x;
	return par[x] = find(par[x],par);
}
void merge(int x,int y,int *par){
	par[find(x,par)] = find(y,par);
}


void solve(){
	int n,m;
	cin >> n >> m;
	
	rep(i,1,n+1) par[i] = i, par2[i] = i;
	
	vector<array<int,3>> edg(m+1);
	vector<vector<int>> d(N);
	rep(i,1,m+1){
		int x,y,z;
		cin >> x >> y >> z;
		edg[i] = {x,y,z};
		d[z].pb(i);
	}
	
	int q;
	cin >> q;
	
	vector<bool> ans(q,1);
	vector<vector<pair<int, vector<int>>>> queries(N);
	
	rep(i,0,q){
		int k;
		cin >> k;
		map<int, vector<int>> m;
		rep(i,0,k){
			int x;
			cin >> x;
			m[edg[x][2]].pb(x);
		}
		for(auto &z:m){
			int wt = z.fr;
			queries[wt].pb({i,z.sc});
		}
	}
	
	for(int wt = 1; wt < N; wt++){
		// solve queries of wt 1
		for(auto &query:queries[wt]){
			int id = query.fr;
			bool tmp = 1;
			set<int> vers;
			for(int e:query.sc){
				int x = edg[e][0], y = edg[e][1];
				x = find(x,par), y = find(y,par);
				vers.insert(x);
				vers.insert(y);
				if(find(x,par2) == find(y,par2)){
					tmp = 0;
				}
				merge(x,y,par2);
			}
			for(int x:vers){
				par2[x] = x;
			}
			ans[id] = (ans[id] && tmp);
		}
		// dsu edges of wt 1
		for(int z:d[wt]){
			int x = edg[z][0], y = edg[z][1];
			merge(x,y,par);
		}
	}
	
	for(int x:ans){
		if(x) cout << "YES\n";
		else cout << "NO\n";
	}
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
	//cin>>t;
	while(t--) solve();
	return 0;
}