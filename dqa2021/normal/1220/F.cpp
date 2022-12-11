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
const int INF=1e9;

int n,a[400010]; P w[400010];
int stk[400010],top;

int L[400010],R[400010],dep[400010];
int ls[400010],rs[400010];

void dfs0(int x,int l,int r,int d){
	L[x]=l,R[x]=r,dep[x]=d;
	if (ls[x]) dfs0(ls[x],l,x-1,d+1);
	if (rs[x]) dfs0(rs[x],x+1,r,d+1);
}

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

int tag[1<<20],mx[1<<20];

void pushup(int x){
	mx[x]=max(mx[ls],mx[rs])+tag[x];
}

void build(int x,int l,int r){
	if (l==r) return mx[x]=dep[l],void();
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(x);
}

void update(int x,int l,int r,int ql,int qr,int v){
	if (ql<=l&&r<=qr){
		tag[x]+=v; mx[x]+=v;
		return;
	}
	if (ql<=mid) update(ls,l,mid,ql,qr,v);
	if (mid<qr) update(rs,mid+1,r,ql,qr,v);
	pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return mx[x];
	int z=0;
	if (ql<=mid) z=max(z,query(ls,l,mid,ql,qr));
	if (mid<qr) z=max(z,query(rs,mid+1,r,ql,qr));
	return z+tag[x];
}

#undef mid
#undef ls
#undef rs


void ins(int x){
	update(1,1,n<<1,x,x,INF+dep[x]);
	update(1,1,n<<1,L[x],R[x],1);
}

void del(int x){
	update(1,1,n<<1,x,x,-INF-dep[x]);
	update(1,1,n<<1,L[x],R[x],-1);
}

void solve(){
	n=read();
	rep(i,1,n) a[i]=a[i+n]=read();
	rep(i,1,n+n) w[i]=P(a[i],i);
	rep(i,1,n+n){
		while (top&&w[stk[top]]>w[i]){
			if (top>1&&w[stk[top-1]]>w[i]) rs[stk[top-1]]=stk[top];
			else ls[i]=stk[top];
			--top;
		}
		stk[++top]=i;
		//puts("test");
	}
	while (top>1) rs[stk[top-1]]=stk[top],--top;
	//puts("test");
	int rt=stk[1];
	dfs0(rt,1,n<<1,1);
	build(1,1,n<<1);
	rep(i,n+1,n<<1) del(i);
	int z=query(1,1,n<<1,1,n),o=0;
	rep(i,1,n-1){
		del(i); ins(i+n);
		int b=query(1,1,n<<1,i+1,n+i);
		if (b<z) z=b,o=i;
	}
	printf("%d %d\n",z,o);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}