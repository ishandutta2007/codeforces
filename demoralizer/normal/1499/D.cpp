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

const int N=2e7+5;

int cnt[N];

#define SIEVE
int primes[N];
void sieve(){
	for(int i=2;i<N;i++){
		if(primes[i]==0){
			for(int j=i;j<N;j+=i){
				primes[j]=1;
				cnt[j]++;
			}
		}
		primes[i]^=1;
	}
}

void solve(){
	// x is a multiple of gcd(a,b)
	
	// cL - dG = x
	
	// let y = x/G
	
	// cL/G - d = y
	
	// L/G = a/G * b/G
	
	// a/G and b/G are coprime
	
	
	// c(ab) = (y + d)
	
	// (ab) = z / c
	
	int c,d,x;
	cin >> c >> d >> x;
	
	vector<int> fact;
	for(int i = 1; i * i <= x; i++){
		if(x % i) continue;
		fact.pb(i);
		if(i != x / i){
			fact.pb(x / i);
		}
	}
	
	int ans = 0;
	for(int g:fact){
		int y = x / g;
		int z = y + d;
		if(z % c != 0){
			continue;
		}
		z /= c;
		ans += (1 << cnt[z]);
	}
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