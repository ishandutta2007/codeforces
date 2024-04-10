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

string s[N];

int vis[N];
int cost[N][N];

int par[N];
int best[N];

int differ(string &s,string &t){
	int n = sz(s);
	int cnt = 0;
	rep(i,0,n){
		cnt += (s[i] != t[i]);
	}
	return cnt;
}

vector<int> v[N];

int dfs(int z,int p = 0){
	if(z){
		cout << z << " " << p << "\n";
	}
	for(int x:v[z]){
		dfs(x,z);
	}
}

void solve(){
	int n,m,k,w;
	cin >> n >> m >> k >> w;
	
	rep(i,1,k+1){
		rep(j,0,n){
			string t;
			cin >> t;
			s[i] += t;
		}
	}
	
	rep(i,1,k+1){
		best[i] = INF;
		cost[0][i] = cost[i][0] = n * m;
		rep(j,i+1,k+1){
			cost[i][j] = cost[j][i] = differ(s[i],s[j]) * w;
		}
	}
	
	// mst
	set<pii> s; // wt,ver
	s.insert({0,0});
	while(!s.empty()){
		pii cur = *s.begin();
		s.erase(s.begin());
		if(vis[cur.sc]) continue;
		int ver = cur.sc;
		vis[ver] = 1;
		
		rep(i,1,k+1){
			if(vis[i]) continue;
			int c = cost[ver][i];
			if(c < best[i]){
				s.erase({best[i],i});
				best[i] = c;
				s.insert({best[i],i});
				par[i] = ver;
			}
		}
		
	}
	
	int ans = 0;
	rep(i,1,k+1){
		ans += best[i];
		v[par[i]].pb(i);
	}
	
	cout << ans << "\n";
	dfs(0);
	
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