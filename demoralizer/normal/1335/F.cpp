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

const int N=1e6+5;

int n,m;
bool check(int x,int y){
	if(x >= n || y >= m || x < 0 || y < 0) return 0;
	return 1;
}
int ord(int x,int y){
	return (m * x + y);
}

int dir[200];

int col[N];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<int> v[N],vr[N],order,comp;
set<int> dis;
int vis[N];

void dfs1(int z){
	vis[z] = 1;
	for(int x:v[z]){
		if(vis[x]) continue;
		dfs1(x);
	}
	order.pb(z);
}
void dfs2(int z){
	vis[z] = 1;
	for(int x:vr[z]){
		if(vis[x]) continue;
		dfs2(x);
	}
	comp.pb(z);
}

void dfs(int z,int s,int start,int dep = 0){
	for(int x:vr[z]){
		if(x == start) continue;
		dfs(x,s,start,dep + 1);
	}
	if(!col[z]){
		dis.insert(dep % s);
	}
}

void solve(){
	cin >> n >> m;
	rep(i,0,n*m){
		v[i].clear();
		vr[i].clear();
		vis[i] = 0;
	}
	rep(i,0,n){
		string s;
		cin >> s;
		rep(j,0,m){
			col[ord(i,j)] = (s[j] == '1');
		}
	}
	rep(i,0,n){
		string s;
		cin >> s;
		rep(j,0,m){
			int x = ord(i,j);
			int y = ord(i+dx[dir[s[j]]],j+dy[dir[s[j]]]);
			v[x].pb(y);
			vr[y].pb(x);
		}
	}
	order.clear();
	rep(i,0,n*m){
		if(vis[i]) continue;
		dfs1(i);
	}
	rep(i,0,n*m){
		vis[i] = 0;
	}
	reverse(all(order));
	
	int ans = 0, b = 0;
	
	for(int z:order){
		if(vis[z]) continue;
		comp.clear();
		dfs2(z);
		// comp contains the component
		int s = sz(comp);
		if(s == 1) continue;
		dis.clear();
		dfs(z,s,z);
		ans += s;
		b += sz(dis);
	}
	cout << ans << " " << b << "\n";
}
signed main(){
	dir['U'] = 2;
	dir['D'] = 0;
	dir['L'] = 3;
	dir['R'] = 1;
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