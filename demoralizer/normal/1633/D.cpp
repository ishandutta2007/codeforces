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

const int N=1005;

int dis[1005];
int mx = 0;

void once(){
	dis[1] = 0;
	for(int i = 2; i < N; i++){
		dis[i] = INF;
	}
	
	queue<int> q;
	q.push(1);
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		for(int x = 1; x < N; x++){
			// cur -> cur + cur / x
			int nex = cur + cur / x;
			if(nex >= N) continue;
			int ndis = dis[cur] + 1;
			if(dis[nex] == INF){
				dis[nex] = ndis;
				q.push(nex);
			}
		}
	}
	
	rep(i,1,N){
		amax(mx,dis[i]);
	}
	
}

void solve(){
	int n,k;
	cin >> n >> k;
	
	if(k > mx * n) k = mx * n;
	
	vector<int> b(n),v(n);
	vector<int> w(n);
	
	rep(i,0,n){
		cin >> b[i];
		w[i] = dis[b[i]];
	}
	rep(i,0,n){
		cin >> v[i];
	}
	
	// k -> capacity
	// dp[ind][weight]
	vector<vector<int>> dp(n,vector<int>(k+1));
	
	dp[0][0] = 0;
	if(w[0] <= k){
		dp[0][w[0]] = v[0];
	}
	
	rep(i,1,n){
		rep(j,0,k+1){
			dp[i][j] = dp[i-1][j];
			if(j >= w[i]){
				amax(dp[i][j] , v[i] + dp[i-1][j - w[i]]);
			}
		}
	}
	
	int ans = 0;
	rep(j,0,k+1){
		amax(ans, dp[n-1][j]);
	}
	
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
	once();
	while(t--) solve();
	return 0;
}