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

set<pii> blocked;
vector<int> coordinates; // of important horizontal coords
int r[N],c[N];

void solve(){
	int n,m;
	cin >> n >> m;
	blocked.clear();
	coordinates.clear();
	rep(i,0,m){
		cin >> r[i] >> c[i];
		blocked.insert({r[i],c[i]});
		coordinates.pb(c[i]);
	}
	
	sort(all(coordinates));
	uniq(coordinates);
	
	int cnt = sz(coordinates);
	
	vector<vector<int>> dp(cnt,vector<int>(4));
	// cnt * 4 matrix called dp
	int x = coordinates[0];
	if(blocked.count({1,x}) && blocked.count({2,x})){
		dp[0][3] = 1;
	}
	else if(blocked.count({1,x})){
		dp[0][1] = 1; // {1,x}
	}
	else{
		dp[0][2] = 1; // {2,x}
	}
	
	rep(i,1,cnt){
		// dp[i]
		int x = coordinates[i];
		int prevx = coordinates[i-1];
		
		if(dp[i-1][3]){
			if(blocked.count({1,x}) && blocked.count({2,x})){
				dp[i][3] = 1;
			}
			else if(blocked.count({1,x})){
				dp[i][1] = 1;
			}
			else{
				dp[i][2] = 1;
			}
		}
		int parity = (x - prevx) % 2;
		if((dp[i-1][2] && parity) || (dp[i-1][1] && parity == 0)){
			// the (1,0) profile on prev step
			// {1,x} must be free
			if(!blocked.count({1,x})){
				// {2,x} is occupied
				dp[i][3] = 1;
			}
		}
		if((dp[i-1][2] && parity == 0) || (dp[i-1][1] && parity)){
			// the (0,1) profile on prev step
			if(!blocked.count({2,x})){
				// {1,x} occupied
				dp[i][3] = 1;
			}
		}
				
	}
	
	if(dp[cnt-1][3]){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	
	// ans is yes if dp[cnt-1][3] = 1
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