#include "bits/stdc++.h"
using namespace std;
#define int long long
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

const int N=100;

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

vector<int> pr;

int paths(int s,int b){
	int num = 0;
	int ans = 1;
	for(int x:pr){
		int cnt1 = 0, cnt2 = 0;
		while(s % x == 0){
			s /= x;
			cnt1++;
		}
		while(b % x == 0){
			b /= x;
			cnt2++;
		}
		int diff = cnt2 - cnt1;
		ans = 1ll * ans * invfact[diff] % M;
		num += diff;
	}
	ans = 1ll * ans * fact[num] % M;
	return ans;
}

void solve(){
	int d;
	cin >> d;
	for(int i = 2; i * i <= d; i++){
		if(d % i == 0){
			pr.pb(i);
			while(d % i == 0){
				d /= i;
			}
		}
	}
	if(d != 1){
		pr.pb(d);
	}
	
	int q;
	cin >> q;
	rep(i,0,q){
		int u,v;
		cin >> u >> v;
		int g = __gcd(u,v);
		int ans = 1ll * paths(g,u) * paths(g,v) % M;
		cout << ans << "\n";
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