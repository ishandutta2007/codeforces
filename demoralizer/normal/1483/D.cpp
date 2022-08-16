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

const int N=605;

vector<pii> v[N];

int d[N][N];
pii edgs[N * N];
int wt[N * N];

int best[N][N]; // u, vertex

void solve(){
	int n,m;
	cin >> n >> m;
	
	rep(i,0,n+1){
		rep(j,0,n+1){
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	
	rep(i,0,m){
		int x,y,w;
		cin >> x >> y >> w;
		x--;
		y--;
		amin(d[x][y],w);
		amin(d[y][x],w);
		edgs[i] = {x,y};
		wt[i] = w;
	}
	
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
			}
		}
	}
	
	int q;
	cin >> q;
	rep(i,0,q){
		int x,y,l;
		cin >> x >> y >> l;
		x--;
		y--;
		v[x].pb({y,l});
	}
	
	rep(i,0,n){
		rep(u,0,n){
			// find best v (z)
			best[u][i] = -INF;
			for(pii z:v[u]){
				int tmp = z.sc - d[z.fr][i];
				amax(best[u][i],tmp);
			}
		}
	}
	
	int ans = 0;
	
	rep(i,0,m){
		bool found = 0;
		
		int x = edgs[i].fr, y = edgs[i].sc;
		rep(u,0,n){
			if(best[u][x] >= d[u][y] + wt[i]){
				found = 1;
			}
			if(best[u][y] >= d[u][x] + wt[i]){
				found = 1;
			}
		}
		
		if(found){
			ans++;
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