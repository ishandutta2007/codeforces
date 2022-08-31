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
const int32_t M=998244353;

const int N=2e5+5;

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	int A[maxn];
	int query(int i){
		int sum = 0;
		while (i > 0) 
			(sum += A[i]) %= M, i -= LSB(i);
		return sum;
	}
	void update(int i, int k){
		if(i<1)return;
		while (i < maxn) 
			(A[i] += k) %= M, i += LSB(i);
	}
	void rupd(int l,int r,int v){
		update(l,v);
		update(r+1,-v);
	}
	int rquery(int l,int r){
		return (query(r) - query(l - 1) + M) % M;
	}
}fenw;

int x[N], y[N], s[N];
int dp[N];

set<pii> p;

void solve(){
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> x[i] >> y[i] >> s[i];
		p.insert({x[i],i});
	}
	
	rep(i,1,n+1){
		int jumpto = p.lower_bound({y[i], -1})->sc;
		dp[i] = (x[i] - y[i]) % M;
		if(jumpto != i){
			dp[i] = (dp[i] + fenw.rquery(jumpto,i - 1)) % M;
		}
		fenw.update(i,dp[i]);
	}
	
	int ans = 1;
	rep(i,1,n+1){
		ans = (ans + x[i] - x[i - 1]) % M;
		if(s[i]) ans = (ans + dp[i]) % M;
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