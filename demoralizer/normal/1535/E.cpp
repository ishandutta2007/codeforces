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

int a[N];
int c[N];

const int H = 19;
int par[N][H+1], lvl[N];
// void dfs(int z, int p){
// 	lvl[z] = lvl[p] + 1;
// 	par[z][0] = p;
// 	for (int i = 1; i <= H; ++i){
// 		par[z][i] = par[par[z][i-1]][i-1];
// 	}
// 	for(int x:v[z]){
// 		if(x==p)continue;
// 		dfs(x,z);
// 	}
// }

// int lca(int x, int y) {
// 	if (lvl[x] < lvl[y]) swap(x, y);
// 	for (int i = H; i >= 0; i--){
// 		if (lvl[x] - (1<<i) >= lvl[y]){
// 			x = par[x][i];
// 		}
// 	}
// 	if (x == y) return x;
// 	for (int i = H; i >= 0; i--){
// 		if (par[x][i] != par[y][i]){
// 			x = par[x][i], y = par[y][i];
// 		}
// 	}
// 	return par[x][0];
// }

void solve(){
	int q;
	cin >> q >> a[0] >> c[0];
	
	rep(i,0,H+1){
		par[0][i] = -1;
	}
	
	rep(i,1,q+1){
		int t;
		cin >> t;
		if(t == 1){
			int p;
			cin >> p >> a[i] >> c[i];
			par[i][0] = p;
			for (int j = 1; j <= H; ++j){
				par[i][j] = par[par[i][j-1]][j-1];
			}
		}
		else{
			int ver,w;
			cin >> ver >> w;
			int b = 0, s = 0;
			while(w > 0){
				int z = ver;
				for(int j = H; j >= 0; j--){
					if(a[par[z][j]]) z = par[z][j];
				}
				// buy from z
				int quan = min(w,a[z]);
				b += quan;
				s += c[z] * quan;
				w -= quan;
				a[z] -= quan;
				if(z == ver){
					break;
				}
			}
			cout << b << " " << s << endl;
		}
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