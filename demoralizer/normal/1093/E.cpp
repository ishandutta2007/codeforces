#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fbo               find_by_order
#define ook               order_of_key
template<typename T>
using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

// #define int               long long
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

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	oset<int> A[maxn];
	int query(int i, int x){
		int sum = 0;
		while (i > 0) 
			sum += A[i].ook(x), i -= LSB(i);
		return sum;
	}
	void insert(int i, int k){
		if(i<1)return;
		while (i < maxn) 
			A[i].insert(k), i += LSB(i);
	}
	void erase(int i, int k){
		if(i<1)return;
		while (i < maxn) 
			A[i].erase(k), i += LSB(i);
	}
	int query(int i, int x, int y){
		return query(i, y + 1) - query(i, x);
	}
	int query(int l, int r, int x, int y){
		return query(r,x,y) - query(l-1,x,y);
	}
}fenw;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n+1);
	rep(i,1,n+1){
		int t;
		cin >> t;
		a[t] = i;
	}
	vector<int> b(n+1);
	rep(i,1,n+1){
		cin >> b[i];
		b[i] = a[b[i]];
		fenw.insert(i,b[i]);
	}
	
	while(m--){
		int t;
		cin >> t;
		if(t == 2){
			int x,y;
			cin >> x >> y;
			fenw.erase(x,b[x]);
			fenw.erase(y,b[y]);
			swap(b[x],b[y]);
			fenw.insert(x,b[x]);
			fenw.insert(y,b[y]);
		}
		else{
			int x,y,l,r;
			cin >> x >> y >> l >> r;
			int ans = fenw.query(l,r,x,y);
			cout << ans << "\n";
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