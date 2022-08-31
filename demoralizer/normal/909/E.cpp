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

vector<int> task[2];
vector<int> v[N];
int vis[N];
int e[N];
int tot[N];
int done[N];
void dfs(int z,int p){
	vis[z]=1;
	for(int x:v[z]){
		if(vis[x])continue;
		done[x]++;
		if(done[x] == tot[x]){
			if(e[x] == e[z]){
				dfs(x,z);
			}
			else{
				task[e[x]].pb(x);
			}
		}
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,n){
		cin>>e[i];
	}
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		v[y].pb(x);
		tot[x]++;
	}
	
	
	rep(i,0,n){
		if(tot[i] == 0){
			task[e[i]].pb(i);
		}
	}
	
	int ans = 0;
	while(sz(task[0]) || sz(task[1])){
		for(int x:task[0]){
			dfs(x,-1);
		}
		task[0].clear();
		if(sz(task[1])) ans++;
		for(int x:task[1]){
			dfs(x,-1);
		}
		task[1].clear();
	}
	cout<<ans;
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