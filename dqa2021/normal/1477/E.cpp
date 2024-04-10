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
const int U=1e6;

int n,m,q,a[200010],b[200010];
ll S,T;
multiset<int> A,B;

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

struct C{
	int tot; ll sum;
}c[1<<21];

C operator+(const C &x,const C &y){return (C){x.tot+y.tot,x.sum+y.sum};}

void pushup(const int &x){
	c[x]=c[ls]+c[rs];
}
void update(const int &x,const int &l,const int &r,const int &p,const int &tot,const ll &sum){
	if (l==r) return c[x]=c[x]+(C){tot,sum},void();
	if (p<=mid) update(ls,l,mid,p,tot,sum);
	else update(rs,mid+1,r,p,tot,sum);
	pushup(x);
}
C query(const int &x,const int &l,const int &r,const int &ql,const int &qr){
	if (ql<=l&&r<=qr) return c[x];
	C res=(C){0,0};
	if (ql<=mid) res=query(ls,l,mid,ql,qr);
	if (mid<qr) res=res+query(rs,mid+1,r,ql,qr);
	return res;
}
int find(const int &x,const int &l,const int &r,const ll &S){
	if (l==r) return l;
	if (S+c[rs].tot<0) return find(ls,l,mid,S+c[rs].tot);
	return find(rs,mid+1,r,S);
}
int getpre(const int &x,const int &l,const int &r,const int &p){
	if (p>=r){
		if (!c[x].tot) return -1;
		if (l==r) return l;
		if (c[rs].tot) return getpre(rs,mid+1,r,p);
		return getpre(ls,l,mid,p);
	}
	if (p<=mid) return getpre(ls,l,mid,p);
	int t=getpre(rs,mid+1,r,p);
	if (!~t) t=getpre(ls,l,mid,p);
	return t;
}

#undef ls
#undef rs
#undef mid

ll getvalA(int f,int k){
	int mn=min(*A.begin(),*B.begin());
	ll A=1LL*n*(-f+k)+S+max(0,f-k-mn)*1LL*(n-1);
	C v=query(1,0,U,max(0,f-k),U);
	ll B=v.sum+1LL*v.tot*(-f+k);
	//printf("getvalA %d %d: %lld - %lld = %lld\n",f,k,A,B,A-B);
	return A-B;
}
ll getvalB(int f,int k){
	int mn=min(*A.begin(),*B.begin());
	ll A=1LL*n*(-f+k)+S+max(0,f-k-mn)*1LL*n;
	C v=query(1,0,U,max(0,f-k),U);
	ll B=v.sum+1LL*v.tot*(-f+k);
	//printf("getvalB %d %d: %lld - %lld = %lld\n",f,k,A,B,A-B);
	return A-B;
}

ll checkA(int k){
	int mn=min(*A.begin(),*B.begin());
	ll res=getvalA(*A.begin(),k);
	auto it=A.upper_bound(mn+k);
	if (it!=A.begin()) res=max(res,getvalA(*--it,k));
	if (mn+k>U) return res;
	int t=min(max(find(1,0,U,-1)+k,mn+k),U);
	it=A.upper_bound(t);
	if (it!=A.end()) res=max(res,getvalA(*it,k));
	if (it!=A.begin()) res=max(res,getvalA(*--it,k));
	return res;
}

ll checkB(int k){
	int mn=min(*A.begin(),*B.begin());
	ll res=getvalB(*B.begin(),k);
	auto it=B.upper_bound(mn+k);
	if (it!=B.begin()) res=max(res,getvalB(*--it,k));
	if (mn+k>U) return res;
	int t=min(max(find(1,0,U,0)+k,mn+k),U);
	it=B.upper_bound(t);
	if (it!=B.end()) res=max(res,getvalB(*it,k));
	if (it!=B.begin()) res=max(res,getvalB(*--it,k));
	return res;
}

void solve(){
	n=read(),m=read(),q=read();
	rep(i,1,n) a[i]=read(),S+=a[i];
	rep(i,1,m) b[i]=read(),T+=b[i];
	multiset<int>(a+1,a+n+1).swap(A);
	multiset<int>(b+1,b+m+1).swap(B);
	rep(i,1,m) update(1,0,U,b[i],1,b[i]);
	while (q--){
		int o=read(),x=read(),v;
		if (o^3) v=read();
		if (o==1){
			A.erase(A.find(a[x])),S-=a[x];
			a[x]=v;
			A.insert(a[x]),S+=a[x];
		}
		else if (o==2){
			B.erase(B.find(b[x])),T-=b[x];
			update(1,0,U,b[x],-1,-b[x]);
			b[x]=v;
			B.insert(b[x]),T+=b[x];
			update(1,0,U,b[x],1,b[x]);
		}
		else{
			//rep(i,1,n) printf("getvalA %d %d = %lld\n",a[i],x,getvalA(a[i],x));
			//rep(i,1,m) printf("getvalB %d %d = %lld\n",b[i],x,getvalB(b[i],x));
			printf("%lld\n",max(checkA(x),checkB(x)));
		}
	}
}
int main()
{
	for (int T=1;T--;) solve();
}