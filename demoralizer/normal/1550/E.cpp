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

int n,k;
string s;

int val[N][17];
int na[N][17];

bool allowed(int x,int k,int len){
	if(x + len > n){
		return false;
	}
	return (val[x+len][k] - val[x][k] == 0);
}

int dp[1<<17];

bool check(int len){
	rep(i,0,k){
		na[n][i] = INF;
	}
	for(int i = n - 1; i >= 0; i--){
		rep(j,0,k){
			na[i][j] = na[i+1][j];
			if(allowed(i,j,len)) na[i][j] = i;
		}
	}
	
	dp[0] = 0;
	rep(mask,1,(1<<k)){
		dp[mask] = INF;
		rep(i,0,k){
			if(mask >> i & 1){
				int other_mask = mask ^ (1 << i);
				if(dp[other_mask] == INF) continue;
				amin(dp[mask],na[dp[other_mask]][i]+len);
			}
		}
	}
	
	return (dp[(1<<k) - 1] <= n);
}

void solve(){
	cin >> n >> k >> s;
	
	rep(i,0,n){
		rep(j,0,k){
			val[i + 1][j] = ((s[i] - 'a') != j && s[i] != '?') + val[i][j];
		}
	}
	
	int L = 1, U = n;
	int ans = 0;
	while(L <= U){
		int m = (L + U) / 2;
		if(check(m)){
			ans = m;
			L = m + 1;
		}
		else{
			U = m - 1;
		}
	}
	cout << ans;
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