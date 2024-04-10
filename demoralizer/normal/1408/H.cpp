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

const int N=5e5+5;

vector<int> v[N];

void solve(){
	int n;
	cin >> n;
	v[0].clear();
	rep(i,1,n+1){
		v[i].clear();
		v[i].pb(-1);
	}
	
	rep(i,0,n){
		int x;
		cin >> x;
		v[x].pb(i);
	}
	
	
	if(sz(v[0]) < 2){
		cout << "0\n";
		return;
	}
	
	int z = sz(v[0]);
	int L = v[0][(z+1)/2], R = v[0][z/2 - 1];
	
	vector<pii> vec;
	
	rep(i,1,n+1){
		v[i].pb(n+2);
		int l = *prev(lower_bound(all(v[i]),L));
		int r = *upper_bound(all(v[i]),R);
		if(l != -1 || r != n+2) vec.pb({l,r});
	}
	for(int x:v[0]){
		if(x < L) vec.pb({x,-1});
	}
	
	sort(all(vec),[&](pii a,pii b){
		return a.fr > b.fr;
	});
	
	int ans = 0;
	multiset<int> s;
	vector<int> vis(n+4);
	
	for(auto x:vec){
		if(x.sc == -1){
			// zero
			if(sz(s)){
				int r = - *s.begin();
				s.erase(s.begin());
				vis[r] = 1;
				ans++;
			}
		}
		else{
			s.insert(-x.sc);
		}
		// cout << x << "\n";
	}
	
	vector<int> vec2;
	for(auto x:vec){
		if(x.sc != -1 && !vis[x.sc]) vec2.pb(x.sc);
	}
	
	for(int x:v[0]){
		if(x > R) vec2.pb(x),vis[x] = 1;
	}
	
	s.clear();
	sort(all(vec2));
	for(int x:vec2){
		if(vis[x]){
			if(sz(s)){
				s.erase(s.begin());
				ans++;
			}
		}
		else{
			s.insert(x);
		}
	}
	
	amin(ans,z/2);
	
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