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

int c[N];
int dp[N][2];
bool pick[N];
bool eq[N];
int worst[N];
vector<vector<int>> v;
vector<int> ans;

void dfs(int z, int p = 0){
	vector<int> tmp;
	for(int x:v[z]){
		if(x == p) continue;
		dfs(x,z);
		dp[z][0] += dp[x][0];
		tmp.pb(dp[x][1] - dp[x][0]);
	}
	sort(all(tmp));
	if(sz(tmp)){
		if(sz(tmp) > 1 && tmp[0] == tmp[1]){
			eq[z] = true;
		}
		dp[z][1] = dp[z][0] + tmp[0];
		worst[z] = tmp[0];
		if(dp[z][1] + c[z] < dp[z][0]){
			pick[z] = true;
			dp[z][0] = dp[z][1] + c[z];
		}
	}
	else{
		dp[z][0] = c[z];
		pick[z] = true;
	}
}

void dfs2(int z, int p = 0, int flag = 0){
	bool unpicked = 1;
	if(!flag && pick[z]){
		ans.pb(z);
		unpicked = 0;
	}
	else if(!flag && worst[z] + c[z] == 0){
		ans.pb(z);
	}
	for(int x:v[z]){
		if(x == p) continue;
		if((flag == 0 && unpicked) || eq[z]){
			dfs2(x,z,0);
		}
		else{
			dfs2(x,z,(worst[z] == dp[x][1] - dp[x][0]));
		}
	}
}
void solve(){
	int n;
	cin >> n;
	v.resize(n+1);
	
	rep(i,1,n+1){
		cin >> c[i];
	}
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs(1);
	dfs2(1);
	
	sort(all(ans));
	uniq(ans);
	
	cout << dp[1][0] << " " << sz(ans) << "\n";
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