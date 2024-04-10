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



void solve(){
	int n;
	string s;
	cin >> n >> s;
	vector<int> a(n + 1);
	rep(i,1,n+1){
		cin >> a[i];
		rep(j,1,i){
			amax(a[i], a[j] + a[i - j]);
		}
	}
	
	vector<int> v(1,1);
	rep(i,1,n){
		if(s[i] == s[i - 1]){
			v.back()++;
		}
		else{
			v.pb(1);
		}
	}
	
	int sum = n;
	n = sz(v);
	
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(sum)));
	// dp[l][r][add]
	
	rep(d,0,n){
		for(int l = 0, r = d; r < n; l++, r++){
			rep(add,0,sum){
				if(l == r){
					dp[l][r][add] = a[v[l] + add];
				}
				else{
					dp[l][r][add] = a[v[l] + add] + dp[l + 1][r][0];
					for(int nex = l + 2; nex < n; nex += 2){
						int na = add + v[l];
						if(na >= sum) continue;
						amax(dp[l][r][add], dp[nex][r][na] + dp[l + 1][nex - 1][0]);
					}
				}
			}
		}
	}
	
	cout << dp[0][n-1][0];
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