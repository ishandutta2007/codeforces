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

const int N=2e5+5;

vector<int> v[N];
int vis[N];

int dfs(int z){
	vis[z] = 1;
	int ans = 1;
	for(int x:v[z]){
		if(vis[x]) continue;
		ans += dfs(x);
	}
	return ans;
}

bool conn(int n, vector<pii> &e){
	rep(i,1,n+1){
		v[i].clear();
		vis[i] = 0;
	}
	for(auto x:e){
		v[x.fr].pb(x.sc);
		v[x.sc].pb(x.fr);
	}
	return dfs(1) == n;
}

void solve(){
	int n,m;
	cin >> n >> m;
	
	vector<pair<pii,int>> edges(m);
	rep(i,0,m){
		cin >> edges[i];
	}
	
	int ans = 0;
	for(int i = 29; i >= 0; i--){
		ans <<= 1;
		vector<pii> e;
		rep(j,0,m){
			if(((edges[j].sc >> i) | ans) == ans){
				e.pb(edges[j].fr);
			}
		}
		
		if(!conn(n,e)){
			ans ^= 1;
		}
	}
	cout << ans << "\n";
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