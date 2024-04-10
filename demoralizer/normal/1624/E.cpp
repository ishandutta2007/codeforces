#include "bits/stdc++.h"
using namespace std;
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

const int N=1e3+5;

int n,m;
string s;
set<string> z;
map<string, array<int,3>> mp;

vector<pair<int,array<int,3>>> v[N];
int vis[N];

vector<array<int,3>> ans;

int dfs(int z){
	if(z == m){
		cout << sz(ans) << "\n";
		for(auto x : ans){
			cout << x[0] << " " << x[1] << " " << x[2] << "\n";
		}
		return 1;
	}
	if(vis[z]) return 0;
	vis[z] = 1;
	for(auto x : v[z]){
		ans.pb(x.sc);
		if(dfs(x.fr)) return 1;
		ans.ppb();
	}
	
	return 0;
}

void solve(){
	z.clear();
	mp.clear();
	
	cin >> n >> m;
	
	
	string t[n];
	rep(i,0,n){
		cin >> t[i];
		rep(j,0,m){
			string x = "";
			x += t[i][j];
			if(j < m - 1){
				x += t[i][j + 1];
				z.insert(x);
				mp[x] = {j+1,j+2,i+1};
			}
			if(j < m - 2){
				x += t[i][j + 2];
				z.insert(x);
				mp[x] = {j+1,j+3,i+1};
			}
		}
	}
	
	cin >> s;
	
	rep(i,0,m){
		v[i].clear();
		vis[i] = 0;
		string x = "";
		x += s[i];
		if(i < m - 1){
			x += s[i + 1];
			if(z.count(x)) v[i].pb({i + 2, mp[x]});
		}
		if(i < m - 2){
			x += s[i + 2];
			if(z.count(x)) v[i].pb({i + 3, mp[x]});
		}
	}
	
	ans.clear();
	
	if(!dfs(0)) cout << -1 << "\n";
	
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