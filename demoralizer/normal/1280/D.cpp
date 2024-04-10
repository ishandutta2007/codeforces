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

const long long INF=1e17;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=3005;

pii operator+ (const pii& x, const pii& y){
	return {x.fr + y.fr, x.sc + y.sc};
}

vector<vector<int>> v;
int val[N];
int siz[N];

pii tmp[N];
pii dp[N][N]; // dp[node][parts] = {max parts,max vote advt}
void dfs(int z,int p = 0){
	siz[z] = 1;
	dp[z][0] = {0,val[z]};
	for(int x:v[z]){
		if(x == p) continue;
		dfs(x,z);
		// merge dp[x] with dp[z]
		siz[z] += siz[x];
		rep(i,0,siz[z]){
			tmp[i] = {-INF,-INF};
		}
		
		rep(i,0,siz[x]){
			// i extra parts
			rep(j,0,siz[z] - siz[x]){
				amax(tmp[i+j], dp[x][i] + dp[z][j]);
				amax(tmp[i+j+1],pii{dp[x][i].fr + (dp[x][i].sc > 0),0} + dp[z][j]);
			}
		}
		
		rep(i,0,siz[z]){
			dp[z][i] = tmp[i];
		}
	}
}

void solve(){
	int n,m;
	v.clear();
	cin >> n >> m;
	v.resize(n + 1);
	
	rep(i,1,n+1){
		int x;
		cin >> x;
		val[i] = -x;
	}
	rep(i,1,n+1){
		int x;
		cin >> x;
		val[i] += x;
	}
	
	rep(i,1,n+1){
		rep(j,1,n+1){
			dp[i][j] = {0,-INF};
		}
	}
	
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs(1);
	int ans = dp[1][m - 1].fr + (dp[1][m - 1].sc > 0);
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