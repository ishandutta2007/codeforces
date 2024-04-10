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
vector<int> v[N];
vector<int> e;

int dfs(int z,int p = 0){
	int s = 1;
	for(int x:v[z]){
		if(x == p){
			continue;
		}
		s += dfs(x,z);
	}
	e.pb((n - s) * s);
	return s;
}

void solve(){
	cin >> n;
	rep(i,1,n+1){
		v[i].clear();
	}
	
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	e.clear();
	dfs(1);
	sort(all(e));
	reverse(all(e));
	int m;
	cin >> m;
	vector<int> p(m);
	rep(i,0,m){
		cin >> p[i];
	}
	sort(all(p));
	while(sz(p) > n - 1){
		int x = p.back();
		p.ppb();
		p.back() = (p.back() * x) % M;
	}
	reverse(all(p));
	while(sz(p) < n - 1){
		p.pb(1);
	}
	int ans = 0;
	rep(i,0,n-1){
		ans += e[i] % M * p[i] % M;
		ans %= M;
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