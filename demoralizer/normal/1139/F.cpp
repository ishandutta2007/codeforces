#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fbo               find_by_order
#define ook               order_of_key
template<typename T>
using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
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

int p[N], s[N], b[N];
int u[N], v[N];

int inc[N], pref[N];
int c[N], d[N], e[N];

int ans[N];

#define LSB(i) ((i) & -(i))
const int maxn=2*N;
struct fenwick{
	oset<pii> A[maxn];
	int cnt = 1;
	int query(int i, int val){
		i++;
		int sum = 0;
		while (i > 0) 
			sum += sz(A[i]) - (A[i].ook({val,-1})), i -= LSB(i);
		return sum;
	}
	void update(int i, int k){
		i++;
		if(i<1)return;
		while (i < maxn) 
			A[i].insert({k,cnt}), i += LSB(i);
		cnt++;
	}
}fenw;

void solve(){
	int n,m;
	cin >> n >> m;
	
	rep(i,1,n+1){
		cin >> p[i];
	}
	rep(i,1,n+1){
		cin >> s[i];
	}
	rep(i,1,n+1){
		cin >> b[i];
		int x = b[i];
		int y = p[i];
		u[i] = y - x;
		v[i] = y + x;
	}
	
	rep(i,1,m+1){
		cin >> inc[i];
	}
	rep(i,1,m+1){
		cin >> pref[i];
		int x = pref[i];
		int y = inc[i];
		c[i] = y - x;
		d[i] = y + x;
		e[i] = y;
	}
	
	// u <= c, v <= d, s >= e
	auto compress = [&](int *a, int *b){
		vector<int> coor;
		rep(i,1,n+1){
			coor.pb(a[i]);
		}
		rep(i,1,m+1){
			coor.pb(b[i]);
		}
		sort(all(coor));
		uniq(coor);
		rep(i,1,n+1){
			a[i] = lower_bound(all(coor),a[i]) - coor.begin();
		}
		rep(i,1,m+1){
			b[i] = lower_bound(all(coor),b[i]) - coor.begin();
		}
	};
	compress(u,c);
	compress(v,d);
	compress(s,e);
	
	vector<pii> queries, dishes;
	rep(i,1,m+1){
		queries.pb({c[i],i});
	}
	sort(all(queries));
	rep(i,1,n+1){
		dishes.pb({u[i],i});
	}
	sort(all(dishes));
	reverse(all(dishes));
	
	for(auto q:queries){
		int i = q.sc;
		while(sz(dishes) && dishes.back().fr <= c[i]){
			int j = dishes.back().sc;
			dishes.ppb();
			fenw.update(v[j],s[j]);
		}
		ans[i] = fenw.query(d[i],e[i]);
	}
	
	rep(i,1,m+1){
		cout << ans[i] << " ";
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