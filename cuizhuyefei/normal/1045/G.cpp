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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 344444,M=18000000,mx=1e9;
int n,k,a[N],len,rt[N],sz,lc[M],rc[M],val[M];
struct ele{
	int x,r,q;
}s[N];
bool cmp(ele a, ele b){return a.r>b.r;}
inline int query(int k, int L, int R, int l, int r){
	if(r<L||l>R||!k)return 0;if(l<=L&&r>=R)return val[k];int mid=(L+R)>>1;
	return query(lc[k],L,mid,l,r)+query(rc[k],mid+1,R,l,r);
}
inline void ins(int &k, int L, int R, int p){
	if(!k)k=++sz;val[k]++;if(L==R)return;int mid=(L+R)>>1;
	if(p<=mid)ins(lc[k],L,mid,p);else ins(rc[k],mid+1,R,p);
}
int main() {
	read(n);read(k);rep(i,1,n)read(s[i].x),read(s[i].r),read(s[i].q);
	int len=0;sort(s+1,s+n+1,cmp);rep(i,1,n)a[++len]=s[i].q;
	sort(a+1,a+len+1);len=unique(a+1,a+len+1)-a-1;ll res=0;
	rep(i,1,n){
		for(int t=lower_bound(a+1,a+len+1,s[i].q-k)-a;t<=len&&a[t]<=s[i].q+k;t++)
			res+=query(rt[t],0,mx,s[i].x-s[i].r,s[i].x+s[i].r);
		ins(rt[lower_bound(a+1,a+len+1,s[i].q)-a],0,mx,s[i].x);
	}
	cout<<res;return 0;
}