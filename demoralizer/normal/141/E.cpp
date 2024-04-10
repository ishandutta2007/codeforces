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

const int N=1e3+5;

int viscnt = 0, wt = 0;

vector<pii> v[N];
int vis[N];
int dep[N];

vector<array<int,3>> edgs;

set<int> pr;

void dfs0(int z,int p = 0){
	dep[z] = dep[p] + 1;
	vis[z]=1;
	viscnt++;
	for(pii x:v[z]){
		if(vis[x.fr])continue;
		wt += edgs[x.sc][2];
		pr.insert(x.sc);
		dfs0(x.fr,z);
	}
}

struct cmp{
	bool operator() (pii x, pii y){
		return x.fr < y.fr;
	}
};

set<pii,cmp> s[N];

void merge(int x,int y){
	if(sz(s[x]) < sz(s[y])){
		swap(s[x],s[y]);
	}
	assert(sz(s[x]) >= sz(s[y]));
	for(auto z:s[y]){
		s[x].insert(z);
	}
}

void dfs(int z,int p = 0){
	vis[z]=1;
	for(pii x:v[z]){
		if(vis[x.fr]){
			if(dep[x.fr] < dep[z] && ((edgs[x.sc][2] && wt < 0) || (edgs[x.sc][2] == 0 && wt > 0))){
				s[z].insert({dep[x.fr],x.sc});
				// cout << "HERE" << endl;
			}
			continue;
		}
		dfs(x.fr,z);
		while(sz(s[x.fr]) && s[x.fr].rbegin()->fr > dep[z]){
			s[x.fr].erase(--s[x.fr].end());
		}
		if(((wt < 0 && edgs[x.sc][2] == 0) || (wt > 0 && edgs[x.sc][2])) && sz(s[x.fr])){
			pii tmp = *s[x.fr].rbegin();
			pr.erase(x.sc);
			pr.insert(tmp.sc);
			s[x.fr].erase(tmp);
			if(wt < 0) wt++;
			else wt--;
			int ver;
			if(dep[edgs[tmp.sc][0]] < dep[edgs[tmp.sc][1]]){
				ver = edgs[tmp.sc][0];
			}
			else{
				ver = edgs[tmp.sc][1];
			}
			merge(ver,x.fr);
		}
		else{
			merge(z,x.fr);
		}
	}
}


void solve(){
	int n, m;
	cin >> n >> m;
	
	if(n % 2 == 0){
		cout << -1;
		return;
	}
	
	rep(i,0,m){
		int x,y;
		string k;
		cin >> x >> y >> k;
		edgs.pb({x,y,k == "S"});
		if(x == y) continue;
		v[x].pb({y,i});
		v[y].pb({x,i});
	}
	
	dfs0(1);
	if(viscnt != n){
		cout << -1;
		return;
	}
	mem0(vis);
	
	wt -= n / 2;
	
	dfs(1);
	
	if(wt != 0){
		cout << -1;
		return;
	}
	
	cout << n - 1 << "\n";
	for(int x:pr){
		cout << x + 1 << " ";
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