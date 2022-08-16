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
	vector<vector<string>> a(n,vector<string>(m)),b(n,vector<string>(m));
	vector<array<int,4>> ans,z;
	
	vector<vector<int>> cnt(n,vector<int>(2)),req(n,vector<int>(2));
	
	rep(i,0,n){
		rep(j,0,m){
			cin >> a[i][j];
			reverse(all(a[i][j]));
			// separation
			for(char c:a[i][j]){
				int x = i, y = c - '0';
				if(y == j) x = !i;
				ans.pb({i,j,x,y});
				cnt[x][y]++;
			}
		}
	}
	
	rep(i,1,n){
		rep(j,0,2){
			// accumulation
			while(cnt[i][j] > 0){
				ans.pb({i,j,0,j});
				cnt[i][j]--;
				cnt[0][j]++;
			}
		}
	}
	
	rep(i,0,n){
		rep(j,0,m){
			cin >> b[i][j];
			reverse(all(b[i][j]));
			// distribution
			for(char c:b[i][j]){
				int x = i, y = c - '0';
				if(y == j){
					x = !i;
				}
				z.pb({x,y,i,j});
				req[x][y]++;
			}
		}
	}
	
	rep(i,1,n){
		rep(j,0,2){
			// distribution
			while(req[i][j] > 0){
				ans.pb({0,j,i,j});
				req[i][j]--;
			}
		}
	}
	
	
	cout << sz(ans) + sz(z) << "\n";
	for(auto &x:ans){
		for(auto y:x){
			cout << y + 1 << " ";
		}
		cout << "\n";
	}
	for(auto &x:z){
		for(auto y:x){
			cout << y + 1 << " ";
		}
		cout << "\n";
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