#include <bits/stdc++.h>
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

bool dp[N][2*N];
int pre[N][2*N];

void solve(){
	int n,k;
	string s;
	cin>>n>>k>>s;
	s='&'+s;
	dp[0][N]=1;
	rep(i,1,n+1){
		if(s[i]=='L' || s[i]=='?'){
			rep(j,N-k+1,N+k){
				dp[i][j] |= dp[i-1][j+1];
				if(dp[i-1][j+1])pre[i][j]=j+1;
			}
			if(i==n){
				dp[i][N-k] |= dp[i-1][N-k+1];
				if(dp[i-1][N-k+1])pre[i][N-k]=N-k+1;
			}
		}
		if(s[i]=='W' || s[i]=='?'){
			rep(j,N-k+1,N+k){
				dp[i][j] |= dp[i-1][j-1];
				if(dp[i-1][j-1])pre[i][j]=j-1;
			}
			if(i==n){
				dp[i][N+k] |= dp[i-1][N+k-1];
				if(dp[i-1][N+k-1])pre[i][N+k]=N+k-1;
			}
		}
		if(s[i]=='D' || s[i]=='?'){
			rep(j,N-k+1,N+k){
				dp[i][j] |= dp[i-1][j];
				if(dp[i-1][j])pre[i][j]=j;
			}
		}
	}
	int j;
	if(dp[n][N+k]){
		j=N+k;
	}
	else if(dp[n][N-k]){
		j=N-k;
	}
	else{
		cout<<"NO";
		return;
	}
	
	string ans;
	for(int i=n;i>0;i--){
		if(pre[i][j] == j){
			ans.pb('D');
		}
		else if(pre[i][j] == j+1){
			ans.pb('L');
			j++;
		}
		else{
			ans.pb('W');
			j--;
		}
	}
	reverse(all(ans));
	cout<<ans;
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