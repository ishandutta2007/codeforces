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

set<pii> sets;
int par[N];
int sz[N];
int comps;

void makeset(int x){
	par[x] = x;
	sz[x] = 1;
	comps++;
	sets.insert({1,x});
}

int findset(int x){
	if(par[x] == x) return x;
	return par[x] = findset(par[x]);
}

void eraseset(int x){
	x = findset(x);
	sets.erase({sz[x],x});
}

void unionsets(int x,int y){
	x = findset(x);
	y = findset(y);
	if(x == y) return;
	eraseset(x);
	eraseset(y);
	par[x] = y;
	sz[y] += sz[x];
	sets.insert({sz[y],y});
	comps--;
}

bool setexists(int x){
	return !!sz[x];
}

bool setsequal(){
	return sets.begin()->fr == sets.rbegin()->fr;
}

void solve(){
	int n;
	cin>>n;
	vector<pii> v;
	rep(i,1,n+1){
		int x;
		cin>>x;
		v.pb({x,i});
	}
	sort(all(v));
	int ans = v[0].fr;
	int ans_comps = 1;
	
	for(auto x:v){
		int val = x.fr, id = x.sc;
		makeset(id);
		if(setexists(id+1)) unionsets(id,id+1);
		if(setexists(id-1)) unionsets(id,id-1);
		if(setsequal()){
			if(comps > ans_comps){
				ans = val;
				ans_comps = comps;
			}
		}
	}
	
	cout << ans + 1;
	
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