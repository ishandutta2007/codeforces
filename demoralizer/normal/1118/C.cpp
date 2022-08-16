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

const int N=2000;

int c[N];

void solve(){
	int n;
	cin >> n;
	rep(i,0,n*n){
		int x;
		cin >> x;
		c[x]++;
	}
	int f[4] = {0};
	rep(i,0,N){
		f[c[i]%4]++;
	}
	if(n % 2){
		if(f[1] + f[3] > 1){
			cout << "NO\n";return;
		}
		int e = 0;
		while(c[e] % 2 == 0) e++;
		c[e]--;
		vector<vector<int>> ans(n,vector<int>(n));
		ans[n/2][n/2] = e;
		e = 0;
		bool flag = 1;
		rep(i,0,n/2){
			while(c[e] % 4 != 2 && e < 1003 && flag) e++;
			if(e == 1003){
				e = 0;
				flag = 0;
			}
			if(!flag){
				while(c[e] == 0){
					e++;
				}
			}
			ans[n/2][i] = ans[n/2][n - 1 - i] = e;
			c[e] -= 2;
		}
		rep(i,0,n/2){
			while(c[e] % 4 != 2 && e < 1003 && flag) e++;
			if(e == 1003){
				e = 0;
				flag = 0;
			}
			if(!flag){
				while(c[e] == 0){
					e++;
				}
			}
			ans[i][n/2] = ans[n - 1 - i][n/2] = e;
			c[e] -= 2;
		}
		rep(i,0,N){
			if(c[i] % 4 == 2){
				cout << "NO\n";
				return;
			}
		}
		e = 0;
		rep(i,0,n/2){
			rep(j,0,n/2){
				while(c[e] == 0) e++;
				ans[i][j] = ans[n - 1 - i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][n - 1 - j] = e;
				c[e] -= 4;
			}
		}
		cout << "YES\n";
		rep(i,0,n){
			rep(j,0,n){
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else{
		if(f[3] || f[1] || f[2]){
			cout << "NO";
			return;
		}
		vector<vector<int>> ans(n,vector<int>(n));
		int e = 0;
		rep(i,0,n/2){
			rep(j,0,n/2){
				while(c[e] == 0) e++;
				ans[i][j] = ans[n - 1 - i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][n - 1 - j] = e;
				c[e] -= 4;
			}
		}
		cout << "YES\n";
		rep(i,0,n){
			rep(j,0,n){
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
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