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

const int N=3e5+5;
const int R=1e5+105;

vector<pii> v[N];
int vis[N];

int a[N];
int b[N];

void solve(){
	int m,n;
	cin >> m >> n;
	
	rep(i,1,m+1) cin >> a[i];
	rep(i,1,n+1) cin >> b[i];
	
	int tot = 0;
	
	rep(i,1,m+1){
		int s;
		cin >> s;
		int y = i + R;
		rep(j,0,s){
			int x;
			cin >> x;
			tot += a[i] + b[x];
			v[x].pb({y,a[i]+b[x]});
			v[y].pb({x,a[i]+b[x]});
		}
	}
	
	int ans = 0;
	set<pii,greater<pii> > s; //{weight,vertex}
	
	rep(i,1,n+1){
		if(vis[i]) continue;
		s.clear();
		s.insert({0,i});
		while(!s.empty()){
			auto cur = *s.begin();
			s.erase(cur);
			if(vis[cur.sc]) continue;
			vis[cur.sc] = 1;
			ans += cur.fr;
			for(pii adj:v[cur.sc]){
				s.insert({adj.sc,adj.fr});
			}
		}
	}
	
	cout << tot - ans;
	
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