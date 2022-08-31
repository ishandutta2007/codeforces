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

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1005;

map<pair<string,int>,vector<pair<string, int>>> v;

map<pair<string, int>,bool> vis;
map<string, bool> done;


void solve(){
	int n;
	cin >> n;
	string root = "";
	int rootver = -1;
	rep(i,0,n){
		string s;
		cin >> s;
		int ver;
		cin >> ver;
		
		if(rootver == -1){
			root = s;
			rootver = ver;
		}
		
		
		pair<string, int> cur = {s,ver};
		int z;
		cin >> z;
		rep(j,0,z){
			pair<string, int> x;
			cin >> x;
			v[cur].pb(x);
		}
	}
	
	pair<string, int> r = {root, rootver};
	
	queue<pair<pair<string, int>,int>> q,nexq;
	nexq.push({r,0});
	vis[r] = 1;
	
	map<string, pii> m;
	m[root] = {0,-rootver};
	done[root] = 1;
	
	while(!nexq.empty()){
		swap(q,nexq);
		set<string> s;
		
		while(!q.empty()){
			auto cur = q.front();
			q.pop();
			auto node = cur.fr;
			int dis = cur.sc;
			
			
			for(auto adj:v[node]){
				if(vis[adj] || done[adj.fr]) continue;
				
				pii xyz = {dis+1,-adj.sc};
				s.insert(adj.fr);
				
				if(!m.count(adj.fr)){
					m[adj.fr] = xyz;
				}
				amin(m[adj.fr], xyz);
				vis[adj] = 1;
			}
		}
		for(string x:s){
			done[x] = 1;
			nexq.push({{x,-m[x].sc},m[x].fr});
		}
	}
	
	m.erase(root);
	cout << sz(m) << "\n";
	for(auto z:m){
		cout << z.fr << " " << -z.sc.sc << "\n";
		// cout << z << "\n";
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