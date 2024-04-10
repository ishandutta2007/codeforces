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
const int N = 400000, M = 21000000; //M?????
int n,q,rt1,rt2,sz,mx=1e9;
int lc[M],rc[M],val[M];
inline int max(int a, int b) {return a>b?a:b;}
void modify(int &k, int L, int R, int l, int r, int v) {
	if (!k) k=++sz; 
	if (L==l&&R==r) {val[k]=max(val[k],v); return;}
	int mid=(L+R)>>1;
	if (r<=mid) modify(lc[k],L,mid,l,r,v);
	else if (l>mid) modify(rc[k],mid+1,R,l,r,v);
	else {
		modify(lc[k],L,mid,l,mid,v);
		modify(rc[k],mid+1,R,mid+1,r,v);
	}
}
int query(int k, int L, int R, int p) {
	if (!k) return 0;
	int mid=(L+R)>>1;
	if (p<=mid) return max(val[k],query(lc[k],L,mid,p));
	else return max(val[k],query(rc[k],mid+1,R,p));
}
int main() {
	read(n); read(q); rt1=++sz; rt2=++sz;
	while (q--) {
		char S[3]; int x,y; read(y); read(x); scanf("%s",S);
		if (S[0]=='U') {
			int p=query(rt2,1,mx,y);
			printf("%d\n",x-p);
			if (p+1<=x) modify(rt1,1,mx,p+1,x,y);
			modify(rt2,1,mx,y,y,x);
		}
		else {
			int p=query(rt1,1,mx,x);
			printf("%d\n",y-p);
			if (p+1<=y) modify(rt2,1,mx,p+1,y,x);
			modify(rt1,1,mx,x,x,y);
		}
	}
	return 0;
}