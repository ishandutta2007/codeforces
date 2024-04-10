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

const int N=0;



void solve(){
	int n,m;
	cin >> n >> m;
	
	string s[n];
	vector<vector<int>> l(n,vector<int>(m));
	vector<vector<int>> r(n,vector<int>(m));
	
	rep(i,0,n){
		cin >> s[i];
		int cnt = 0;
		rep(j,0,m){
			if(s[i][j] == '.'){
				cnt = 0;
				continue;
			}
			l[i][j] = cnt;
			cnt++;
		}
		
		cnt = 0;
		for(int j = m - 1; j >= 0; j--){
			if(s[i][j] == '.'){
				cnt = 0;
				continue;
			}
			r[i][j] = cnt;
			cnt++;
		}
	}
	
	int ans = 0;
	
	rep(i,0,n){
		rep(j,0,m){
			if(s[i][j] == '.') continue;
			ans++;
			for(int h = 1; i + h < n; h++){
				if(l[i+h][j] < h || r[i+h][j] < h) break;
				ans++;
			}
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
	cin>>t;
	while(t--) solve();
	return 0;
}