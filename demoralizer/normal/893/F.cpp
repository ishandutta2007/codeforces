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

struct node
{
	int v;
	node* left;
	node* right;
} ns[N * 20];
int cnt = 0;

node* create(){
	(ns + cnt) -> v = INF;
	(ns + cnt) -> left = ns;
	(ns + cnt) -> right = ns;
	return (ns + cnt++);
}

int query(node* v,int tl,int tr,int l,int r){
	if(l > tr || r < tl || v == ns){
		return INF;
	}
	if(l <= tl && tr <= r){
		return v -> v;
	}
	int tm = (tl + tr) / 2;
	return min(query(v->left,tl,tm,l,r),query(v->right,tm+1,tr,l,r));
}

node* update(node* v,int tl,int tr,int id,int val){
	if(id < tl || id > tr){
		return v;
	}
	node* ret = create();
	if(tl == tr){
		ret -> v = val;
		return ret;
	}
	int tm = (tl + tr) / 2;
	ret -> left = update(v->left,tl,tm,id,val);
	ret -> right = update(v->right,tm+1,tr,id,val);
	ret -> v = min(ret -> left -> v, ret -> right -> v);
	return ret;
}

int a[N];
int dep[N];
int st[N],et[N],tim = 0;
vector<int> v[N],d[N];
void dfs(int z,int p = 0){
	dep[z] = dep[p] + 1;
	d[dep[z]].pb(z);
	st[z] = tim++;
	for(int x:v[z]){
		if(x == p) continue;
		dfs(x,z);
	}
	et[z] = tim;
}

node* version[N];

void solve(){
	int n,r;
	cin >> n >> r;
	
	rep(i,1,n+1){
		cin >> a[i];
	}
	
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs(r);
	version[0] = create();
	rep(i,1,n+1){
		version[i] = version[i-1];
		for(int x:d[i]){
			version[i] = update(version[i],0,n+4,st[x],a[x]);
		}
	}
	
	int m;
	cin >> m;
	int last = 0;
	rep(i,0,m){
		int p,q;
		cin >> p >> q;
		int x = (p + last) % n + 1;
		int k = (q + last) % n;
		
		int ver = min(dep[x] + k,n);
		last = query(version[ver],0,n+4,st[x],et[x]-1);
		
		cout << last << "\n";
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