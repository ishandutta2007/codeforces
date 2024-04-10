#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
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
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666, M = 10700000, inf = 0x3f3f3f3f;
int q,len,p[N],tot;
struct line{
	int p,l,r,tp;//WA
}s[N];
int Abs(int x){return x>0?x:-x;}
bool cmp(line a, line b){return a.p!=b.p?a.p<b.p:a.tp<b.tp;}//WA
int lc[M],rc[M],sum[M],mx[M],lzy[M],cnt=1;
void pushdown(int k){
	if(lzy[k]){
		if(!lc[k])lc[k]=++cnt;{sum[lc[k]]+=lzy[k];mx[lc[k]]+=lzy[k];lzy[lc[k]]+=lzy[k];}//WA WA
		if(!rc[k])rc[k]=++cnt;{sum[rc[k]]+=lzy[k];mx[rc[k]]+=lzy[k];lzy[rc[k]]+=lzy[k];}
		lzy[k]=0;
	}
}
void modify(int &k, int L, int R, int l, int r, int v){
//	if(k==1)printf("%d %d %d %d\n",l,r,v,mx[k]);
	if(!k)k=++cnt;
	if(l<=L&&r>=R){sum[k]+=v;mx[k]+=v;lzy[k]+=v;return;}
	pushdown(k);int mid=(L+R)>>1;
	if(r<=mid)modify(lc[k],L,mid,l,r,v);
	else if(l>mid)modify(rc[k],mid+1,R,l,r,v);
	else modify(lc[k],L,mid,l,mid,v),modify(rc[k],mid+1,R,mid+1,r,v);
	sum[k]=sum[lc[k]]+sum[rc[k]];mx[k]=max(mx[lc[k]],mx[rc[k]]);
}
inline int query(int k, int l, int r){
	if(l==r)return l;pushdown(k);int mid=(l+r)>>1;
	if(mx[lc[k]]>=q-1)return query(lc[k],l,mid);return query(rc[k],mid+1,r);
}
int main() {
	read(q);
	rep(i,1,q){
		int x1,y1,x2,y2;read(x1);read(y1);read(x2);read(y2);
		len++;s[len].p=x1;s[len].l=y1;s[len].r=y2;s[len].tp=1;
		len++;s[len].p=x2+1;s[len].l=y1;s[len].r=y2;s[len].tp=-1;
		p[++tot]=y1;p[++tot]=y2;
	}
	sort(p+1,p+tot+1);tot=unique(p+1,p+tot+1)-p-1;
	sort(s+1,s+len+1,cmp);int rt=1;
	rep(i,1,len){
		modify(rt,1,tot,lower_bound(p+1,p+tot+1,s[i].l)-p,lower_bound(p+1,p+tot+1,s[i].r)-p,s[i].tp);
		if(mx[1]>=q-1){printf("%d %d\n",s[i].p,p[query(1,1,tot)]);return 0;}
	}
	return 0;
}