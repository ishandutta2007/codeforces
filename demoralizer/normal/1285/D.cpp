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

struct node{
	int next[2];
};

node trie[30*N];

int cnt = 1;
int create(){
	return cnt++;
}

void insert(int x){
	int root = 0;
	for(int i=29;i>=0;i--){
		int b = x>>i&1;
		if(!trie[root].next[b]){
			trie[root].next[b] = create();
		}
		root = trie[root].next[b];
	}
}


int dfs(int z,int d){
	int v = INF;
	rep(i,0,2){
		if(trie[z].next[i]){
			amin(v,dfs(trie[z].next[i],d-1));
		}
	}
	if(v==INF) v = 0;
	if(trie[z].next[0] && trie[z].next[1]){
		v += (1<<d);
	}
	return v;
}

void solve(){
	int n;
	cin>>n;
	rep(i,0,n){
		int x;
		cin>>x;
		insert(x);
	}
	cout<<dfs(0,29);
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