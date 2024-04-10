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
const int32_t M=998244353;

const int N=1e3+5;

int dp[N][N];
int a[N][N];
vector<pii> cells[N * N];

int32_t mod_inv(int32_t a, int32_t m = M) {
	int32_t g = m, r = a, x = 0, y = 1;
	while (r != 0) {
		int32_t q = g / r;
		g %= r; swap(g, r);
		x -= q * y; swap(x, y);
	}
	return x < 0 ? x + m : x;
}

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> c;
	rep(i,0,n){
		rep(j,0,m){
			cin >> a[i][j];
			c.pb(a[i][j]);
		}
	}
	sort(all(c));
	uniq(c);
		
	rep(i,0,n){
		rep(j,0,m){
			a[i][j] = lower_bound(all(c),a[i][j]) - c.begin();
			cells[a[i][j]].pb({i,j});
		}
	}
	
	int add = 0, sigmai = 0, sigmaj = 0, cnt = 0;
	
	rep(yo,0,sz(c)){
		if(yo)
		for(auto x:cells[yo]){
			int i = x.fr, j = x.sc;
			dp[i][j] = (i * i + j * j) % M;
			int sub = 2 * (i * sigmai + j * sigmaj) % M;
			int tmp = (add - sub + M) % M * mod_inv(cnt) % M;
			dp[i][j] = (dp[i][j] + tmp) % M;
		}
		
		for(auto x:cells[yo]){
			int i = x.fr, j = x.sc;
			sigmai += i;
			sigmaj += j;
			cnt++;
			add = (add + dp[i][j] + i * i + j * j) % M;
		}
	}	
	{
		int r,c;
		cin >> r >> c;
		cout << dp[r-1][c-1];
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