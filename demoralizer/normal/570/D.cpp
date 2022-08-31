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
int c[N];
int ans[N];
vector<pii> q[N];

int siz[N],dep[N],st[N],et[N],ver[N],tim = 1;
void dfs(int z,int d = 1){
	ver[tim] = z;
	st[z] = tim++;
	dep[z] = d;
	siz[z] = 1;
	for(int x:v[z]){
		dfs(x,d+1);
		siz[z] += siz[x];
	}
	et[z] = tim;
}

int lev[N];

void dfs2(int z,bool keep){
	int big = -1, val = 0;
	for(int x:v[z]){
		if(siz[x] > val){
			val = siz[x];
			big = x;
		}
	}
	
	for(int x:v[z]){
		if(x == big) continue;
		dfs2(x,0);
	}
	
	if(big != -1){
		dfs2(big,1);
	}
	
	
	lev[dep[z]] ^= c[z];
	for(int x:v[z]){
		if(x != big){
			rep(i,st[x],et[x]){
				int v = ver[i];
				lev[dep[v]] ^= c[v];
			}
		}
	}
	
	// queries
	for(auto x:q[z]){
		ans[x.sc] = lev[x.fr];
	}
	
	if(!keep){
		rep(i,st[z],et[z]){
			int v = ver[i];
			lev[dep[v]] ^= c[v];
		}
	}
	
}

void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,2,n+1){
		int p;
		cin >> p;
		v[p].pb(i);
	}
	
	rep(i,1,n+1){
		char z;
		cin >> z;
		c[i] = 1 << (z - 'a');
	}
	
	rep(i,0,m){
		int v,h;
		cin >> v >> h;
		q[v].pb({h,i});
	}
	
	dfs(1);
	dfs2(1,0);
	
	rep(i,0,m){
		if(ppc(ans[i]) < 2){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
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