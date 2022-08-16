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

const int N=405;

int32_t dp[N][N][N];

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n+1);
	rep(i,1,n+1){
		cin >> a[i];
	}
	
	rep(d,1,n){
		for(int l = 1, r = l + d; r <= n; l++, r++){
			dp[l][r][0] = a[r] - a[l];
			int checkpoint = r - 1;
			rep(f,1,n+1){
				int d1 = a[checkpoint] - a[l];
				int d2 = dp[checkpoint][r][f-1];
				dp[l][r][f] = max(d1, d2);
				while(d1 > d2){
					checkpoint--;
					d1 = a[checkpoint] - a[l];
					d2 = dp[checkpoint][r][f-1];
					amin(dp[l][r][f], max(d1, d2));
				}
				checkpoint++;
			}
		}
	}
	
	int ans = 0;
	while(m--){
		int s,f,c,r;
		cin >> s >> f >> c >> r;
		amax(ans,c * dp[s][f][r]);
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