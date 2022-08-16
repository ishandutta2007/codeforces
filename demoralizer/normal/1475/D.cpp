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

const int N=2e5+5;

int a[N];
int b[N];

void solve(){
	int n,m;
	cin >> n >> m;
	
	vector<int> reg,imp;
	
	rep(i,0,n){
		cin >> a[i];
	}
	rep(i,0,n){
		cin >> b[i];
		if(b[i] == 1){
			reg.pb(a[i]);
		}
		else{
			imp.pb(a[i]);
		}
	}
	
	sort(all(reg));
	reverse(all(reg));
	
	sort(all(imp));
	reverse(all(imp));
	
	
	rep(i,1,sz(reg)){
		reg[i] += reg[i - 1];
	}
	
	rep(i,1,sz(imp)){
		imp[i] += imp[i - 1];
	}
	
	int ans = INF;
	
	rep(i,0,sz(imp)+1){
		int ni = i;
		
		int sum = 0;
		if(i){
			sum = imp[i - 1];
		}
		
		int cost = 2 * ni;
		
		if(sum >= m){
			amin(ans,cost);
		}
		
		auto k = lower_bound(all(reg),m - sum) - reg.begin();
		
		if(k < sz(reg)){
			amin(ans,cost + k + 1);
		}
		
	}
	
	if(ans == INF) ans = -1;
	
	cout << ans << "\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}