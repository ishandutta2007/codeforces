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

const int N=1e5+5;

int n;
vector<pii> v[N];
int vis[N];
int dep[N];

bool dfs(int z,int wt){
	vis[z] = 1;
	for(pii x:v[z]){
		if(x.sc <= wt) continue;
		if(vis[x.fr] == 2) continue;
		if(vis[x.fr] == 1){
			return 1;
		}
		if(dfs(x.fr,wt)){
			return 1;
		}
	}
	
	for(pii x:v[z])
		amax(dep[z],dep[x.fr]);
	dep[z]++;
	vis[z] = 2;
	return 0;
}

bool cycle(int wt){
	mem0(vis);
	mem0(dep);
	rep(i,1,n+1){
		if(vis[i]) continue;
		if(dfs(i,wt)){
			return 1;
		} 
	}
	return 0;
}

pair<int, pii> e[N];

void solve(){
	int m;
	cin >> n >> m;
	rep(i,1,m+1){
		int x,y,c;
		cin >> x >> y >> c;
		v[x].pb({y,c});
		e[i] = {c,{x,y}};
	}
	
	int L = 0, U = 1e9;
	int ans;
	while(L <= U){
		int m = (L + U) / 2;
		if(cycle(m)){
			L = m + 1;
		}
		else{
			ans = m;
			U = m - 1;
		}
	}
	cycle(ans);
	
	vector<int> pr;
	rep(i,1,m+1){
		if(e[i].fr > ans) continue;
		int x = e[i].sc.fr;
		int y = e[i].sc.sc;
		// cout << x << " " << y << " " << dep[x] << " " << dep[y] << "\n";
		if(dep[x] > dep[y]) continue;
		if(dep[x] < dep[y]){
			pr.pb(i);
			continue;
		}
		if(x < y) continue;
		pr.pb(i);
	}
	
	cout << ans << " " << sz(pr) << "\n";
	for(int x:pr){
		cout << x << " ";
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