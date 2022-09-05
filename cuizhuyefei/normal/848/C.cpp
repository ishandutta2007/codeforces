#include<cstdio>
#include<set>
#define MID ((L+R)>>1)
#define rep(i,a,b) for (int i=a; i<=b; i++)
using namespace std;
const int N = 100004, M = 12000200;
typedef long long ll;
int n,m,a[N];
set<int> Set[N];
set<int> ::iterator it;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
struct Seg {
	int size,lc[M],rc[M];
	ll sum[M];
	inline void init() {size=n;}
	inline void add(int k, int p, int v, int L, int R) {
		sum[k]+=v;
		if (L==R) return;
		if (p<=MID) {if (!lc[k]) lc[k]=++size; add(lc[k],p,v,L,MID);}
		else {if (!rc[k]) rc[k]=++size; add(rc[k],p,v,MID+1,R);}
	}
	inline ll query(int k, int l, int r, int L, int R) {
		if (!k) return 0;
		if (l==L && r==R) return sum[k];
		if (r<=MID) return query(lc[k],l,r,L,MID);
		if (l>=MID+1) return query(rc[k],l,r,MID+1,R);
		return query(lc[k],l,MID,L,MID)+query(rc[k],MID+1,r,MID+1,R);
	}
} tree;
struct B {
	inline void add(int x, int y, int v) {
		if (x<1||x>n||y<1||y>n) return;
		while (x<=n) {tree.add(x,y,v,1,n); x+=x&-x;}
	}
	inline ll query(int x, int l, int r) {
		ll res=0;
		while (x) {res+=tree.query(x,l,r,1,n); x-=x&-x;}
		return res;
	}
} BIT;
inline void jiaru(int p, int v) {
	Set[v].insert(p); it=Set[v].find(p);
	int l,r; it++; r=*it; it--; it--; l=*it;
	BIT.add(p,l,p-l); BIT.add(r,p,r-p); BIT.add(r,l,l-r);
//	printf("%d %d %d %d\n",p,v,l,r);
}
inline void shanchu(int p, int v) {
	Set[v].erase(p); it=Set[v].lower_bound(p);
	int l,r; r=*it; it--; l=*it;
	BIT.add(p,l,l-p); BIT.add(r,p,p-r); BIT.add(r,l,r-l);
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(m);
	rep(i,1,n) read(a[i]);
	rep(i,1,N-4) {Set[i].insert(0); Set[i].insert(n+1);}
	tree.init(); rep(i,1,n) jiaru(i,a[i]);
//	printf("%d %d\n",BIT.query(5,4,5),BIT.query(5,4,5)-BIT.query(3,4,5));
//	jiaru(5,a[5]);
//	printf("%d %d\n",BIT.query(5,4,5),BIT.query(5,4,5)-BIT.query(3,4,5));
	while (m--) {
		int op,l,r; read(op); read(l); read(r);
		if (op==1) {shanchu(l,a[l]); a[l]=r; jiaru(l,a[l]);}
		else printf("%lld\n",BIT.query(r,l,r)-BIT.query(l-1,l,r));
	}
	return 0;
}