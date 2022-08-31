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

const int N=4e5+5;



void solve(){
	int m;
	cin >> m;
	
	vector<vector<int>> a(m), ans(m);
	
	vector<map<int, vector<int>>> ids(m);
	vector<int> c;
	int cnt = 0;
	rep(i,0,m){
		int n;
		cin >> n;
		a[i].resize(n);
		ans[i].resize(n);
		rep(j,0,n){
			cin >> a[i][j];
			c.pb(a[i][j]);
			cnt++;
		}
	}
	
	
	vector<multiset<int>> v(N);
	sort(all(c));
	rep(i,0,m){
		int pos = 0;
		for(int &x: a[i]){
			x = lower_bound(all(c),x) - c.begin() + m;
			v[i].insert(x);
			v[x].insert(i);
			ids[i][x].pb(pos);
			pos++;
		}
	}
	
	
	int par = 1;
	auto rem = [&](int x, int y){
		v[x].erase(v[x].find(y));
		v[y].erase(v[y].find(x));
		if(x > y) swap(x,y);
		int z = ids[x][y].back();
		ids[x][y].ppb();
		ans[x][z] = par;
		par = 3 - par;
		cnt--;
	};
	
	
	rep(i,0,m){
		int x = i;
		while(sz(v[x])){
			int y = *v[x].begin();
			rem(x,y);
			x = y;
		}
		if(x != i){
			cout << "NO\n";
			return;
		}
	}
	
	if(cnt){
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	rep(i,0,m){
		for(int x:ans[i]){
			cout << (x==1?'L':'R');
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