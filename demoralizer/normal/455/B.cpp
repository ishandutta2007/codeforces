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
	bool end;
	node* next[26];
}
nodes[N];
int cnt = 1;

node* create(){
	nodes[cnt].end = 0;
	rep(i,0,26) nodes[cnt].next[i] = NULL;
	return nodes+cnt++;
}
node* root;
void insert(string &s){
	node* cur = root;
	for(char c:s){
		int x = c-'a';
		if(!cur->next[x]) cur->next[x] = create();
		cur = cur->next[x];
	}
	cur->end = 1;
}

bool dfswin(node* cur){
	rep(i,0,26){
		if(!cur->next[i])
			continue;
		if(!dfswin(cur->next[i])){
			return 1;
		}
	}
	return 0;
}

bool dfslose(node* cur){
	bool leaf = 1;
	rep(i,0,26){
		if(!cur->next[i])
			continue;
		leaf = 0;
		if(!dfslose(cur->next[i])){
			return 1;
		}
	}
	return leaf;
}


void solve(){
	root = create();
	int n,k;
	cin>>n>>k;
	rep(i,0,n){
		string s;
		cin>>s;
		insert(s);
	}
	bool win = dfswin(root);
	bool lose = dfslose(root);
		
	if(win & lose){
		cout << "First";
	}
	else if(win){
		if(k%2){
			cout << "First";
		}
		else{
			cout << "Second";
		}
	}
	else{
		cout << "Second";
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