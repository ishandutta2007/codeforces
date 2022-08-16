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

int k[N];
int m[N];
int ans[N][2520];
int vis[N][2520];

vector<int> e[N];

int normalize(int x,int mod = 2520){
	return ((x % mod) + mod) % mod;
}

int used[N];
vector<int> v;

int dfs(int x,int y,int tim){
	if(ans[x][y] != -1){
		return ans[x][y];
	}
	if(vis[x][y] != -1){
		ans[x][y] = 0;
		rep(i,vis[x][y],tim){
			ans[x][y] += !used[v[i]];
			used[v[i]] = 1;
		}
		rep(i,vis[x][y],tim){
			used[v[i]] = 0;
		}
		// return ans[x][y];
	}
	if(ans[x][y] == -1){
		vis[x][y] = tim;
		v.pb(x);
		int c = normalize(y + k[x]);
		ans[x][y] = dfs(e[x][c % m[x]],c,tim+1);
		vis[x][y] = -1;
		v.ppb();
	}
	return ans[x][y];
}

void solve(){
	mem1(ans);
	mem1(vis);
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> k[i];
	}
	rep(i,1,n+1){
		cin >> m[i];
		rep(j,0,m[i]){
			int x;
			cin >> x;
			e[i].pb(x);
		}
	}
	
	int q;
	cin >> q;
	while(q--){
		int x,y;
		cin >> x >> y;
		y = normalize(y);
		
		cout << dfs(x,y,0) << "\n";
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