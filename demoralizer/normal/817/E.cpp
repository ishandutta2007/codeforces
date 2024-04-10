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

struct node{
	struct node* left=NULL;
	struct node* right=NULL;
	int cum = 0;
};


struct node* root=new node();

node* create(){
	struct node* temp = new node();
	temp->left = NULL;
	temp->right = NULL;
	temp->cum = 0;
	return temp;
}
void add(int p){
	struct node* cur = root;
	for(int i=27; i>=0; i--){
		cur->cum++;
		if((p&(1<<i))==0){
			if(cur->left == NULL){
				cur->left = create();
			}
			cur = cur->left;
		}
		else{
			if(cur->right == NULL){
				cur->right = create();
			}
			cur = cur->right;
		}
	}
	cur->cum++;
}
void erase(int p){
	node* cur = root;
	for(int i=27; i>=0; i--){
		cur->cum--;
		if((p&(1<<i))==0){
			cur = cur->left;
		}
		else cur = cur->right;
	}
	cur->cum--;
}
int query(int p, int l){
	int ans = 0;
	node* cur = root;
	for(int i=27; i>=0&&cur!=NULL; i--){
		int required_bit = l&(1<<i);
		if(required_bit){
			if((p&(1<<i))==0){
 				if(cur->left) ans += cur->left->cum;
				cur = cur->right;
				continue;
			}
			else{
				if(cur->right) ans += cur->right->cum;
				cur = cur->left;
				continue;
			}
		}
		else{
			if((p&(1<<i))==0){
				cur = cur->left;
				continue;
			}
			else{
				cur = cur->right;
				continue;
			}
		}
	}
	return ans;
}
void solve(){
	int q;
	cin>>q;
	rep(zz,0,q){
		int t,p;
		cin>>t>>p;
		if(t==1){
			add(p);
		}
		else if(t==2){
			erase(p);
		}
		else{
			int l;
			cin>>l;
			cout<<query(p,l)<<"\n";
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
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