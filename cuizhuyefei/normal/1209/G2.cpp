#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,q,a[N];set<int>Set[N];
struct node{
	int mn,lzy,mx,lmx,rmx,ans;
}tree[N<<2];
void upd(int k){
	tree[k].mn=min(tree[k<<1].mn,tree[k<<1|1].mn);
	tree[k].mx=max(tree[k<<1].mx,tree[k<<1|1].mx);
	if(tree[k<<1].mn<tree[k<<1|1].mn){
		tree[k].ans=tree[k<<1].ans;tree[k].lmx=tree[k<<1].lmx;
		tree[k].rmx=max(tree[k<<1].rmx,tree[k<<1|1].mx);
	}
	else if(tree[k<<1].mn>tree[k<<1|1].mn){
		tree[k].ans=tree[k<<1|1].ans;tree[k].rmx=tree[k<<1|1].rmx;
		tree[k].lmx=max(tree[k<<1].mx,tree[k<<1|1].lmx);
	}
	else{
		tree[k].ans=tree[k<<1].ans+tree[k<<1|1].ans+max(tree[k<<1].rmx,tree[k<<1|1].lmx);
		tree[k].lmx=tree[k<<1].lmx;tree[k].rmx=tree[k<<1|1].rmx;
	}
}
void pushdown(int k){
	if(tree[k].lzy){
		tree[k<<1].lzy+=tree[k].lzy;tree[k<<1].mn+=tree[k].lzy;
		tree[k<<1|1].lzy+=tree[k].lzy;tree[k<<1|1].mn+=tree[k].lzy;
		tree[k].lzy=0;
	}
}
void mdy(int k, int l, int r, int x, int L, int R){
	if(l==L&&r==R){tree[k].mn+=x;tree[k].lzy+=x;return;}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)mdy(k<<1,l,r,x,L,mid);
	else if(l>mid)mdy(k<<1|1,l,r,x,mid+1,R);
	else mdy(k<<1,l,mid,x,L,mid),mdy(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k);
}
void modify(int k, int p, int x, int l, int r){
	if(l==r){tree[k].mx=tree[k].lmx=x;return;}
	int mid=(l+r)>>1;pushdown(k);
	if(p<=mid)modify(k<<1,p,x,l,mid);else modify(k<<1|1,p,x,mid+1,r);
	upd(k);
}
void ins(int x, int t){
	if(Set[x].empty())return;
	if(Set[x].size()>=2)mdy(1,*Set[x].begin(),(*Set[x].rbegin())-1,t,0,n);
	modify(1,*Set[x].begin(),t>0?SZ(Set[x]):0,0,n);
}
int main() {
	read(n);read(q);rep(i,1,n)read(a[i]),Set[a[i]].insert(i);
	rep(i,0,n)modify(1,i,0,0,n);
	rep(i,1,2e5)ins(i,1);
	printf("%d\n",n-tree[1].ans);
	while(q--){
		int x,y;read(x);read(y);
		ins(a[x],-1);Set[a[x]].erase(x);ins(a[x],1);
		a[x]=y;
		ins(a[x],-1);Set[a[x]].insert(x);ins(a[x],1);
		printf("%d\n",n-tree[1].ans);
	}
	return 0;
}