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

const int N=2e5+5;

vector<int> v[N];
int ans = 1;

int dfs(int z,int p = 1){
	int dep = INF;
	bool leaf = 1;
	vector<int> d;
	for(int x:v[z]){
		if(x == p){
			continue;
		}
		leaf = 0;
		int tmp = dfs(x,z);
		d.pb(tmp);
	}
	// sort(all(d));
	// reverse(all(d));
	for(int x:d){
		amax(ans,x+1); // able to find parent of z
		amin(dep,x);
	}
	if(leaf){
		dep = 0;
	}
	return (dep+1);
}

void solve(){
	int n;
	cin >> n;
	rep(i,1,n+1){
		v[i].clear();
	}
	ans = 1;
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	vector<int> d;
	for(int x:v[1]){
		int tmp = dfs(x);
		d.pb(tmp);
	}
	
	sort(all(d));
	d.ppb(); // has to reach till 1 only
	for(int x:d){
		amax(ans,x+1); // have reach a child of 1
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