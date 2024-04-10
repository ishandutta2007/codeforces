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
typedef pair<int,int> P;
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

int n,m;
P c[200010],d[200010];
int a[200010],b[200010];
ll e[200010];
int L,R;

void add(int l,int r,int w){
	//printf("  add %d %d  %d\n",l,r,w);
	e[l]+=w,e[r+1]-=w;
}

void add1(int l,int r,int o,int w){
	//printf("add1 %d %d %d %d\n",l,r,o,w);
	if (l>r) return;
	if (r>=o) add(max(o,l)-o+1,r-o+1,w);
	if (l<o) add(l+n-o+1,min(r,o-1)+n-o+1,w);
}

void add2(int l,int r,int o,int w){
	//printf("add2 %d %d %d %d\n",l,r,o,w);
	if (l>r) return;
	if (l<=o) add(o-min(o,r)+1,o-l+1,w);
	if (r>o) add(n-r+1+o,n-max(o+1,l)+1+o,w);
}

void work1(int o){
	if (a[o]+R>m){
		int l=lower_bound(b+1,b+n+1,a[o]-L)-b;
		int r=lower_bound(b+1,b+n+1,a[o])-b-1;
		add1(l,r,o,a[o]);
		add1(1,l-1,o,-a[o]);
		add1(r+1,n,o,-a[o]);
	}
	else{
		int l=lower_bound(b+1,b+n+1,a[o])-b;
		int r=upper_bound(b+1,b+n+1,a[o]+R)-b-1;
		add1(l,r,o,-a[o]);
		add1(1,l-1,o,a[o]);
		add1(r+1,n,o,a[o]+m);
	}
}

void work2(int o){
	if (b[o]+L>m){
		int l=lower_bound(a+1,a+n+1,b[o]-R)-a;
		int r=upper_bound(a+1,a+n+1,b[o])-a-1;
		add2(l,r,o,b[o]);
		add2(1,l-1,o,-b[o]);
		add2(r+1,n,o,-b[o]);
	}
	else{
		int l=upper_bound(a+1,a+n+1,b[o])-a;
		int r=upper_bound(a+1,a+n+1,b[o]+L)-a-1;
		add2(l,r,o,-b[o]);
		add2(1,l-1,o,b[o]);
		add2(r+1,n,o,b[o]+m);
	}
}

void solve(){
	m=read(),n=read();
	L=m>>1,R=m-1>>1;
	//printf("test L %d R %d\n",L,R);
	rep(i,1,n) d[i]=P(read(),i);
	rep(i,1,n) c[i]=P(read(),i);
	sort(c+1,c+n+1);
	sort(d+1,d+n+1);
	rep(i,1,n) a[i]=c[i].fi,b[i]=d[i].fi;
	rep(i,1,n) work1(i),work2(i);
	ll mn=1e18; int o=-1;
	rep(i,1,n){
		e[i]+=e[i-1];
		//printf("ans %d = %lld\n",i,e[i]);
		if (e[i]<mn) mn=e[i],o=i;
	}
	printf("%lld\n",mn);
	//printf("test o %d\n",o);
	static int q[200010];
	rep(i,1,n){
		q[d[(i+o-2)%n+1].se]=c[i].se;
		//printf("test link %d -> %d\n",c[i].se,d[(i+o-2)%n+1].se);
		//printf("  test %d -> %d\n",i,(i+o-2)%n+1);
	}
	rep(i,1,n) printf("%d ",q[i]);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}