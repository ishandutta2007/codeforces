#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

const int N=5005;

int c[N],l[N],r[N],dp[N][N];

void solve(){
	int n;
	cin>>n;
	rep(i,1,n+1){
		cin>>c[i];
		if(c[i]==c[i-1])l[i]=l[i-1];
		else l[i]=i;
		rep(j,1,n+1)dp[i][j]=INF;
	}
	for(int i=n;i>0;i--){
		if(c[i]==c[i+1])r[i]=r[i+1];
		else r[i]=i;
	}
	dp[1][n]=0;
	rep(i,1,n+1){
		for(int j=n;j>=i;j--){
			if(i>1){
				amin(dp[i][j],1+dp[l[i-1]][j]);
			}
			if(j<n){
				amin(dp[i][j],1+dp[i][r[j+1]]);
			}
			if(i>1 && j<n && c[i-1]==c[j+1]){
				amin(dp[i][j],1+dp[l[i-1]][r[j+1]]);
			}
		}
	}
	int ans=INF;
	rep(i,1,n+1){
		amin(ans,dp[i][r[i]]);
		i=r[i];
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}