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

vector<array<int,3>> v[N];
int vis[N];
int par[N];

array<int,3> edgs[N];

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,1,m+1){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].pb({y,z,i});
		v[y].pb({x,z,i});
		edgs[i] = {x,y,z};
	}
	set<array<int,5>> s;
	s.insert({0,0,1,-1,0}); // dist , bad edges , vertex , incoming edge
	while(sz(s)){
		auto x = *s.begin();
		s.erase(s.begin());
		if(vis[x[2]]) continue;
		vis[x[2]] = x[3];
		par[x[2]] = x[4];
		for(auto y:v[x[2]]){
			s.insert({x[0] + 1 , x[1] + (!y[1]) , y[0] , y[2],x[2]});
		}
	}
	
	set<int> taken;
	
	int ver = n;
	while(ver != 1){
		taken.insert(vis[ver]);
		ver = par[ver];
	}
	
	int cnt = 0;
	
	rep(i,1,m+1){
		if(taken.count(i) ^ edgs[i][2]){
			cnt++;
		}
	}
	cout<<cnt<<"\n";
	rep(i,1,m+1){
		if(taken.count(i) ^ edgs[i][2]){
			cout<<edgs[i][0] <<" "<<edgs[i][1]<<" "<<!edgs[i][2]<<"\n";
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