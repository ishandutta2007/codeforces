#include "bits/stdc++.h"
using namespace std;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

// #define int               long long
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

const int N=0;

vector<int> b;
using ll = long long;
ll dp[61][8],op[9+4],ep[9+4];


bool isspace(char c) {
	return c == ' ' || c == '\n';
}


ll readLL() {
	ll x = 0;
	char c = ' ';
	while(isspace(c)) c = _getchar_nolock();
	while(!isspace(c)) {
		x = 10 * x + (int)(c - '0');
		c = _getchar_nolock();
	}
	return x;
}


void solve(){
	long long n = readLL();
	b.clear();
	while(n){
		b.pb(n%2);
		n /= 2;
	}
	int l = sz(b);
	
	int tmp;
	// dp[id][c] = id, carry
	
	dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;
		
	rep(id,1,l){
		rep(x,0,8){
			if(x % 2){
				op[x/2+5] = dp[id-1][x] + op[x/2+4];
			}
			else{
				ep[x/2+5] = dp[id-1][x] + ep[x/2+4];
			}
		}
		rep(x,5,8){
			op[x+4] = op[x+3];
			ep[x+4] = ep[x+3];
		}
		rep(j,0,7){
			dp[id][j] = op[j+4+b[id]] + ep[j+5] - op[j+b[id]] - ep[j+1];
		}
		if(id % 10 == 0){
			rep(j,0,7){
				dp[id][j] %= M;
			}
		}
	}

		
	
	printf("%d\n",(dp[l-1][0] % M + M)%M);
	
}
signed main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=readLL();
	while(t--) solve();
	return 0;
}