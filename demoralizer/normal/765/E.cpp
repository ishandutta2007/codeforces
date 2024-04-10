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

set<int> v[N];
set<int> d[N];
void solve(){
	int n;
	cin >> n;
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].insert(y);
		v[y].insert(x);
	}
	vector<int> leaves;
	rep(i,1,n+1){
		if(sz(v[i]) == 1){
			d[i].insert(0);
			leaves.pb(i);
		}
	}
	
	int root = 0;
	
	while(sz(leaves)){
		int tmp = leaves.back();
		leaves.ppb();
		int dep = *d[tmp].begin() + 1;
		int par = *v[tmp].begin();
		v[par].erase(tmp);
		d[par].insert(dep);
		if(sz(d[par]) == 1 && sz(v[par]) == 1){
			leaves.pb(par);
		}
		if(sz(v[par]) == 0){
			root = par;
			break;
		}
	}
	if(root == 0 || sz(d[root]) > 2){
		cout << -1;
		return;
	}
	int len = 0;
	// cout << root << "\n";
	for(int x:d[root]){
		len += x;
		// cout << x << "\n";
	}
	while(len % 2 == 0){
		len /= 2;
	}
	cout << len;
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