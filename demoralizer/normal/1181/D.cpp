#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fbo               find_by_order
#define ook               order_of_key
template<typename T>
using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
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

vector<int> vals[N];

int a[N];
int freq[N];
int moves[N];
int ans[N];

void solve(){
	int n,m,q;
	cin >> n >> m >> q;
	rep(i,0,n){
		int x;
		cin >> x;
		a[x]++;
	}
	rep(i,1,m+1){
		vals[a[i]].pb(i);
		freq[a[i]]++;
	}
	rep(i,1,n+1){
		freq[i] += freq[i-1];
		moves[i] = moves[i-1] + freq[i-1];
	}
	
	vector<pii> z;
	
	rep(i,0,q){
		int k;
		cin >> k;
		k -= n;
		z.pb({k,i});
	}
	
	sort(all(z));
	
	oset<int> s;
	// for(int x:vals[0]) s.insert(x);
	int j = -1;
	for(auto x:z){
		int k = x.fr;
		while(j < n && k > moves[j + 1]){
			j++;
			for(int y:vals[j]){
				s.insert(y);
			}
		}
		k -= moves[j];
		k--;
		int tmp = sz(s);
		k %= tmp;
		// cout << k << " " << tmp << "\n";
		ans[x.sc] = *s.find_by_order(k);
	}
	
	
	rep(i,0,q){
		cout << ans[i] << "\n";
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