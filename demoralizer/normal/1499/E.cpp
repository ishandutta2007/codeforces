#include "bits/stdc++.h"
using namespace std;
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

const int N=1005;

string x,y;
int dp[N][N][3][4];

int calc(int a,int b,int last,int started){
	if(dp[a][b][last][started] != -1){
		return dp[a][b][last][started];
	}
	int ans = (started == 3);
	char pc;
	if(last == 2){
		pc = 'z' + 1;
	}
	else{
		pc = ((last == 0)?x[a-1]:y[b-1]);
	}
	
	if(a < sz(x) && x[a] != pc){
		ans = (ans + calc(a+1,b,0,started | 1)) % M;
	}
	
	if(b < sz(y) && y[b] != pc){
		ans = (ans + calc(a,b+1,1,started | 2)) % M;
	}
	return dp[a][b][last][started] = ans;
}

void solve(){
	mem1(dp);
	cin >> x >> y;
	
	int ans = 0;
	rep(i,0,sz(x)){
		rep(j,0,sz(y)){
			
			ans = (ans + calc(i,j,2,0)) % M;
		}
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
	//cin>>t;
	while(t--) solve();
	return 0;
}