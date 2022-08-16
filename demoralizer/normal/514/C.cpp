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

const int N=3e5+5;

struct node{
	node* next[3] = {0};
	bool end = 0;
} ns[24*N];
int cnt = 1;
node* create(){
	if(cnt < 24*N) return (ns+cnt++);
	return new node;
}

void insert(string &s){
	node* root = ns;
	for(char c:s){
		int k = c-'a';
		if(!root->next[k]) root->next[k] = create();
		root = root->next[k];
	}
	root->end = 1;
}

bool dfs(node* z,string &s,int pos,bool chng){
	if(pos == sz(s)){
		return (z->end) && chng;
	}
	int k = s[pos]-'a';
	if(z->next[k] && dfs(z->next[k],s,pos+1,chng)) return 1;
	if(chng) return 0;
	rep(i,0,3){
		if(i == k || !z->next[i]) continue;
		if(dfs(z->next[i],s,pos+1,1)) return 1;
	}
	return 0;
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,n){
		string s;
		cin>>s;
		insert(s);
	}
	vector<string> pr={"NO\n","YES\n"};
	rep(i,0,m){
		string s;
		cin>>s;
		cout<<pr[dfs(ns,s,0,0)];
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