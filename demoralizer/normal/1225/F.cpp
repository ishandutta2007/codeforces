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

vector<vector<int>> v;
int p[N];
int siz[N];
int vis[N];

void dfs_sz(int z){
	for(int x:v[z]){
		dfs_sz(x);
		amax(siz[z], siz[x]);
	}
	siz[z] += 1;
}

vector<int> moves;

void dfs(int z){
	if(vis[z]) return;
	vis[z] = 1;
	while(sz(v[z]) > 1){
		int x = v[z].back();
		v[z].ppb();
		dfs(x);
		v[v[z].back()].pb(x);
		moves.pb(x);
	}
	if(sz(v[z])){
		dfs(v[z][0]);
	}
}

void solve(){
	int n;
	cin >> n;
	v.resize(n);
	rep(i,1,n){
		cin >> p[i];
		v[p[i]].pb(i);
	}
	
	dfs_sz(0);
	rep(i,0,n){
		sort(all(v[i]),[&](int x, int y){
			return siz[x] < siz[y];
		});
	}
	dfs(0);
	
	int z = 0;
	while(sz(v[z])){
		cout << z << " ";
		z = v[z][0];
	}
	cout << z << "\n";
	cout << sz(moves) << "\n";
	reverse(all(moves));
	for(int x:moves){
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