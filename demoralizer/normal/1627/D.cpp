#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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

const int N=1e6+5;

int p[N];
int vis[N];
int ans = 0;

int dfs(int z,int k){
	vis[z] = 1;
	int cnt = 0;
	for(int x = 2 * z; x < N; x += z){
		if(vis[x] || !p[x]) continue;
		cnt += dfs(x,k);
	}
	if(cnt > 1 && !p[z] && k == z){
		ans++;
		p[z] = 1;
	}
	return p[z];
}

void solve(){
	int n;
	cin >> n;
	
	vector<int> a(n);
	
	rep(i,0,n){
		cin >> a[i];
		p[a[i]] = 1;
	}
	
	for(int i = N - 1; i >= 1; i--){
		for(int j = 2 * i; j < N; j += i){
			vis[j] = 0;
		}
		dfs(i,i);
	}
	
	cout << ans;
	
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