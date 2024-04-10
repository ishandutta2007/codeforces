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

const int N=3e5+5;

vector<int> g[N],v[N];
int st[N],et[N],tim = 1;

void dfs_inout(int z){
	st[z] = tim++;
	for(int x:g[z]){
		dfs_inout(x);
	}
	et[z] = tim-1;
}

int ans;
set<pii> s;
void dfs(int z){
	bool added = false;
	pii rem = {-1,-1};
	auto it = s.lower_bound({st[z],-1});
	if(it != s.end() && it->sc <= et[z]){
		// do not even consider
	}
	else{
		if(it != s.begin()){
			it--;
			if(it->sc >= et[z]){
				// completely covers current
				rem = *it;
				s.erase(it);
			}
		}
		s.insert({st[z],et[z]});
		added = true;
	}
	for(int x:v[z]){
		dfs(x);
	}
	amax(ans,sz(s));
	if(rem.fr != -1){
		s.insert(rem);
	}
	if(added){
		s.erase({st[z],et[z]});
	}
}

void solve(){
	int n;
	cin >> n;
	
	// clear
	ans = 0;
	s.clear();
	rep(i,1,n+1){
		v[i].clear();
		g[i].clear();
	}
	tim = 1;
	
	// solve
	rep(i,2,n+1){
		int x;
		cin >> x;
		v[x].pb(i);
	}
	rep(i,2,n+1){
		int x;
		cin >> x;
		g[x].pb(i);
	}
	
	dfs_inout(1);
	dfs(1);
	
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