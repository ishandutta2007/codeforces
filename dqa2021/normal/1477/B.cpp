#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
typedef long long ll;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

int n,q;
char s[200010],t[200010];
int L[200010],R[200010];

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

struct C{
	int tg,tot;
}c[1<<19];
void pushdown(int x,int l,int r){
	if (!~c[x].tg) return;
	int t=c[x].tg;
	c[ls].tg=t,c[rs].tg=t;
	c[ls].tot=t*(mid-l+1);
	c[rs].tot=t*(r-mid);
	c[x].tg=-1;
}
void pushup(int x){
	c[x].tot=c[ls].tot+c[rs].tot;
}
void build(int x,int l,int r){
	c[x].tg=-1;
	if (l==r) c[x].tot=t[l]-'0';
	else build(ls,l,mid),build(rs,mid+1,r),pushup(x);
}
int query(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return c[x].tot;
	pushdown(x,l,r);
	int res=0;
	if (ql<=mid) res=query(ls,l,mid,ql,qr);
	if (mid<qr) res+=query(rs,mid+1,r,ql,qr);
	return res;
}
void modify(int x,int l,int r,int ql,int qr,int t){
	if (ql<=l&&r<=qr) return c[x].tg=t,c[x].tot=t*(r-l+1),void();
	pushdown(x,l,r);
	if (ql<=mid) modify(ls,l,mid,ql,qr,t);
	if (mid<qr) modify(rs,mid+1,r,ql,qr,t);
	pushup(x);
}

bool check(int x,int l,int r){
	if (l==r) return s[l]-'0'==c[x].tot;
	pushdown(x,l,r);
	return check(ls,l,mid)&&check(rs,mid+1,r);
}

#undef ls
#undef rs
#undef mid

void solve(){
	n=read(),q=read();
	scanf("%s%s",s+1,t+1);
	rep(i,1,q) L[i]=read(),R[i]=read();
	build(1,1,n);
	per(i,1,q){
		int t=query(1,1,n,L[i],R[i]);
		if (t*2<R[i]-L[i]+1) modify(1,1,n,L[i],R[i],0);
		else if (t*2==R[i]-L[i]+1) return puts("NO"),void();
		else modify(1,1,n,L[i],R[i],1);
	}
	puts(check(1,1,n)?"YES":"NO");
}
int main()
{
	for (int T=read();T--;) solve();
}