#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
struct SegmentTree{
	int tree[MAXN<<2];
	void build(int x,int l,int r){
		tree[x]=-1;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(lc(x),l,mid);build(rc(x),mid+1,r);
	}
	void query(int x,int l,int r,int k){
		if(l==r){
			printf("! %d\n",l);
			fflush(stdout);
			tree[x]=1;
			return;
		}
		int mid=(l+r)>>1;
		if(tree[lc(x)]!=-1){
			tree[rc(x)]=tree[x]-tree[lc(x)];
		}else if(tree[rc(x)]!=-1){
			tree[lc(x)]=tree[x]-tree[rc(x)];
		}else{
			printf("? %d %d\n",l,mid);
			fflush(stdout);
			cin>>tree[lc(x)];
			tree[rc(x)]=tree[x]-tree[lc(x)];
		}
		if((mid-l+1-tree[lc(x)])>=k){
			query(lc(x),l,mid,k);
		}else{
			query(rc(x),mid+1,r,k-(mid-l+1-tree[lc(x)]));
		}
		tree[x]++;
	}
}tree;
ll n,t,k;
int main(){
	cin>>n>>t;
	tree.build(1,1,n);
	rep(i,1,t){
		cin>>k;
		if(i==1){
			printf("? %lld %lld\n",1LL,n);
			fflush(stdout);
			cin>>tree.tree[1];
		}
		tree.query(1,1,n,k);
	}

	return 0;
}