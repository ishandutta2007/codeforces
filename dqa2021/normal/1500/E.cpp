#pragma GCC optimize(2,3,"Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
inline uint getrand(){
	static uint sd=443515789U;
	return sd^=sd>>13,sd^=sd<<24,sd^=sd>>27,sd^=sd<<14;
}


int n,q;

ll A[200010],B[200010];
ll C[400010]; int m;

bool vis[400010];

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

int s[1<<20];
ll f[1<<20],g[1<<20];

inline void pushup(int x){
	s[x]=s[ls]+s[rs];
	f[x]=f[ls]+f[rs];
	g[x]=g[ls]+g[rs]+f[rs]*s[ls];
}

void build(int x,int l,int r){
	if (l==r) return s[x]=vis[l],f[x]=g[x]=C[l]*s[x],void();
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(x);
}

void update(int x,int l,int r,int p,int v){
	if (l==r) return s[x]+=v,f[x]=g[x]=C[l]*s[x],void();
	if (p<=mid) update(ls,l,mid,p,v);
	else update(rs,mid+1,r,p,v);
	pushup(x);
}

ll getkth(int x,int l,int r,int k){
	if (l==r) return C[l];
	if (k<=s[ls]) return getkth(ls,l,mid,k);
	return getkth(rs,mid+1,r,k-s[ls]);
}

/*ll query(int x,int l,int r,int ql,int qr,int k,int b,int rk=0){
	if (ql<=l&&r<=qr) return k*f[x]+b*(g[x]+rk*f[x]);
	ll z=0;
	if (ql<=mid) z=query(ls,l,mid,ql,qr,k,b,rk);
	if (mid<qr) z+=query(rs,mid+1,r,ql,qr,k,b,rk+s[ls]);
	return z;
}*/

ll getpre(int x,int l,int r,int p,int k,int b,int rk=0){
	if (rk+s[x]<=p) return k*f[x]+b*(g[x]+rk*f[x]);
	if (rk+s[ls]>=p) return getpre(ls,l,mid,p,k,b,rk);
	return getpre(ls,l,mid,p,k,b,rk)+getpre(rs,mid+1,r,p,k,b,rk+s[ls]);
}

ll getsuf(int x,int l,int r,int p,int k,int b,int rk=0){
	if (rk+1>=p) return k*f[x]+b*(g[x]+rk*f[x]);
	if (rk+s[ls]<p) return getsuf(rs,mid+1,r,p,k,b,rk+s[ls]);
	return getsuf(ls,l,mid,p,k,b,rk)+getsuf(rs,mid+1,r,p,k,b,rk+s[ls]);
}

#undef ls
#undef rs
#undef mid

ll getpre(int p){
	return p?getpre(1,1,m,p,1,0):0;
}

ll getsuf(int p){
	return p<=s[1]?getsuf(1,1,m,p,1,0):0;
}

ll getpre2(int p,int k,int b){
	return p?getpre(1,1,m,p,k,b):0;
}

ll getsuf2(int p,int k,int b){
	return p<=s[1]?getsuf(1,1,m,p,k,b):0;
}

ll getkth(int k){
	return getkth(1,1,m,k);
}

ll getans(){
	const int lim=s[1];
	if (lim<=1) return 0;
	if (lim==2) return getkth(2)-getkth(1);
	int l=1,r=lim-2,mid,L=-1,R=-1;
	while (l<=r){
		mid=l+r>>1;
		if (getpre(mid+1)<=getsuf(lim-mid+1)) L=mid,r=mid-1;
		else{
			if (getkth(mid+2)-getkth(lim-mid)<=0) l=mid+1;
			else r=mid-1;
		}
	}
	ll z=getsuf2(2,-1,1)-getpre2(lim-1,lim,-1);
	if (!~L) return z;
	l=L,r=lim-2;
	while (l<=r){
		mid=l+r>>1;
		if (getpre(mid+1)<=getsuf(lim-mid+1)) R=mid+1,l=mid+1;
		else{
			if (getkth(mid+2)-getkth(lim-mid)<=0) l=mid+1;
			else r=mid-1;
		}
	}
	assert(~R);
	z+=getpre(L-1)*(R-L+1);
	z+=getpre2(R,R+1,-1)-getpre2(L-1,R+1,-1);
	z-=getsuf(lim-L+2)*(R-L+1);
	z-=getsuf2(lim-R+1,R-lim,1)-getsuf2(lim-L+2,R-lim,1);
	z+=getsuf(lim-R+1)-getpre(L);
	return z;
}

void solve(){
	n=read(),q=read();
	rep(i,1,n) C[++m]=A[i]=read();
	rep(i,1,q) if (read()&1) B[i]=C[++m]=read();
		else B[i]=-read();
	sort(C+1,C+m+1);
	m=unique(C+1,C+m+1)-C-1;
	
	per(i,1,q){
		int f=1;
		if (B[i]<0) B[i]=-B[i],f=-f;
		B[i]=lower_bound(C+1,C+m+1,B[i])-C;
		//printf("q %d = %lld\n",i,B[i]);
		B[i]*=f;
	}
	per(i,1,n){
		A[i]=lower_bound(C+1,C+m+1,A[i])-C;
		//printf("a %d = %lld\n",i,A[i]);
		vis[A[i]]=1;
	}
	build(1,1,m);
	printf("%lld  ",getans());
	rep(i,1,q){
		if (B[i]<0) update(1,1,m,-B[i],-1);
		else update(1,1,m,B[i],1);
		printf("%lld ",getans());
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}