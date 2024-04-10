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

const int N=2e5 + 5;

vector<int> v[N];
int vis[N];
int siz[N];
int dep[N];
int ans = 0;
int n;

void dfs1(int z,int p, int d = 0){
	dep[z] = d;
	vis[z] = 1;
	for(int x:v[z]){
		if(x == p) continue;
		if(vis[x]){
			// backedge
			continue;
		}
		dfs1(x,z,d+1);
		siz[z] += siz[x];
	}
}

int dfs2(int z,int p){
	vis[z] = 1;
	int ret = n + 5;
	int effsz = siz[z];
	int szofspe = 0;
	for(int x:v[z]){
		if(x == p) continue;
		if(vis[x]){
			ret = dep[x];
			continue;
		}
		int tmp = dfs2(x,z);
		if(tmp <= dep[z]){
			szofspe = siz[x];
			effsz -= szofspe;
		}
		amin(ret,tmp);
	}
	if(ret < dep[z]){
		// case B
		ans += (n - siz[z]) * effsz;
	}
	if(ret == dep[z]){
		// case A
		// do nothing
	}
	
	return ret;
}

void solve(){
	cin >> n;
	ans = n * (n - 1) / 2;
	
	for(int i = 1; i <= n; i++){
		v[i].clear();
		vis[i] = 0;
		siz[i] = 1;
		dep[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs1(1,0);
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
	}
	
	dfs2(1,0);
	
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