#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fbo               find_by_order
#define ook               order_of_key
template<typename T>
using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,greater<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
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

const int N=2e5+5;

int p[N];
int id[N];

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
	void rupd(int l,int r,int v){
		update(l,v);
		update(r+1,-v);
	}
}f,g;

void solve(){
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> p[i];
		id[p[i]] = i;
	}
	
	int inversions = 0;
	oset<int> s;
	s.insert(id[1]);
	f.update(id[1],1);
	g.update(id[1],id[1]);
	
	int ct = 1;
	int st = id[1];
	
	cout << 0 << " ";
	rep(i,2,n+1){
		
		inversions += s.order_of_key(id[i]);
		
		s.insert(id[i]);
		f.update(id[i],1);
		g.update(id[i],id[i]);
		ct++;
		st += id[i];
		
		int x = sz(s);
		
		int val = *s.find_by_order(x / 2);
		
		int cnt = f.query(val);
		int sum = g.query(val);
		
		int ans = (val + val - cnt + 1) * cnt / 2 - sum;
		
		cnt = ct - cnt;
		sum = st - sum;
		
		// cout << cnt << " " << sum << "\n";
		
		ans += sum - (val + 1 + val + cnt) * cnt / 2;
		
		cout << ans + inversions << " ";
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