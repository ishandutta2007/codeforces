#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=3e5+10,MAXM=1e7+10;
int n,q,a[MAXN],l[MAXN],r[MAXN];
int w[MAXN];
struct Node{int lc,rc,sum;};
struct Seg{
	Node tree[MAXM];
	int tot;
	int newnode(){return ++tot;}
	void copy(int from,int to){
		tree[to].lc=tree[from].lc;
		tree[to].rc=tree[from].rc;
		tree[to].sum=tree[from].sum;
	}
	void pushup(int x){
		tree[x].sum=tree[tree[x].lc].sum+tree[tree[x].rc].sum;
	}
	int update(int x,int l,int r,int pos,int val){
		int p=newnode();copy(x,p);	
		if(l==r){
			tree[p].sum+=val;return p;
		}
		int mid=(l+r)>>1;
		if(pos<=mid)tree[p].lc=update(tree[p].lc,l,mid,pos,val);
		else tree[p].rc=update(tree[p].rc,mid+1,r,pos,val);
		pushup(p);return p;
	}
	int query(int x1,int x2,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r)return tree[x2].sum-tree[x1].sum;
		int mid=(l+r)>>1,ret=0;
		if(ql<=mid)ret+=query(tree[x1].lc,tree[x2].lc,l,mid,ql,qr);
		if(qr>mid)ret+=query(tree[x1].rc,tree[x2].rc,mid+1,r,ql,qr);
		return ret;
	}
}tree;
int rt[MAXN]; 
int check(int mid,int x){
	int val=a[x];
	return tree.query(rt[mid-1],rt[x-1],1,n,mid,n)>=val;
}
void solve(int l,int r){
	int ans=tree.query(rt[l-1],rt[r],1,n,l,n);
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		scanf("%d",&a[i]);
		a[i]=i-a[i];
	}
	rep(i,1,q){scanf("%d%d",&l[i],&r[i]);}
	rep(i,1,n)w[i]=-1;
	rep(i,1,n){
		if(a[i]<0){rt[i]=rt[i-1];continue;}
		if(a[i]==0){
			w[i]=i;
			rt[i]=tree.update(rt[i-1],1,n,w[i],1);
			continue;
		}
		int L=1,R=i-1,ret=-1;
		while(L<=R){
			int mid=(L+R)>>1;
			if(check(mid,i)){
				ret=mid;
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		if(ret==-1){
			rt[i]=rt[i-1];
			continue;
		}
		w[i]=ret;
		rt[i]=tree.update(rt[i-1],1,n,w[i],1);
	}
	rep(i,1,q){
		solve(l[i]+1,n-r[i]);
	}
	return 0;
}