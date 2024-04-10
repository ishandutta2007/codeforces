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

const int N=1e6+5;

#define NCR
#define PRIME	M
int pw(int a,int p=M-2,int MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}
int fact[N],invfact[N];
void init(){
	int p=PRIME;
	fact[0]=1;
	int i;
	for(i=1;i<N;i++){
		fact[i]=i*fact[i-1]%p;
	}
	i--;
	invfact[i]=pw(fact[i],p-2,p);
	for(i--;i>=0;i--){
		invfact[i]=invfact[i+1]*(i+1)%p;
	}
}
int ncr(int n,int r){
	if(r > n || n < 0 || r < 0)return 0;
	return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;
}

int tot = 0;
int n;
void fun(vector<int> seq){
	int ans = 1;
	vector<int> v;
	for(int x:seq){
		v.pb(n/x);
	}
	for(int i = sz(v) - 1; i > 0; i--){
		v[i] -= v[i - 1];
	}
	for(int x:v){
		ans *= fact[x];
		ans %= M;
	}
	
	while(sz(v) > 1){
		int y = v.back();
		v.ppb();
		int x = v.back();
		v.ppb();
		
		ans *= ncr(x+y-1,y);
		ans %= M;
		
		v.pb(x + y);
	}
	
	tot = (tot + ans) % M;
}

void solve(){
	cin >> n;
	int x = 1;
	while(x * 2 <= n) x *= 2;
	
	vector<int> v;
	v.pb(x);
	while(v.back() != 1){
		v.pb(v.back() / 2);
	}
	fun(v);
	
	x /= 2;
	x *= 3;
	if(x <= n){
		// do for this also
		int k = sz(v);
		rep(i,0,k-1){
			v.clear();
			v.pb(x);
			rep(j,0,k-1){
				v.pb(v.back() / (2 + (i == j)));
			}
			fun(v);
		}
	}
	
	cout << tot;
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