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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n; P w[200010];

int fat[400010],siz[400010];
int find(int x){return fat[x]?fat[x]=find(fat[x]):x;}
int merge(int x,int y){
	if (!x||!y) return x+y;
	x=find(x),y=find(y);
	if (x==y) return x;
	fat[y]=x; return x;
}

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

int f[1<<20],g[1<<20];
bool tg[1<<20];

void query(int x,int l,int r,int ql,int qr,int a,int b){
	if (ql<=l&&r<=qr){
		if (tg[x]||l==r){
			merge(a,f[x]);
			merge(b,g[x]);
			tg[x]=1;
			return;
		}
		tg[x]=1;
		query(ls,l,mid,ql,qr,a,b);
		query(rs,mid+1,r,ql,qr,a,b);
		f[x]=merge(f[ls],f[rs]);
		g[x]=merge(g[ls],g[rs]);
		return;
	}
	if (ql<=mid) query(ls,l,mid,ql,qr,a,b);
	if (mid<qr) query(rs,mid+1,r,ql,qr,a,b);
}

void modify(int x,int l,int r,int p,int a,int b){
	tg[x]=0;
	if (l==r) return f[x]=a,g[x]=b,void();
	if (p<=mid) modify(ls,l,mid,p,a,b);
	else modify(rs,mid+1,r,p,a,b);
}

#undef mid
#undef ls
#undef rs

void solve(){
	n=read();
	rep(i,1,n){
		int u=read(),v=read();
		w[i]=P(u,v);
	}
	sort(w+1,w+n+1,[&](const P &x,const P &y){return min(x.fi,x.se)<min(y.fi,y.se);});
	{
	int S=2e9;
	rep(i,1,n){
		const P &x=w[i];
		if (S<min(x.fi,x.se)) return puts("-1"),void();
		S=min(S,max(x.fi,x.se));
	}
	}
	rep(i,1,n){
		const P &x=w[i];
		if (x.fi<x.se){
			query(1,1,n<<1,x.fi,x.se,i+n,i);
			modify(1,1,n<<1,x.se,i,i+n);
		}
		else{
			query(1,1,n<<1,x.se,x.fi,i,i+n);
			modify(1,1,n<<1,x.fi,i+n,i);
		}
	}
	rep(i,1,n) if (find(i)==find(i+n)) return puts("-1"),void();
	rep(i,1,n) ++siz[find(i+n)];
	int z=0;
	rep(i,1,n) if (find(i)==i) z+=min(siz[find(i)],siz[find(i+n)]);
	rep(i,n+1,n<<1) if (find(i)==i) z+=min(siz[find(i)],siz[find(i-n)]);
	printf("%d\n",z>>1);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}