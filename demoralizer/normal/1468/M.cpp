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

const int N=0;



void solve(){
	int n;
	cin >> n;
	vector<vector<int>> a(n+1);
	vector<int> coor;
	rep(i,1,n+1){
		int k;
		cin >> k;
		a[i].resize(k);
		rep(j,0,k){
			cin >> a[i][j];
			coor.pb(a[i][j]);
		}
	}
	sort(all(coor));
	uniq(coor);
	vector<vector<int>> v(n + 1 + sz(coor));
	rep(i,1,n+1){
		for(int &x:a[i]){
			x = lower_bound(all(coor),x) - coor.begin() + n + 1;
			v[i].pb(x);
			v[x].pb(i);
		}
	}
	
	auto cmp = [&](int a,int b){
		if(sz(v[a]) != sz(v[b])){
			return sz(v[a]) > sz(v[b]);
		}
		return a > b;
	};
	
	vector<int> vis(sz(v));
	
	rep(i,1,sz(v)){
		vector<int> changed;
		for(int x:v[i]){
			if(!cmp(i,x)) continue;
			for(int y:v[x]){
				if(y == i) continue;
				if(vis[y]){
					if(i <= n){
						cout << i << " " << y << "\n";
					}
					else{
						cout << x << " " << vis[y] << "\n";
					}
					return;
				}
				vis[y] = x;
				changed.pb(y);
			}
		}
		for(int c:changed){
			vis[c] = 0;
		}
	}
	cout << -1 << "\n";
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