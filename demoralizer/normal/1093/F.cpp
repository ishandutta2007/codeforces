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

const int N=0;



void solve(){
	int n,k,len;
	cin >> n >> k >> len;
	if(len == 1){
		cout << 0;
		return;
	}
	vector<int> a(n);
	for(int &x:a){
		cin >> x;
		if(x != -1) x--;
	}
	
	vector<vector<int>> dp(n,vector<int>(k));
	vector<int> tot(n);
	if(a[0] == -1){
		rep(j,0,k){
			dp[0][j] = 1;
			tot[0]++;
		}
	}
	else{
		dp[0][a[0]] = 1;
		tot[0]++;
	}
	
	auto pf = dp;
	
	
	
	vector<vector<int>> till(n,vector<int>(k,n));
	rep(j,0,k){
		rep(i,0,n){
			if(a[i] == j || a[i] == -1){
				till[i][j] = i;
				if(i) amin(till[i][j], till[i-1][j]);
			}
		}
	}
	
	auto get = [&](int l, int r){
		int ans = tot[r];
		if(l) ans = (tot[r] + M - tot[l - 1]) % M;
		return ans;
	};
	
	auto getb = [&](int j, int l, int r){
		int ans = pf[r][j];
		if(l) ans = (pf[r][j] + M - pf[l - 1][j]) % M;
		return ans;
	};
	
	rep(i,1,n){
		rep(j,0,k){
			int t = max(till[i][j] - 1, i - len + 1);
			if(t >= i){
				continue;
			}
			if(t == -1){
				dp[i][j] = 1;
			}
			amax(t,0);
			dp[i][j] = (dp[i][j] + get(t, i - 1) + M - getb(j,t,i-1)) % M;
		}
		tot[i] = tot[i - 1];
		rep(j,0,k){
			pf[i][j] = (pf[i-1][j] + dp[i][j]) % M;
			tot[i] = (tot[i] + dp[i][j]) % M;
		}
	}
	
	int ans = 0;
	rep(j,0,k){
		ans = (ans + dp[n - 1][j]) % M;
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