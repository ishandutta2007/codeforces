#include <bits/stdc++.h>
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

const int N=6e5+5;

const int maxn=N;
const int max_logn=20;
template<typename T>
struct SparseTable{
	int log[maxn];
	T dp[max_logn][maxn];
	T combine(T a,T b){
		return min(a,b);
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

int l[N],r[N];
set<int> co;
map<int, int> cocom;

void solve(){
	int n;
	cin>>n;
	vector<int> arr(N);
	rep(i,0,n){
		cin>>l[i]>>r[i];
		co.insert(l[i]);
		co.insert(r[i]);
		co.insert(r[i]+1);
	}
	int cnt = 0;
	for(int x:co){
		cocom[x] = cnt++;
	}
	rep(i,0,n){
		l[i] = cocom[l[i]];
		r[i] = cocom[r[i]];
		arr[l[i]] += 1;
		arr[r[i]+1] -= 1;
	}
	rep(i,1,N){
		arr[i] += arr[i-1];
	}
	sp.build(arr);
	rep(i,0,n){
		if(sp.query(l[i],r[i]) > 1){
			cout<<i+1;
			return;
		}
	}
	cout<<-1;
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