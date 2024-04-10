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

bool a[N];
bool f[N];
bool ypar[N];
bool foundy;
vector<vector<int>> v;
int y,ans;

bool dfs1(int z, int p = 0){
	bool ans = a[z];
	ypar[z] = (z == y);
	for(int x:v[z]){
		if(x == p) continue;
		ans |= dfs1(x,z);
		ypar[z] |= ypar[x];
	}
	return f[z] = ans;
}

void dfs2(int z, int p = 0){
	for(int x:v[z]){
		if(x == p || !f[x]) continue;
		ans++;
		dfs2(x,z);
	}
	if(z == y) foundy = 1;
	if(!foundy) ans++;
}

void solve(){
	int n,k;
	cin >> n >> k;
	
	ans = 0;
	foundy = 0;
	v.clear();
	v.resize(n+1);
	rep(i,1,n+1){
		a[i] = f[i] = ypar[i] = 0;
	}
	
	int x;
	cin >> x >> y;
	
	rep(i,0,k){
		int x;
		cin >> x;
		a[x] = 1;
	}
	a[y] = 1;
	
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs1(x);
	rep(i,1,n+1){
		sort(all(v[i]), [&](int x, int y){
			return ypar[x] < ypar[y];
		});
	}
	
	dfs2(x);
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