#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define SZ(x) ((int)x.size())
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b?a:b;}
inline int min(int a, int b) {return a<b?a:b;}
const int N = 200300;
struct seg {int l,r,tp;} a[N];
int l[N],r[N],n,tp[N],s[N],tot,f[N],size[N];

inline int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
inline void merge(int x, int y) {
	x=find(x);y=find(y);if(x>y)swap(x,y);//x<y
	if (x!=y) {f[x]=y;l[y]=min(l[y],l[x]);r[y]=max(r[y],r[x]);size[y]+=size[x];}
}
struct node {
	int l,r; Vi e;
} tree[N<<2];
inline void build(int k, int l, int r) {
	tree[k].l=l; tree[k].r=r;
	if (l==r) return; int mid=(l+r)>>1;
	build(lc(k),l,mid); build(rc(k),mid+1,r);
}
inline void modify(int k, int p) {
	per(i,SZ(tree[k].e)-1,0) merge(n,tree[k].e[i]); tree[k].e.clear();
	if (tree[k].l==tree[k].r) return;
	if (p<=tree[lc(k)].r) modify(lc(k),p); else modify(rc(k),p);
}
inline void add(int k, int l, int r) { //n
	if (r<tree[k].l||l>tree[k].r) return;
	if (l<=tree[k].l&&r>=tree[k].r) {tree[k].e.push_back(n); return;}
	add(lc(k),l,r); add(rc(k),l,r);
}

int main() { //freopen("1.in","r",stdin);
	int q; read(q);
	rep(i,1,q) {
		int op,l,r;read(op);read(l);read(r);
		a[i].l=l;a[i].r=r;a[i].tp=op;
	}
	rep(i,1,q) if (a[i].tp==1) s[++tot]=a[i].l,s[++tot]=a[i].r;
	sort(s+1,s+tot+1); tot=unique(s+1,s+tot+1)-s-1;
	rep(i,1,q) if (a[i].tp==1) {
		a[i].l=lower_bound(s+1,s+tot+1,a[i].l)-s;
		a[i].r=lower_bound(s+1,s+tot+1,a[i].r)-s;
	}
	rep(i,1,q) f[i]=i,size[i]=1; build(1,1,tot);
	rep(i,1,q)
		if (a[i].tp==1) {
			l[++n]=a[i].l;r[n]=a[i].r; 
			modify(1,a[i].l); modify(1,a[i].r);
			if (l[n]+1<=r[n]-1) add(1,l[n]+1,r[n]-1); //WA1
		//	printf("[%d,%d] --> [%d,%d]\n",a[i].l,a[i].r,l[n],r[n]);
		}
		else {
			int fx=find(a[i].l),fy=find(a[i].r);
			if (fx==fy||(l[fx]>=l[fy]&&r[fx]<=r[fy]&&(l[fx]!=l[fy]||r[fx]!=r[fy]||size[fx]>1)))
				puts("YES"); else puts("NO");
		}
	return 0;
}