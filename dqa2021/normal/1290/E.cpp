#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])
const int INF=1e9;

int n,p[150010],q[150010];
ll ans[150010];

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

int fi[1<<19],fitot[1<<19],se[1<<19],siz[1<<19],tag[1<<19];
ll sum[1<<19];

inline void pushdown(int x){
	const int &w=tag[x];
	fi[ls]+=w; se[ls]+=w;
	tag[ls]+=w; sum[ls]+=1LL*w*siz[ls];
	fi[rs]+=w; se[rs]+=w;
	tag[rs]+=w; sum[rs]+=1LL*w*siz[rs];
	tag[x]=0;
	if (fi[x]<fi[ls]){
		const int d=fi[ls]-fi[x];
		fi[ls]-=d; sum[ls]-=1LL*d*fitot[ls];
	}
	if (fi[x]<fi[rs]){
		const int d=fi[rs]-fi[x];
		fi[rs]-=d; sum[rs]-=1LL*d*fitot[rs];
	}
}

inline void pushup(int x){
	fi[x]=max(fi[ls],fi[rs]);
	fitot[x]=0;
	se[x]=-INF;
	if (fi[ls]!=fi[x]) se[x]=max(se[x],fi[ls]);
	else fitot[x]+=fitot[ls];
	if (fi[rs]!=fi[x]) se[x]=max(se[x],fi[rs]);
	else fitot[x]+=fitot[rs];
	if (se[ls]!=fi[x]) se[x]=max(se[x],se[ls]);
	if (se[rs]!=fi[x]) se[x]=max(se[x],se[rs]);
	siz[x]=siz[ls]+siz[rs];
	sum[x]=sum[ls]+sum[rs];
}

void update(int x,int l,int r,int ql,int qr){
	if (!siz[x]) return;
	if (ql<=l&&r<=qr){
		++fi[x]; ++se[x]; ++tag[x];
		sum[x]+=siz[x];
		return;
	}
	pushdown(x);
	if (ql<=mid) update(ls,l,mid,ql,qr);
	if (mid<qr) update(rs,mid+1,r,ql,qr);
	pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
	if (!siz[x]) return 0;
	if (ql<=l&&r<=qr) return siz[x];
	pushdown(x); int z=0;
	if (ql<=mid) z=query(ls,l,mid,ql,qr);
	if (mid<qr) z+=query(rs,mid+1,r,ql,qr);
	return z;
}

void modify(int x,int l,int r,int ql,int qr,const int &w){
	if (!siz[x]) return;
	if (w>=fi[x]) return;
	if (ql<=l&&r<=qr){
		if (w>se[x]){
			const int d=fi[x]-w;
			fi[x]-=d; sum[x]-=1LL*fitot[x]*d;
			return;
		}
	}
	pushdown(x);
	if (ql<=mid) modify(ls,l,mid,ql,qr,w);
	if (mid<qr) modify(rs,mid+1,r,ql,qr,w);
	pushup(x);
}

void ins(int x,int l,int r,int p,const int &w){
	if (l==r) return sum[x]=fi[x]=w,fitot[x]=siz[x]=1,void();
	pushdown(x);
	if (p<=mid) ins(ls,l,mid,p,w);
	else ins(rs,mid+1,r,p,w);
	pushup(x);
}

#undef mid
#undef ls
#undef rs

void work(){
	memset(fi,-0x3f,sizeof fi);
	memset(fitot,0,sizeof fitot);
	memset(se,-0x3f,sizeof se);
	memset(siz,0,sizeof siz);
	memset(tag,0,sizeof tag);
	memset(sum,0,sizeof sum);
	rep(i,1,n) q[p[i]]=i;
	rep(i,1,n){
		const int &o=q[i];
		if (o<n) update(1,1,n,o+1,n);  //add
		const int s=query(1,1,n,1,o)+1;
		modify(1,1,n,1,o,s);
		ins(1,1,n,o,i+1);
		ans[i]+=sum[1];
	}
}

void solve(){
	n=read();
	rep(i,1,n) p[i]=read();
	work();
	reverse(p+1,p+n+1);
	work();
	rep(i,1,n) printf("%lld\n",ans[i]-1LL*(i+2)*i);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}