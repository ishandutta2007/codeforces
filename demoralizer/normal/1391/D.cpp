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

const int N=1e6+5;

int a[3][N];

void solve(){
	int n,m;
	cin>>n>>m;
	string s[n];
	rep(i,0,n) cin>>s[i];
	
	if(min(n,m) == 1){
		cout << 0;
		return;
	}
	
	if(min(n,m) > 3){
		cout << -1;
		return;
	}
	
	if(n < m){
		rep(i,0,n){
			rep(j,0,m){
				a[i][j] = s[i][j] - '0';
			}
		}
	}
	else{
		rep(i,0,n){
			rep(j,0,m){
				a[j][i] = s[i][j] - '0';
			}
		}
		swap(n,m);
	}
	
	if(n == 2){
		int tmp1 = 0, tmp2 = 0;
		rep(j,0,m){
			if((j % 2) ^ ((a[0][j] + a[1][j]) % 2)) tmp1++;
			else tmp2++;
		}
		cout << min(tmp1,tmp2);
	}
	else{
		int ans[4] = {m,m,m,m};
		rep(j,0,m){
			int p1 = (a[0][j] + a[1][j]) % 2, p2 = (a[1][j] + a[2][j]) % 2;
			int p = 2 * p1 + p2;
			if(j%2) ans[p]--;
			else ans[p^3]--;
		}
		cout << min({ans[0], ans[1], ans[2], ans[3]});
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
	// cin>>t;
	while(t--) solve();
	return 0;
}