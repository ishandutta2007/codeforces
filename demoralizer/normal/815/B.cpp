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

int n;
int tmp;
int calc(int id, vector<int> &a){
	int ret = 0;
	int cnt = 0;
	while(id < n/2*2){
		ret += ncr(tmp,cnt) * a[id] % M;
		ret %= M;
		id += 2;
		cnt++;
	}
	return ret;
}


void solve(){
	cin >> n;
	vector<int> a(n);
	for(int &x:a){
		cin>>x;
	}
	
	if(n == 1){
		cout << a[0];
		return;
	}
	
	if(n%2){
		vector<int> b;
		rep(i,0,n-1){
			if(i%2 == 0) b.pb(a[i]+a[i+1]);
			else b.pb(a[i]-a[i+1]);
			b.back() += M;
			b.back() %= M;
		}
		a = b;
	}
	
	tmp = (n-2)/2;
	
	int x = calc(0,a), y = calc(1,a);
	if((n*(n-1)/2) % 2 == 0){
		cout << (x-y+M)%M;
	}
	else{
		cout << (x+y)%M;
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