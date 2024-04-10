#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 202000;
int n,q;char s[N];
struct node{
	int l,r,qzadd,qzsub,hzadd,hzsub,ans;
}tree[N<<2];
void init(int k, char x){
	tree[k].ans=1;
	if(x==')'){
		tree[k].l=1;tree[k].r=0;
		tree[k].qzadd=1;tree[k].qzsub=0;
		tree[k].hzadd=1;tree[k].hzsub=1;
	}
	else{
		tree[k].l=0;tree[k].r=1;
		tree[k].qzadd=1;tree[k].qzsub=1;
		tree[k].hzadd=1;tree[k].hzsub=0;
	}
}
inline void upd(int k){
	tree[k].l=tree[k<<1].l+max(tree[k<<1|1].l-tree[k<<1].r,0);
	tree[k].r=tree[k<<1|1].r+max(tree[k<<1].r-tree[k<<1|1].l,0);
	tree[k].qzsub=max(tree[k<<1].qzsub,tree[k<<1|1].qzsub+tree[k<<1].r-tree[k<<1].l);
	tree[k].hzsub=max(tree[k<<1|1].hzsub,tree[k<<1].hzsub+tree[k<<1|1].l-tree[k<<1|1].r);
	int l1=tree[k<<1].l,r1=tree[k<<1].r,l2=tree[k<<1|1].l,r2=tree[k<<1|1].r;
	tree[k].qzadd=max(tree[k<<1].qzadd,max(l1+r1+tree[k<<1|1].qzsub,l1-r1+tree[k<<1|1].qzadd));
	tree[k].hzadd=max(tree[k<<1|1].hzadd,max(-l2+r2+tree[k<<1].hzadd,l2+r2+tree[k<<1].hzsub));
	tree[k].ans=max(max(tree[k<<1].hzadd+tree[k<<1|1].qzsub,tree[k<<1].hzsub+tree[k<<1|1].qzadd),max(tree[k<<1].ans,tree[k<<1|1].ans));
}
void build(int k, int l, int r){
	if(l==r){
		init(k,s[l]);return;
	}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	upd(k);
}
void modify(int k, int p, char x, int l, int r){
	if(l==r){
		init(k,x);return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)modify(k<<1,p,x,l,mid);else modify(k<<1|1,p,x,mid+1,r);
	upd(k);
}
int main() {
	read(n);read(q);scanf("%s",s+1);n=2*(n-1);
	build(1,1,n);printf("%d\n",tree[1].ans);
	while(q--){
		int x,y;read(x);read(y);
		if(s[x]!=s[y]){
			modify(1,x,s[y],1,n);
			modify(1,y,s[x],1,n);swap(s[x],s[y]);
		}
		printf("%d\n",tree[1].ans);
	}
	return 0;
}