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
const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n;
int w[100010],v[100010],p[100010],q[100010];

struct C{
	int tx,ty;
	int o,x;  // 3 merge 1/2 set
}c[200010]; int m;
bool operator<(const C &x,const C &y){
	const ll a=1LL*x.tx*y.ty,b=1LL*y.tx*x.ty;
	return a<b;
}

int gett(C x){
	return 1LL*x.tx*qpow(x.ty,mod-2)%mod;
}


#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

struct M{
	int s[2][2];
}g[1<<18];
M f[100010];

M operator*(const M &x,const M &y){
	M z;
	rep(i,0,1) rep(j,0,1){
		int &t=z.s[i][j]; t=0;
		rep(k,0,1) add(t,1LL*x.s[i][k]*y.s[k][j]%mod);
	}
	return z;
}

void build(int x,int l,int r){
	if (l==r) return g[x]=f[l]=(M){{{q[l],p[l]},{q[l],p[l]}}},void();
	build(ls,l,mid); build(rs,mid+1,r);
	g[x]=g[ls]*g[rs];
}

void modify(int x,int l,int r,int p,const M &w){
	if (l==r) return g[x]=w,void();
	if (p<=mid) modify(ls,l,mid,p,w);
	else modify(rs,mid+1,r,p,w);
	g[x]=g[ls]*g[rs];
}

#undef mid
#undef ls
#undef rs



void solve(){
	n=read(); const int i100=qpow(100,mod-2);
	//if (n==1) return puts("0"),void();
	rep(i,1,n){
		w[i]=read(),v[i]=read();
		p[i]=1LL*read()*i100%mod; q[i]=upd(1-p[i]);
		if (i==1) continue;
		c[++m]=(C){w[i]-w[i-1],v[i]+v[i-1],3,i-1};
		if (v[i]<v[i-1]) c[++m]=(C){w[i]-w[i-1],v[i-1]-v[i],1,i-1};
		else if (v[i]>v[i-1]) c[++m]=(C){w[i]-w[i-1],v[i]-v[i-1],2,i-1};
	}
	stable_sort(c+1,c+m+1);
	build(1,1,n);
	int z=0;
	add(z,gett(c[1]));
	
	rep(i,1,m){
		const C &o=c[i];
		if (o.o==3){
			int c=o.x+1;
			f[c].s[1][0]=0;
			modify(1,1,n,c,f[c]);
		}
		else if (o.o==1){
			int c=o.x+1;
			f[c].s[1][1]=0;
			modify(1,1,n,c,f[c]);
		}
		else{
			int c=o.x+1;
			f[c].s[0][0]=0;
			modify(1,1,n,c,f[c]);
		}
		const int pr=(g[1].s[0][1]+g[1].s[0][0])%mod;
		if (i==m) iadd(z,1LL*gett(o)*pr%mod);
		else add(z,1LL*upd(gett(c[i+1])-gett(o))*pr%mod);
	}
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}