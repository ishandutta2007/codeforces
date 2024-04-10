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

int cnt_to_id[N];

void solve(){
	int n,m;
	cin >> n >> m;
	
	vector<int> a(n);
	map<int, int> f;
	rep(i,0,n){
		cin >> a[i];
		f[a[i]]++;
	}
	
	vector<int> vals = a;
	sort(all(vals));
	uniq(vals);
	
	vector<int> cnts;
	for(int v:vals){
		cnts.pb(f[v]);
	}
	sort(all(cnts));
	uniq(cnts);
	
	rep(i,0,sz(cnts)){
		cnt_to_id[cnts[i]] = i;
	}
	
	
	map<int, vector<int>> v;
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	int nc = sz(cnts);
	vector<vector<int>> s(nc);
	vector<int> cache(nc);
	for(int x:vals){
		s[cnt_to_id[f[x]]].pb(x);
		v[x].pb(x);
		sort(all(v[x]), greater<int>());
	}
	
	rep(i,0,nc){
		sort(all(s[i]),greater<int>());
	}
	
	int ans = 0;
	for(int x:vals){
		int cx = f[x];
		for(int y:v[x]){
			int c = f[y];
			int id = cnt_to_id[c];
			if(s[id][cache[id]] == y){
				cache[id]++;
			}
		}
		
		rep(i,0,nc){
			if(cache[i] < sz(s[i])){
				int c = cnts[i];
				amax(ans, (x + s[i][cache[i]]) * (c + cx));
			}
			cache[i] = 0;
		}
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