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

const int N=1e6+5;

int n,edges,uuu,vertices;
int a[N],b[N];
int vis[N * 3];
vector<int> v[N * 3];

void dfs(int z,int m){
	vis[z] = 1;
	vertices++;
	for(int x:v[z]){
		if(x >= m){
			uuu++;
			continue;
		}
		edges++;
		if(vis[x]){
			continue;
		}
		dfs(x,m);
	}
}

bool check(int m){
	rep(i,0,m){
		vis[i] = 0;
	}
	rep(i,0,m){
		if(vis[i]){
			continue;
		}
		edges = 0;
		vertices = 0;
		uuu = 0;
		dfs(i,m);
		edges /= 2;
		edges += uuu;
		if(vertices < edges){
			return false;
		}
	}
	return true;
}

void solve(){
	cin >> n;
	vector<int> coor;
	rep(i,0,n){
		cin >> a[i] >> b[i];
		coor.pb(a[i]);
		coor.pb(b[i]);
	}
	sort(all(coor));
	uniq(coor);
	int L = n - 1, U = sz(coor) - 1;
	rep(i,0,n){
		a[i] = lower_bound(all(coor),a[i]) - coor.begin();
		b[i] = lower_bound(all(coor),b[i]) - coor.begin();
		amax(L,a[i]);
		v[a[i]].pb(b[i]);
		v[b[i]].pb(a[i]);
	}
	int ans = -1;
	
	while(L <= U){
		int m = (L + U) / 2;
		
		if(check(m+1)){
			ans = m;
			U = m - 1;
		}
		else{
			L = m + 1;
		}
	}
	
	if(ans != -1){
		ans = coor[ans];
	}
	cout << ans;//
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