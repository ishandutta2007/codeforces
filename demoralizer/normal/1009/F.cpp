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

struct node
{
	int v = 0,id;
	node(){}
	node(int val){
		id = val;
	}
	void merge(node &l,node &r){
		if(l.v > r.v){
			v = l.v;
			id = l.id;
		}
		else if(r.v > l.v){
			v = r.v;
			id = r.id;
		}
		else{
			v = l.v;
			id = min(l.id,r.id);
		}
	}
};
struct update
{
	int v = 0;
	update(){}
	update(int val){
		v = val;
	}
	void combine(update &other,int32_t tl,int32_t tr){
		
	}
	void apply(node &x,int32_t tl,int32_t tr){
		x.v += v;
	}
};

const int len = N;
struct segtree
{
	node t[4 * len], zero = node();
	update u[4 * len], noop = update();
	bool lazy[4 * len];
	
	void pushdown(int32_t v, int32_t tl, int32_t tr){
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(v<<1,tl,tm,u[v]);
		apply(v<<1|1,tm+1,tr,u[v]);
		u[v] = noop;
		lazy[v] = 0;
	}
	
	void apply(int32_t v, int32_t tl, int32_t tr, update upd){
		if(tl != tr){
			lazy[v] = 1;
			u[v].combine(upd,tl,tr);
		}
		upd.apply(t[v],tl,tr);
	}
	
	template<typename T>
	void build(const T &arr,int32_t v, int32_t tl, int32_t tr){
		if(tl == tr){
			t[v] = arr[tl];
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(arr,v<<1,tl,tm);
		build(arr,v<<1|1,tm+1,tr);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	
	node query(int32_t v,int32_t tl,int32_t tr,int32_t l,int32_t r){
		if(l > tr || r < tl){
			return zero;
		}
		if(tl >= l && tr <= r){
			return t[v];
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
	}
	
	void rupd(int32_t v,int32_t tl,int32_t tr,int32_t l,int32_t r,const update &upd){
		if(l > tr || r < tl){
			return;
		}
		if(tl >= l && tr <= r){
			apply(v,tl,tr,upd);
			return;
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		rupd(v<<1,tl,tm,l,r,upd);
		rupd(v<<1|1,tm+1,tr,l,r,upd);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	
	public:
	template<typename T>
	void build(const T &arr){
		build(arr,1,0,len-1);
	}
	node query(int32_t l,int32_t r){
		return query(1,0,len-1,l,r);
	}
	void rupd(int32_t l,int32_t r,const update &upd){
		rupd(1,0,len-1,l,r,upd);
	}
};

segtree t;

vector<int> v[N];
int tim = 0, st[N], et[N], ver[N], siz[N], dep[N];

int dom[N];

void dfs_sz(int z,int p = 0){
	dep[z] = dep[p] + 1;
	siz[z] = 1;
	ver[tim] = dep[z];
	st[z] = tim++;
	for(int x:v[z]){
		if(x == p){
			continue;
		}
		dfs_sz(x,z);
		siz[z] += siz[x];
	}
	et[z] = tim;
}

void dfs(int z,int p = 0,int clear = 0){
	int big = -1;
	for(int x:v[z]){
		if(x == p) continue;
		if(big == -1 || siz[big] < siz[x]){
			big = x;
		}
	}
	for(int x:v[z]){
		if(x == p || x == big){
			continue;
		}
		dfs(x,z,1);
	}
	if(big != -1){
		dfs(big,z);
	}
	
	t.rupd(dep[z],dep[z],1);
	for(int x:v[z]){
		if(x == p || x == big){
			continue;
		}
		rep(i,st[x],et[x]){
			t.rupd(ver[i],ver[i],1);
		}
	}
	
	dom[z] = t.query(0,N).id - dep[z];
	
	if(clear){
		rep(i,st[z],et[z]){
			t.rupd(ver[i],ver[i],-1);
		}
	}
}

int ids[N];

void solve(){
	rep(i,0,N){
		ids[i] = i;
	}
	t.build(ids);
	int n;
	cin >> n;
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs_sz(1);
	dfs(1);
	rep(i,1,n+1){
		cout << dom[i] << "\n";
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