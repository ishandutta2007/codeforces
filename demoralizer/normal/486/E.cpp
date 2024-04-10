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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fbo               find_by_order
#define ook               order_of_key
template<typename T>
using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

const int N=1e5+5;

int v[N];
oset<int> o;
int lis[N];
int a[N];
int grp[N];
int cnt[N];

void solve(){
	int n;
	cin >> n;
	
	int mx = 0;
	
	rep(i,0,n){
		cin >> a[i];
		lis[i] = 1;
		lis[i] += o.ook(a[i]);
		auto it = o.lower_bound(a[i]);
		if(it != o.end()) o.erase(it);
		o.insert(a[i]);
		amax(mx,lis[i]);
	}
	
	for(int i = n - 1; i >= 0; i--){
		if(lis[i] == mx || a[i] < v[lis[i]+1]){
			// part of lis
			grp[i] = 2;
			cnt[lis[i]]++;
			amax(v[lis[i]],a[i]);
		}
		else{
			grp[i] = 1;
		}
	}
	
	rep(i,0,n){
		if(grp[i] == 2 && cnt[lis[i]] == 1) grp[i] = 3;
		cout << grp[i];
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