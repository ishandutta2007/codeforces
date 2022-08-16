#include <bits/stdc++.h>
using namespace std;
// #define int               long long
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

const long long INF=1e10;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2e5+5;


// TRIE
		struct node
		{
			int child[2]={0};
		};
		node trie[62*N];
		vector<int> avail;
		int create(){
			int x=avail.back();
			avail.ppb();
			trie[x].child[0]=0;
			trie[x].child[1]=0;
			return x;
		}
		void insert(int val,int root,int pos=29){
			if(pos<0)return;
			int next=(val>>pos)&1;
			if(!trie[root].child[next]){
				trie[root].child[next]=create();
			}
			insert(val,trie[root].child[next],pos-1);
		}
		void free(int root){
			rep(i,0,2){
				if(trie[root].child[i])free(trie[root].child[i]);
			}
			avail.pb(root);
		}
		int minxor(int val,int root,int pos=29){
			if(pos<0)return 0;
			int next=(val>>pos)&1;
			if(!trie[root].child[next]){
				return (1<<pos)+minxor(val,trie[root].child[next^1],pos-1);
			}
			return minxor(val,trie[root].child[next],pos-1);
		}
//TRIE



vector<int> elems[N];
int unionNodes(int &parent_a,int &parent_b)
{
	if(sz(elems[parent_a])>=sz(elems[parent_b]))
	{
		swap(parent_a,parent_b);
	}
	long long tans=INF;
	for(int x:elems[parent_a]){
		amin(tans,minxor(x,parent_b));
	}
	while(!elems[parent_a].empty()){
		elems[parent_b].pb(elems[parent_a].back());
		insert(elems[parent_a].back(),parent_b);
		elems[parent_a].ppb();
	}
	free(parent_a);
	return tans;
}


int n;
void solve(){
	rep(i,1,62*N){
		avail.pb(i);
	}
	reverse(all(avail));
	cin>>n;
	set<int> inp;
	rep(i,0,n){
		int xx;
		cin>>xx;
		inp.insert(xx);
	}
	
	vector<pii> vals,newvals;
	for(int xx:inp){
		vals.pb({xx,0});
		vals.back().sc=create();
	}
	sort(all(vals));
	int n=sz(vals);
	rep(i,0,n){
		elems[vals[i].sc].pb(vals[i].fr);
		insert(vals[i].fr,vals[i].sc);
	}
	long long ans=0;
	
	rep(i,0,30){
		while(!vals.empty()){
			if(!newvals.empty() && newvals.back().fr==(vals.back().fr>>1)){
				int parent_a=newvals.back().sc,parent_b=vals.back().sc;
				ans+=unionNodes(parent_a,parent_b);
				newvals.back().sc=parent_b;
			}
			else{
				newvals.pb({vals.back().fr>>1,vals.back().sc});
			}
			vals.ppb();
		}
		sort(all(newvals));
		swap(vals,newvals);
	}
	cout<<ans;
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