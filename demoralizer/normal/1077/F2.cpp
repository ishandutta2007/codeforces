#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 10000000000000007LL
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template<typename T1,typename T2>std::istream& operator>>(std::istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a){out<<a.fr<<" "<<a.sc;return out;}

const int N=5005;

int a[N];
int dp[N][N];

void solve(){
	int n,k,x;
	cin>>n>>k>>x;
	rep(i,1,n+1)cin>>a[i];
	rep(i,0,N)rep(j,0,N)dp[i][j]=-M;
	dp[0][0]=0;
	deque<int> q;
	rep(j,1,x+1){
		q.pb(dp[0][j-1]);
		rep(i,1,n+1){
			if(i>k && dp[i-k-1][j-1]==q.front())q.ppf();
			dp[i][j]=q.front()+a[i];
			while(!q.empty() && dp[i][j-1]>q.back())q.ppb();
			q.pb(dp[i][j-1]);
			// cout<<dp[i][j]<<"\n";
		}
		q.clear();
	}
	int ans=-1;
	rep(i,n+1-k,n+1){
		amax(ans,dp[i][x]);
		// cout<<dp[i][x]<<" ";
	}
	cout<<ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}