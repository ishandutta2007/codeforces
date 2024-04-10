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

const int N=4e5+5;

struct node{
	long long v = 0;
	node *left = NULL, *right = NULL;
}
nodes[25*N];
int cnt = 1;
node* create(){
	nodes[cnt].v = 0;
	nodes[cnt].left = NULL;
	nodes[cnt].right = NULL;
	return (nodes+cnt++);
}

long long query(node *t,int l,int r,int tl = 0,int tr = N - 1){
	if(tl > r || tr < l) return 0;
	if(tl >= l && tr <= r){
		return t->v;
	}
	int tm = (tl+tr)/2;
	return query(t->left,l,r,tl,tm) + query(t->right,l,r,tm+1,tr);
}

node* update(node *t,int x,int v,int tl = 0,int tr = N - 1){
	node* tmp = create();
	tmp->left = t->left;
	tmp->right = t->right;
	if(tl == tr){
		tmp->v = v;
		return tmp;
	}
	int tm = (tl+tr)/2;
	if(x<=tm){
		tmp->left = update(tmp->left,x,v,tl,tm);
	}
	else{
		tmp->right = update(tmp->right,x,v,tm+1,tr);
	}
	tmp->v = tmp->left->v + tmp->right->v;
	return tmp;
}

node* build(int tl = 0,int tr = N - 1){
	node* t = create();
	if(tl == tr){
		t->v = 0;
		return t;
	}
	int tm = (tl+tr)/2;
	t->left = build(tl,tm);
	t->right = build(tm+1,tr);
	return t;
}

node* tree[N];
int sz[N];

void solve(){
	long long last = 0;
	int q;
	cin >> q;
	
	tree[1] = build();
	sz[1] = 1;
	int cnt = 1;
	
	rep(i,0,q){
		long long t,a,b;
		cin>>t>>a>>b;
		a ^= last;
		b ^= last;
		if(t == 1){
			cnt++;
			int L = 0, U = sz[a] - 1, ans = sz[a];
			while(L <= U){
				int m = (L+U)/2;
				if(query(tree[a],m,m) < b){
					ans = m;
					U = m - 1;
				}
				else{
					L = m + 1;
				}
			}
			sz[cnt] = ans + 1;
			tree[cnt] = update(tree[a],ans,b);
		}
		else{
			int L = 0, U = sz[a] - 1, ans = sz[a];
			while(L <= U){
				int m = (L+U)/2;
				if(query(tree[a],m,sz[a]-1) <= b){
					ans = m;
					U = m - 1;
				}
				else{
					L = m + 1;
				}
			}
			last = sz[a] - ans;
			cout << last << "\n";
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