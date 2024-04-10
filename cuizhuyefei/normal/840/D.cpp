#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
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
const int N = 305000, M = 20000000;
int n,q,a[N],rt[N];
int lc[M],rc[M],cnt[M],sz;
inline void add(int &k, int K, int l, int r, int p) {
	if (!k) k=++sz; cnt[k]=cnt[K]+1; if (l==r) return;
	int mid=(l+r)>>1;
	if (p<=mid) {add(lc[k],lc[K],l,mid,p); rc[k]=rc[K];}
	else {add(rc[k],rc[K],mid+1,r,p); lc[k]=lc[K];}
}
inline void query(int k1, int k2, int l, int r, int k, int &ans) { //>=k
	if (l==r) {ans=l; return;} int mid=(l+r)>>1;
	if (cnt[rc[k1]]-cnt[rc[k2]]>=k) query(rc[k1],rc[k2],mid+1,r,k,ans);
	if (cnt[lc[k1]]-cnt[lc[k2]]>=k) query(lc[k1],lc[k2],l,mid,k,ans);
}
int main() {
	read(n); read(q); rep(i,1,n) read(a[i]);
	rep(i,1,n) add(rt[i],rt[i-1],1,n,a[i]);
	while (q--) {
		int l,r,k; read(l); read(r); read(k); k=(r-l+1)/k+1;
		int ans=-1; query(rt[r],rt[l-1],1,n,k,ans);
		printf("%d\n",ans);
	}
	return 0;
}