#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 200050, inf = 0x3f3f3f3f;
int n,q,s[N];
int x[]={-1,2,0,1,7,-1};
char S[N];
struct node {
	int l,r,v[5][5];
} tree[N<<2];
inline void umin(int &a, int b) {a=a<b?a:b;}
inline node merge(node a, node b) {
	node u;
	rep(i,0,4) rep(j,i,4) {
		u.v[i][j]=inf;
		rep(k,i,j) umin(u.v[i][j],a.v[i][k]+b.v[k][j]);
	}
	return u;
}
inline void update(int k) {
	int l=tree[k].l,r=tree[k].r;
	tree[k]=merge(tree[lc(k)],tree[rc(k)]);
	tree[k].l=l; tree[k].r=r;
}
inline void build(int k, int l, int r) {
	tree[k].l=l; tree[k].r=r;
	if (l==r) {
		rep(i,0,4) rep(j,i,4)
			if (i==j) {
				tree[k].v[i][j]=(x[i+1]==s[l]);
				if (s[l]==6&&i>=3) tree[k].v[i][j]=1;
			}
			else if (i+1==j) tree[k].v[i][j]=(x[i+1]==s[l]?0:inf);
			else tree[k].v[i][j]=inf;
		return;
	}
	int mid=(l+r)>>1;
	build(lc(k),l,mid); build(rc(k),mid+1,r); update(k);
}
inline node query(int k, int l, int r) {
	if (l<=tree[k].l&&r>=tree[k].r) return tree[k];
	if (r<=tree[lc(k)].r) return query(lc(k),l,r);
	if (l>tree[lc(k)].r) return query(rc(k),l,r);
	return merge(query(lc(k),l,r),query(rc(k),l,r));
}
int main() {
	read(n); read(q); scanf("%s",S+1); rep(i,1,n) s[i]=S[i]-'0';
	build(1,1,n);
	while (q--) {
		int l,r; read(l); read(r); node u=query(1,l,r);
		printf("%d\n",u.v[0][4]<inf?u.v[0][4]:-1);
	}
	return 0;
}