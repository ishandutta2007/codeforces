#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(pair<int,int> x) const { return (x.first + x.second) ^ RANDOM; }
};
vector<gp_hash_table<pair<int,int>, null_type, chash>> seen;
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

const int N=3005;

int ok(string &s){
	if(s == "1100" || s == "1010" || s == "0111" || s == "1111"){
		return 0;
	}
	return 1;
}

int base;
int a[N];
int b[N];
int h[N];
int g[N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto dist=uniform_int_distribution<int>(1000,100005);

int dp[N][N];

void solve(){
	base = dist(rng);
	int m;
	cin >> m;
	seen.resize(m);
	string s;
	rep(i,0,m){
		int x;
		cin >> x;
		s.pb('0'+x);
	}
	
	a[0] = 1;
	b[0] = 1;
	rep(i,0,m){
		a[i + 1] = a[i] * base % M;
		b[i + 1] = b[i] * base % MM;
		h[i + 1] = (s[i] * a[i] + h[i]) % M;
		g[i + 1] = (s[i] * b[i] + g[i]) % MM;
	}
	
	auto hsh = [&](int l, int r){
		return pii{(h[r + 1] + M - h[l]) * a[m-1-r] % M,
			(g[r + 1] + MM - g[l]) * b[m-1-r] % MM};
	};
	
	auto valid = [&](int l, int r){
		string t;
		rep(i,l,r+1){
			t += s[r+l-i];
		}
		return ok(t);
	};
	
	int ans = 0;
	rep(r,0,m){
		rep(l,0,r+1){
			// dp[l][r]
			string t = "";
			if(l <= r - 1){
				t += s[r];
				dp[l][r] += dp[l][r-1];
			}
			if(l <= r - 2){
				t += s[r-1];
				dp[l][r] += dp[l][r-2];
			}
			if(l <= r - 3){
				t += s[r-2];
				dp[l][r] += dp[l][r-3];
			}
			if(l <= r - 4){
				t += s[r-3];
				if(ok(t)) dp[l][r] += dp[l][r-4];
			}
			
			if(r - l + 1 <= 4 && (r - l + 1 <= 3 || valid(l,r))){
				dp[l][r]++; 
			}
			dp[l][r] %= M;
			pii z = hsh(l,r);
			if(seen[r-l].find(z) == seen[r-l].end()){
				ans = (ans + dp[l][r]) % M;
				seen[r-l].insert(z);
			}
		}
		cout << ans << "\n";
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