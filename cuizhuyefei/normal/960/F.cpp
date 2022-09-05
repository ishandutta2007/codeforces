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
const int N = 400020, M = 7000000;
int n,m;
int rt[N],lc[M],rc[M],val[M],num;
int query(int k, int l, int r, int L, int R) {
	if (!k) return 0;
	if (l==L&&r==R) return val[k];
	int mid=(L+R)>>1;
	if (r<=mid) return query(lc[k],l,r,L,mid);
	if (l>=mid+1) return query(rc[k],l,r,mid+1,R);
	return max(query(lc[k],l,mid,L,mid),query(rc[k],mid+1,r,mid+1,R));
}
void modify(int &k, int p, int v, int L, int R) {
	if (!k) k=++num; val[k]=max(val[k],v); if (L==R) return;
	int mid=(L+R)>>1;
	if (p<=mid) modify(lc[k],p,v,L,mid); else modify(rc[k],p,v,mid+1,R);
}
int main() {
	read(n); read(m); int mx=100000;
	rep(i,1,n) rt[i]=++num; int res=0;
	rep(i,1,m) {
		int u,v,w;read(u);read(v);read(w);
		int tmp=1+(0<=w-1?query(rt[u],0,w-1,0,mx):0);
		modify(rt[v],w,tmp,0,mx); res=max(res,tmp);
	}
	printf("%d",res);
	return 0;
}