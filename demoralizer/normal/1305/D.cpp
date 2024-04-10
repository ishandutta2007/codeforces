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

const int N=1005;

int deg[N];
vector<int> v[N];

int query(int x, int y){
	cout << "? " << x << " " << y << endl;
	int w;
	cin >> w;
	return w;
}

void ans(int z){
	cout << "! " << z << endl;
}

void solve(){
	int n;
	cin >> n;
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
		deg[x]++;
		deg[y]++;
	}
	
	set<int> vis;
	set<pii> s;
	rep(i,1,n+1){
		s.insert({deg[i],i});
		vis.insert(i);
	}
	
	while(!s.empty()){
		auto x = *s.begin();
		s.erase(s.begin());
		auto y = *s.begin();
		s.erase(s.begin());
		
		int w = query(x.sc,y.sc);
		
		if(w == x.sc || w == y.sc){
			ans(w);
			return;
		}
		vis.erase(x.sc);
		vis.erase(y.sc);
		for(int a:v[x.sc]){
			s.erase({deg[a],a});
			deg[a]--;
			if(deg[a]) s.insert({deg[a],a});
		}
		for(int a:v[y.sc]){
			s.erase({deg[a],a});
			deg[a]--;
			if(deg[a]) s.insert({deg[a],a});
		}
	}
	ans(*vis.begin());
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