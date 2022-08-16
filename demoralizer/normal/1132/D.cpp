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

const int N=2e5+5;

int n,k;
long long a[N];
int b[N];
long long tim[N];

long long A[N];

struct cmp
{
	bool operator() (int a,int b){
		return (tim[a] > tim[b]);
	}
};

bool check(long long p){
	priority_queue<int,vector<int>,cmp> q;
	rep(i,0,n){
		tim[i] = a[i] / b[i];
		q.push(i);
		A[i] = a[i];
	}
	rep(t,0,k){
		int cur = q.top();
		q.pop();
		if(A[cur] - t * 1ll * b[cur] < 0){
			return 0;
		}
		A[cur] += p;
		tim[cur] = A[cur] / b[cur];
		q.push(cur);
	}
	return 1;
}

void solve(){
	cin >> n >> k;
	rep(i,0,n){
		cin >> a[i];
	}
	rep(i,0,n){
		cin >> b[i];
	}
	
	// binary search
	
	const long long K = N * 1ll * N * 50;
	
	long long L = 0, U = K;
	long long ans = -1;
	while(L <= U){
		long long m = (L + U) / 2;
		if(check(m)){
			ans = m;
			U = m - 1;
		}
		else{
			L = m + 1;
		}
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