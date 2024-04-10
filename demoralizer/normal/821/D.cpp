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

const int N=1e4+5;

map<pii, int> z;
vector<int> v[3*N];
int vis[3*N];
pii p[N];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	rep(i,0,k){
		int x,y;
		cin >> x >> y;
		z[{x,y}] = i;
		p[i] = {x,y};
	}
	
	for(auto tmp:z){
		int x = tmp.fr.fr, y = tmp.fr.sc, i = tmp.sc;
		rep(k,-1,2){
			if(x+k > 0 && x+k <= n){
				v[i].pb(x+N+k);
				v[x+N+k].pb(i);
			}
			if(y+k > 0 && y+k <= m){
				v[i].pb(y+2*N+k);
				v[y+2*N+k].pb(i);
			}
		}
		rep(j,0,4){
			if(z.count({x+dx[j],y+dy[j]})){
				v[i].pb(z[{x+dx[j],y+dy[j]}]);
			}
		}
	}
	
	deque<pii> d; // {id,dist}
	d.pb({z[{1,1}],0});
	
	while(!d.empty()){
		auto tmp = d.front();
		d.ppf();
		int id = tmp.fr, dist = tmp.sc;
		if(id == N + n || id == 2 * N + m || (id < N && p[id] == make_pair(n,m))){
			cout << dist;
			return;
		}
		if(vis[id]){
			continue;
		}
		vis[id] = 1;
		for(int x:v[id]){
			if(x >= N){
				d.pb({x,dist+1});
			}
			else{
				d.pf({x,dist});
			}
		}
	}
	
	cout << -1;
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