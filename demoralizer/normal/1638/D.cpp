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
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1005;

int done[N][N];

void solve(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> a(n,vector<int>(m));
	
	auto valid = [&](int i, int j){
		if(i < 0 || j < 0 || i > n - 2 || j > m - 2) return 0;
		vector<int> vals;
		vals.pb(a[i][j]);
		vals.pb(a[i+1][j]);
		vals.pb(a[i][j+1]);
		vals.pb(a[i+1][j+1]);
		sort(all(vals));
		uniq(vals);
		if(sz(vals) == 1){
			return vals[0];
		}
		else if(sz(vals) == 2){
			return (vals[0] == 0 ? vals[1] : 0);
		}
		return 0;
	};
	
	rep(i,0,n){
		rep(j,0,m){
			cin >> a[i][j];
		}
	}
	
	vector<pii> s;
	
	auto consider = [&](int x, int y){
		if(done[x][y]) return 0;
		if(valid(x,y)){
			s.pb({x,y});
			done[x][y] = 1;
		}
	};
	
	rep(i,0,n){
		rep(j,0,m){
			consider(i,j);
		}
	}
	
	
	vector<array<int,3>> moves;
	
	while(!s.empty()){
		auto cur = s.back();
		s.ppb();
		int x = cur.fr;
		int y = cur.sc;
		int c = valid(x,y);
		if(!c) continue;
		
		moves.pb({x+1,y+1,c});
		a[x][y] = a[x+1][y] = a[x+1][y+1] = a[x][y+1] = 0;
		
		for(int i = -1; i <= 1; i++){
			for(int j = -1; j <= 1; j++){
				consider(x+i,y+j);
			}
		}
		
	}
	
	rep(i,0,n){
		rep(j,0,m){
			if(a[i][j]){
				cout << -1 << "\n";
				return;
			}
		}
	}
	
	cout << sz(moves) << "\n";
	reverse(all(moves));
	for(auto x:moves){
		for(int y:x){
			cout << y << " ";
		}
		cout << "\n";
		
		// a[x[0]-1][x[1]-1] = x[2];
		// a[x[0]][x[1]-1] = x[2];
		// a[x[0]-1][x[1]] = x[2];
		// a[x[0]][x[1]] = x[2];
		// rep(i,0,n){
		// 	rep(j,0,m){
		// 		cout << a[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
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