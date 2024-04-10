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

vector<vector<pii>> v, vals;
int siz[N];
int dep[N];
int val[N];
int tim = 1;
int st[N];
int et[N];
int ances[N];
vector<set<pii>> s;

void dfs(int z,int p = 0){
	ances[z] = 1;
	if(sz(s[val[z]])){
		ances[z] = s[val[z]].begin()->sc;
	}
	s[val[z]].insert({-dep[z],z});
	st[z] = tim++;
	siz[z] = 1;
	for(pii x:v[z]){
		if(x.fr == p) continue;
		val[x.fr] = x.sc;
		dep[x.fr] = dep[z] + 1;
		dfs(x.fr,z);
		siz[z] += siz[x.fr];
	}
	et[z] = tim-1;
	vals[val[z]].pb({-dep[z],z});
	s[val[z]].erase({-dep[z],z});
}

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	int A[maxn];
	int query(int i){
		int sum = 0;
		while (i > 0) 
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, int k){
		if(i<1)return;
		while (i < maxn) 
			A[i] += k, i += LSB(i);
	}
	int rquery(int x, int y){
		return query(y) - query(x - 1);
	}
}fenw;

void solve(){
	int n;
	cin >> n;
	v.resize(n + 1);
	s.resize(n + 1);
	vals.resize(n + 1);
	rep(i,1,n){
		int x,y,z;
		cin >> x >> y >> z;
		v[x].pb({y,z});
		v[y].pb({x,z});
	}
	
	dfs(1);
	
	int ans = 0;
	rep(i,1,n+1){
		sort(all(vals[i]));
		for(auto tmp:vals[i]){
			int z = tmp.sc;
			int l = st[z];
			int r = et[z];
			int inside = fenw.rquery(l,r);
			inside = siz[z] - inside;
			fenw.update(l,inside);
		}
		
		for(auto tmp:vals[i]){
			int z = tmp.sc;
			int inside = fenw.rquery(st[z]+1,et[z]);
			int y = ances[z];
			int outside = fenw.rquery(st[y]+1,et[y]);
			inside = siz[z] - inside;
			outside = siz[y] - outside;
			ans += inside * outside;
		}
		
		for(auto tmp:vals[i]){
			int z = st[tmp.sc];
			fenw.update(z,-fenw.rquery(z,z));
		}
	}
	
	cout << ans;
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