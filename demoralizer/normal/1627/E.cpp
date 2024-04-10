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
const long long eh = -1e16;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;

int x[N];
vector<int> v[N];
vector<int> ans[N];

vector<array<int,4>> l[N];

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	
	rep(i,1,n+1){
		cin >> x[i];
		v[i].clear();
		ans[i].clear();
		l[i].clear();
	}
	
	v[1].pb(1);
	v[n].pb(m);
	rep(i,0,k){
		int a,b,c,d,h;
		cin >> a >> b >> c >> d >> h;
		v[a].pb(b);
		v[c].pb(d);
		
		l[a].pb({b,c,d,h});
	}
	
	rep(i,1,n+1){
		sort(all(v[i]));
		uniq(v[i]);
		ans[i].resize(sz(v[i]), -INF);
	}
	
	ans[1][0] = 0;
	
	rep(i,1,n+1){
		int z = sz(v[i]);
		rep(j,1,z){
			amax(ans[i][j], ans[i][j-1] - (v[i][j] - v[i][j-1]) * x[i]);
			if(ans[i][j] < eh) ans[i][j] = -INF;
		}
		for(int j = z - 2; j >= 0; j--){
			amax(ans[i][j], ans[i][j+1] - (v[i][j+1] - v[i][j]) * x[i]);
			if(ans[i][j] < eh) ans[i][j] = -INF;
		}
		map<int, int> tmp;
		rep(j,0,z){
			tmp[v[i][j]] = ans[i][j];
		}
		for(auto lad : l[i]){
			int b = lad[0], c = lad[1], d = lad[2], h = lad[3];
			int val = tmp[b];
			
			int j = lower_bound(all(v[c]), d) - v[c].begin();
			
			amax(ans[c][j], val + h);
			if(ans[c][j] < eh) ans[c][j] = -INF;
		}
	}
	
	if(ans[n].back() == -INF){
		cout << "NO ESCAPE\n";
		return;
	}
	
	cout << -ans[n].back() << "\n";
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