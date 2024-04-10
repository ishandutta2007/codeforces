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

const int N=1e5+5;

const int maxn=N;
const int max_logn=20;
template<typename T>
struct SparseTable{
	int log[maxn];
	T dp[max_logn][maxn];
	T combine(T a,T b){
		return max(a,b);
	}
	SparseTable(){
		log[1] = 0;
		for (int i = 2; i < maxn; i++)
			log[i] = log[i/2] + 1;
	}
	void build(vector<T> b)
	{
		int n=b.size();
		for (int i = 0; i < n; ++i){
			dp[0][i]=b[i];
		}
		for (int j = 1; j < max_logn; j++)
			for (int i = 0; i + (1 << j) < maxn; i++)
				dp[j][i] = combine(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
	}
	T query(int l,int r)
	{
		int j=log[r-l+1];
		return combine(dp[j][l],dp[j][r-(1<<j)+1]);
	}
};
SparseTable<int> sp;

int a[N];
int lft[N];
int rght[N];

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> b(N);
	rep(i,1,n+1){
		cin>>a[i];
	}
	rep(i,1,n){
		b[i] = abs(a[i] - a[i+1]);
	}
	sp.build(b);
	rep(i,1,n){
		int x = b[i];
		int L = 1, U = i-1;
		lft[i] = i;
		while(L<=U){
			int m = (L+U)/2;
			if(sp.query(m,i-1) < x){
				lft[i] = m;
				U = m - 1;
			}
			else{
				L = m + 1;
			}
		}
		L = i+1, U = n-1;
		rght[i] = i;
		while(L<=U){
			int m=(L+U)/2;
			if(sp.query(i+1,m) <= x){
				rght[i] = m;
				L = m+1;
			}
			else{
				U = m-1;
			}
		}
	}
	
	rep(zzz,0,q){
		int l,r;
		cin>>l>>r;
		r--;
		long long ans = 0;
		rep(i,l,r+1){
			// cout<<i<<" "<<b[i]<<" "<<lft[i]<<" "<<rght[i]<<"\n";
			ans += 1ll * b[i] * (min(rght[i],r) - i + 1) * (i - max(lft[i],l) + 1);
		}
		cout<<ans<<"\n";
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