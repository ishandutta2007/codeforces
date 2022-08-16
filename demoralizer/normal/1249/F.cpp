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

const int N=1e5+5;

int n,k;
int a[N],dp[205][205];


vector<int> v[N];
void dfs(int z,int p){
	int colsum[205];
	rep(i,0,k+1){
		colsum[i]=0;
	}
	for(int x:v[z]){
		if(x==p)continue;
		dfs(x,z);
		rep(i,0,k+1){
			colsum[i]+=dp[x][i];
		}
	}
	dp[z][0]=a[z]+colsum[k-1];
	for(int x:v[z]){
		if(x==p)continue;
		rep(i,0,k){
			amax(dp[z][i+1],dp[x][i]+colsum[max(k-2-i,i)]-dp[x][max(k-2-i,i)]);
		}
	}
	for(int i=k-1;i>=0;i--){
		amax(dp[z][i],dp[z][i+1]);
		// cout<<z<<" "<<i<<" "<<dp[z][i]<<"\n";
	}
}

void solve(){
	cin>>n>>k;k++;
	rep(i,1,n+1){
		cin>>a[i];
	}
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,1);
	cout<<dp[1][0]<<"\n";
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