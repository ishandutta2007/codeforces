#include "bits/stdc++.h"
using namespace std;
#define ll               long long
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

const int N=2005;

int n,k;
int l[N],r[N],a[N];

unordered_map<int, ll> dp[N];

ll calc(int id,int rem){
	if(id == n){
		return 0;
	}
	ll tmp = a[id] - (r[id] - l[id]) * 1LL * k - rem;
	if(tmp > 0){
		return INF;
	}
	
	if(dp[id].count(rem)){
		return dp[id][rem];
	}
	
	tmp = a[id] - rem;
	
	int m = (tmp + k - 1) / k;
	int new_rem = m * k - tmp;
	
	ll ans1 = calc(id+1,new_rem);
	
	if(m < (l[id+1] - l[id])){
		ll ans2 = new_rem + calc(id+1,k);
		amin(ans1,ans2);
	}
	if(ans1 >= INF) ans1 = INF;
	
	return (dp[id][rem] = ans1);
}

void solve(){
	cin >> n >> k;
	
	ll val = 0;
	
	rep(i,0,n){
		cin >> l[i] >> r[i] >> a[i];
		val += a[i];
	}
	
	ll ans = calc(0,k);
	if(ans >= INF) ans = -1;
	else ans += val;
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