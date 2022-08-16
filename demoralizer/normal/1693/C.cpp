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

vector<multiset<int>> v;
vector<set<int>> vr;

int dp[N];

void solve(){
	int n,m;
	cin >> n >> m;
	v.resize(n + 1);
	vr.resize(n + 1);
	
	rep(i,1,n+1){
		dp[i] = INF;
	}
	
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		v[x].insert(y);
		vr[y].insert(x);
	}
	
	
	set<pii> s;
	s.insert({0,n});
	while(sz(s)){
		auto tmp = *s.begin();
		s.erase(tmp);
		int z = tmp.sc;
		int ans = tmp.fr;
		if(dp[z] != INF){
			continue;
		}
		dp[z] = ans;
		for(int x:vr[z]){
			// consider x also
			v[x].erase(z);
			// sz(v[x]) -> cut, 1 travel to here, + ans
			int y = sz(v[x]) + 1 + ans;
			s.insert({y,x});
		}
	}
	
	
	cout << dp[1];
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