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

const int N=2e5+5;

struct cmp
{
	bool operator() (pair<int, pii> a, pair<int, pii> b){
		return a > b;
	}
};

vector<pii> v[N];

int dis[N][51];
int vis[N][51];

void solve(){
	int n,m;
	cin >> n >> m;
	
	rep(i,1,n+1){
		rep(j,0,51){
			dis[i][j] = INF;
		}
	}
	
	rep(i,0,m){
		int x,y,w;
		cin >> x >> y >> w;
		v[x].pb({y,w});
		v[y].pb({x,w});
	}
	
	priority_queue<pair<int, pii>,vector<pair<int, pii>>,cmp> s; // {dis,ver,last_w}
	s.push({0,{1,0}});
	
	while(!s.empty()){
		auto top = s.top();
		s.pop();
		int ver = top.sc.fr;
		int lw = top.sc.sc;
		int d = top.fr;
		if(vis[ver][lw]){
			continue;
		}
		vis[ver][lw] = 1;
		dis[ver][lw] = d;
		
		
		for(auto x:v[ver]){
			int nlw = x.sc;
			int newdis = d;
			if(lw) newdis += (x.sc + lw) * (x.sc + lw);
			if(lw) nlw = 0;
			if(dis[x.fr][nlw]<=newdis) continue;dis[x.fr][nlw]=newdis;
			s.push({newdis,{x.fr,nlw}});
		}
	}
	
	rep(i,1,n+1){
		if(dis[i][0] == INF) dis[i][0] = -1;
		cout << dis[i][0] << " ";
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