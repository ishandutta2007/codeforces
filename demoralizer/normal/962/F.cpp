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

const int N=1e5+5;

vector<int> ans;
int vis[N];
int par[N];
int paredg[N];
vector<pii> v[N];

// number of unpaired back edges
int num[N];
// vertex if single valid back edge else -1 or 0 if no back edges
int ver[N];
int close_at[N];
int backedge[N];

void dfs(int z,int p = 0){
	vis[z] = 1;
	par[z] = p;
	for(pii x:v[z]){
		if(x.fr == p){
			continue;
		}
		if(vis[x.fr] == 2){
			num[z]--;
			continue;
		}
		if(vis[x.fr] == 1){
			// backedge found
			close_at[z] = x.fr;
			backedge[z] = x.sc;
			num[z]++;
			if(ver[z] == 0){
				ver[z] = z;
			}
			else{
				ver[z] = -1;
			}
			continue;
		}
		paredg[x.fr] = x.sc;
		dfs(x.fr,z);
		num[z] += num[x.fr];
		if(ver[x.fr] > 0){
			if(close_at[x.fr] == z){
				int y = ver[x.fr];
				ans.pb(backedge[y]);
				while(y != z){
					ans.pb(paredg[y]);
					y = par[y];
				}
			}
			else{
				// closes higher
				close_at[z] = close_at[x.fr];
				backedge[z] = backedge[x.fr];
				if(ver[z] == 0){
					ver[z] = ver[x.fr];
				}
				else{
					ver[z] = -1;
				}
			}
		}
	}
	if(ver[z] == 0 && num[z]){
		ver[z] = -1;
	}
	if(num[z] > 1){
		ver[z] = -1;
	}
	vis[z] = 2;
	// cout << z << " " << num[z] << " " << ver[z] << " " << close_at[z] << "\n";
}

void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,1,m+1){
		int x,y;
		cin >> x >> y;
		v[x].pb({y,i});
		v[y].pb({x,i});
	}
	
	rep(i,1,n+1){
		if(vis[i]) continue;
		dfs(i);
	}
	sort(all(ans));
	cout << sz(ans) << "\n";
	for(int x:ans){
		cout << x << " ";
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