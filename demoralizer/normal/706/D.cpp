#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

struct node
{
	int child[2]={0};
	int ends=0;
};
vector<node> trie;
int create(){
	trie.pb(node());
	return (sz(trie)-1);
}
void insert(int x,int val,int root=0,int pos=29){
	trie[root].ends+=val;
	if(pos<0){
		return;
	}
	int next=(x>>pos)&1;
	if(!trie[root].child[next]){
		int y=create();
		trie[root].child[next]=y;
	}
	insert(x,val,trie[root].child[next],pos-1);
}

int dfs(int x,int root=0,int pos=29){
	if(pos<0){
		return 0;
	}
	int next=(x>>pos)&1;
	next^=1;
	if(trie[root].child[next] && trie[trie[root].child[next]].ends){
		return (1<<pos)+dfs(x,trie[root].child[next],pos-1);
	}
	else{
		return dfs(x,trie[root].child[next^1],pos-1);
	}
}

void solve(){
	trie.pb(node());
	int q;
	cin>>q;
	insert(0,1);
	rep(zz,0,q){
		char c;
		int x;
		cin>>c>>x;
		// cout<<c<<" "<<x<<"\n";
		if(c=='?'){
			cout<<dfs(x)<<"\n";
		}
		else{
			insert(x,(c=='+')?(1):(-1));
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}