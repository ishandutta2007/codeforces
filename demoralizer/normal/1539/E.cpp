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

int k[N];
int a[2][N];
int b[2][N];

set<int> ind;
int s[2][N];

int dp[2][N];
int best[2][N];

void solve(){
	int n,m;
	cin >> n >> m;
	
	rep(i,1,n+1){
		cin >> k[i];
		rep(j,0,2){
			cin >> a[j][i] >> b[j][i];
		}
	}
	
	rep(j,0,2){
		ind.clear();
		rep(i,1,n+2){
			ind.insert(i);
		}
		
		vector<array<int,3>> v;
		rep(i,1,n+1){
			v.pb({a[j][i],0,i});
			v.pb({k[i],1,i});
			v.pb({b[j][i],2,i});
		}
		
		v.pb({0,1,0});
		sort(all(v));
		
		for(auto z:v){
			int opr = z[1];
			int x = z[2];
			if(opr == 0){
				ind.erase(x);
			}
			else if(opr == 1){
				s[j][x] = *ind.lower_bound(x) - 1;
			}
			else{
				ind.insert(x);
			}
		}
	}
	
	dp[0][0] = dp[1][0] = -1;
	if(s[1][0] >= 0) dp[0][0] = s[0][0];
	if(s[0][0] >= 0) dp[1][0] = s[1][0];
	
	rep(i,1,n+1){
		rep(j,0,2){
			dp[j][i] = -1;
			if(dp[!j][i-1] >= i){
				dp[j][i] = s[j][i];
				best[j][i] = 0;
			}
			if(s[!j][i] >= i && dp[j][i] < dp[j][i - 1]){
				dp[j][i] = dp[j][i - 1];
				best[j][i] = 1;
			}
		}
	}
	
	// rep(j,0,2){
	// 	rep(i,0,n+1){
	// 		cout << dp[j][i] << " ";
	// 	}
	// 	cout << "\n";
	// }
	
	if(dp[0][n] >= n || dp[1][n] >= n){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
		return;
	}
	
	vector<int> ans;
	int i = n;
	int j = -1;
	while(i > 0){
		if(j == -1){
			if(dp[0][i] >= i) j = 0;
			else j = 1;
		}
		if(best[j][i] == 0){
			ans.pb(j);
			j ^= 1;
		}
		else{
			ans.pb(!j);
		}
		i--;
	}
	
	reverse(all(ans));
	for(int x:ans){
		cout << x << " ";
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