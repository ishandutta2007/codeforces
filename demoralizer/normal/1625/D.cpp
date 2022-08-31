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

const int N=0;

int p;
struct node
{
    // int val;
    node *child[2];
    
    node(){
    	// val = 0;
    	child[0] = child[1] = NULL;
    }
};

void insert(node *trie, int x, int ind)
{   
    if(ind < 0) {
        return;
    }
    int k=(x>>ind)&1;

    if(!trie->child[k]) {
        trie->child[k]=new node;
    }
    insert(trie->child[k], x, ind-1);
}

void find(node *trie, int x, int ind)
{   
    if(ind<0) {
        return;
    }

    int k=(x>>ind)&1;
    k^=1;

    if(!trie->child[k]) {
        k^=1;
    }
    p=p<<1|k;
    find(trie->child[k], x, ind-1);
}


vector<int> ans;

void get(vector<int> &v, int k, int pref){
	node *trie = new node;
	
	int n = sz(v);
	
	rep(i,0,n){
		if(i){
			find(trie,v[i],31);
			if((p^v[i]) >= k){
				ans.pb(p+pref);
				ans.pb(v[i]+pref);
				return;
			}
		}
		insert(trie,v[i],31);
	}
	ans.pb(v[0]+pref);
}

void solve(){
	int n,k;
	cin >> n >> k;
	
	if(k == 0){
		cout << n << "\n";
		rep(i,0,n){
			cout << i + 1 << " ";
		}
		return;
	}
	
	int z = 1;
	int tmp = k;
	while(z <= tmp){
		z *= 2;
	}
	z--;
	
	map<int, vector<int>> m;
	map<int, int> id;
	rep(i,0,n){
		int x;
		cin >> x;
		id[x] = i + 1;
		m[x-(x&z)].push_back(x&z);
	}
	
	for(auto x:m){
		get(x.sc,k,x.fr);
	}
	
	if(sz(ans) == 1) cout << -1;
	else{
		cout << sz(ans) << "\n";
		for(int x:ans){
			cout << id[x] << " ";
		}
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