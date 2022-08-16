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

const int N=1e6+5;

int cnt = 0;
map<string, int> mp;
vector<int> v[N];
int g[45];
int dp[N];
bool vis[N];

int calc(int mask){
	if(mask == 0) return 0;
	if(mask < N){
		if(vis[mask]){
			return dp[mask];
		}
		vis[mask] = 1;
	}
	int fr = 63 - __builtin_clzll(mask);
	// cout << mask << " " << fr << endl;
	int ans = calc(mask ^ (1ll << fr));
	amax(ans,1 + calc(mask & (~g[fr])));
	if(mask < N){
		dp[mask] = ans;
	}
	return ans;
}

void solve(){
	int n,m;
	cin >> n >> m;
	
	int last = -1;
	rep(i,0,n){
		int x;
		cin >> x;
		if(x == 1){
			last = i;
			continue;
		}
		string s;
		cin >> s;
		if(!mp.count(s))
			mp[s] = cnt++;
		int tmp = mp[s];
		if(last != -1){
			v[last].pb(tmp);
		}
	}
	
	rep(i,0,n){
		int x = 0;
		for(int y:v[i]){
			x |= (1ll << y);
		}
		for(int y:v[i]){
			g[y] |= x;
		}
	}
	
	cout << calc((1ll << cnt) - 1);
	// cout << 3;
	
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