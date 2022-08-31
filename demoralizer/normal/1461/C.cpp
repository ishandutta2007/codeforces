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

double dp[N][2]; // id,taken
int a[N];

void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,1,n+1){
		cin >> a[i];
	}
	
	int cnt = 0;
	for(int i = n; i > 0; i--){
		if(a[i] == i) cnt++;
		else break;
	}
	
	int req = n - cnt;
	vector<double> valid;
	
	rep(i,0,m){
		int r;
		double p;
		cin >> r >> p;
		if(r >= req){
			valid.pb(p);
		}
	}
	
	if(req == 0){
		cout << 1.0 << "\n";
		return;
	}
	
	m = sz(valid);
	
	dp[0][0] = 1;
	
	rep(i,1,m+1){
		// cout << valid[i-1] << "\n";
		// valid[i-1]  followed or not followed
		
		dp[i][0] = dp[i-1][0] * (1-valid[i-1]);
		dp[i][1] = dp[i-1][0] * valid[i-1] + dp[i-1][1];
	}
	
	cout << dp[m][1] << "\n";
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cout<<setprecision(9);
	cout<<fixed;
	
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