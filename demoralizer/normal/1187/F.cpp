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

int l[N];
int r[N];

int z[N];

void solve(){
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> l[i];
	}
	rep(i,0,n){
		cin >> r[i];
	}
	n++;
	
	int sum = 0, sqsum = 0;
	rep(i,1,n){
		int x = max(l[i-1],l[i]);
		int y = min(r[i-1],r[i]);
		int inter = max(0LL,y - x + 1);
		
		int tmp = inter * pw(r[i] - l[i] + 1) % M * pw(r[i-1] - l[i-1] + 1) % M;
		tmp = (1 - tmp + M) % M;
		z[i] = tmp;
		
		sum = (sum + tmp) % M;
		sqsum = (sqsum + tmp * tmp) % M;
		if(i > 1){
			sqsum = (sqsum + 2 * z[i] * z[i-1]) % M;
			
			amax(x,l[i-2]);
			amin(y,r[i-2]);
			inter = max(0LL,y - x + 1);
			
			tmp = (1 - z[i] + M) % M + (1 - z[i-1] + M) % M;
			tmp %= M;
			tmp = (tmp + M - inter * pw(r[i] - l[i] + 1) % M * pw(r[i-1] - l[i-1] + 1) % M * pw(r[i-2] - l[i-2] + 1) % M) % M;
			tmp = (1 - tmp + M) % M;
			
			sqsum = (sqsum - 2 * tmp % M + M) % M;
		}
	}
	
	int ans = (sum + (sum * sum % M - sqsum + M) % M) % M;
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
	//cin>>t;
	while(t--) solve();
	return 0;
}