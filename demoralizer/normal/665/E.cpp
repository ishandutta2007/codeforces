#include "bits/stdc++.h"
using namespace std;
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
const int32_t MM=998244353;

const int N=1e6+5;

int n,k;
int trie[40*N][3];

int cnt = 1;
int create(){
	return cnt++;
}

void insert(int x){
	int cur = 0;
	trie[cur][2]++;
	for(int i = 29; i >= 0; i--){
		int nxt = x>>i&1;
		if(!trie[cur][nxt]){
			trie[cur][nxt] = create();
		}
		cur = trie[cur][nxt];
		trie[cur][2]++;
	}
}

int query(int x){
	int cur = 0;
	int ans = 0;
	for(int i = 29; i >= 0; i--){
		int nxtk = k>>i&1;
		int nxtx = x>>i&1;
		if(nxtk){
			cur = trie[cur][!nxtx];
			if(!cur) return ans;
		}
		else{
			if(trie[cur][!nxtx]) ans += trie[trie[cur][!nxtx]][2];
			cur = trie[cur][nxtx];
			if(!cur) return ans;
		}
	}
	return ans;
}

int a[N];

void solve(){
	cin>>n>>k;
	k--;
	long long ans = 0;
	insert(0);
	rep(i,1,n+1){
		cin>>a[i];
		a[i] ^= a[i-1];
		ans += query(a[i]);
		insert(a[i]);
	}
	cout<<ans;
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