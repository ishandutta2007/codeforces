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

const int N=0;

int b1,b2;
vector<int> pb1;
vector<int> pb2;

struct hsh{
	int n;
	vector<int> a1,a2;
	hsh(string &s){
		n = sz(s);
		a1.resize(n+1);
		a2.resize(n+1);
		if(sz(pb1) == 0){
			pb1.pb(1);
			pb2.pb(1);
		}
		while(sz(pb1) < n + 5){
			pb1.pb(pb1.back() * b1 % M);
			pb2.pb(pb2.back() * b2 % MM);
		}
		rep(i,0,n){
			a1[i+1] = (a1[i] + s[i] * pb1[i]) % M;
			a2[i+1] = (a2[i] + s[i] * pb2[i]) % MM;
		}
	}
	pii sub(int l,int r){
		int x1 = (a1[r+1] - a1[l] + M) * pb1[n - r] % M;
		int x2 = (a2[r+1] - a2[l] + MM) * pb2[n - r] % MM;
		return {x1,x2};
	}
};

void solve(){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	auto dist=uniform_int_distribution<int>(200,4000);
	b1 = dist(rng), b2 = dist(rng);
	
	int n,m;
	string s;
	cin >> n >> m >> s;
	
	string k[26];
	vector<hsh> h;
	vector<vector<int>> dp(26,vector<int>(n+1));
	rep(i,0,26){
		k[i].resize(n);
		rep(j,0,n){
			if(s[j] == 'a' + i) k[i][j] = '#';
			else k[i][j] = '.';
		}
		h.pb(k[i]);
		dp[i][n] = n;
		for(int j = n - 1; j >= 0; j--){
			dp[i][j] = dp[i][j+1];
			if(k[i][j] == '#') dp[i][j] = j;
		}
	}
	
	rep(zz,0,m){
		int x,y,len;
		cin >> x >> y >> len;
		x--;
		y--;
		vector<pii> dx,dy;
		rep(i,0,26){
			if(dp[i][x] < x + len) dx.pb({dp[i][x],i});
			if(dp[i][y] < y + len) dy.pb({dp[i][y],i});
		}
		sort(all(dx));
		sort(all(dy));
		if(sz(dx) != sz(dy)){
			cout << "NO\n";
			continue;
		}
		bool found = 1;
		rep(i,0,sz(dx)){
			int a = dx[i].sc;
			int b = dy[i].sc;
			if(h[a].sub(x,x+len-1) != h[b].sub(y,y+len-1)){
				found = 0;
			}
		}
		if(found){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
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