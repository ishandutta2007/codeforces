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

const int N=2e5+505;
const int R=1e9 + 1005;

set<int> r,c;

map<int, vector<int>> v;

map<int, int> vis;

void solve(){
	int n,m;
	cin >> n >> m;
	int sx,sy,fx,fy;
	cin >> sx >> sy >> fx >> fy;
	
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		r.insert(x);
		c.insert(y);
		v[x].pb(y);
		v[R+y].pb(x);
	}
	
	r.insert(sx);
	c.insert(sy);
	v[sx].pb(sy);
	v[R+sy].pb(sx);
	
	// row, R + column
	
	set<pii> s; // cost, row or col
	s.insert({0,sx});
	s.insert({0,R+sy});
	
	int ans = abs(fx-sx) + abs(fy-sy);
	
	while(sz(s)){
		int dis = s.begin()->fr;
		int cur = s.begin()->sc;
		s.erase(s.begin());
		if(vis[cur]) continue;
		vis[cur] = 1;
		if(cur < R){
			// cout << "Row: " << cur << "\n"; 
			for(int y:v[cur]){
				amin(ans,dis + abs(fx-cur) + abs(fy-y));
				s.insert({dis,y+R});
			}
			// row
			auto it = r.upper_bound(cur);
			if(it != r.end()){
				s.insert({abs(cur - *it)+dis,*it});
			}
			it = r.lower_bound(cur);
			if(it != r.begin()){
				it--;
				s.insert({abs(cur - *it)+dis,*it});
			}
		}
		else{
			for(int x:v[cur]){
				amin(ans,dis + abs(fx-x) + abs(fy-(cur-R)));
				s.insert({dis,x});
			}
			cur -= R;
			// cout << "Col: " << cur << "\n";
			// column
			auto it = c.upper_bound(cur);
			if(it != c.end()){
				s.insert({dis+abs(cur - *it),*it+R});
			}
			it = c.lower_bound(cur);
			if(it != c.begin()){
				it--;
				s.insert({dis+abs(cur - *it),*it+R});
			}
		}
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