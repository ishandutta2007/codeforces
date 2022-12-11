#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
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
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m; ll X,Y;  // II I
int a[100010],b[100010];  // W P
ll f[100010],g[100010];
ll c[100010],d[100010];

ll W_to_P(int L,int R){  // [)
	ll z=(R-L)*X+ll(upper_bound(b+1,b+m+1,R)-upper_bound(b+1,b+m+1,L)-1)*Y;
	int l=upper_bound(a+1,a+n+1,L)-a,_l(l);
	int r=upper_bound(a+1,a+n+1,R)-a,_r(r-1);
	z+=f[l-1];
//	if (l==r) return z;
	while (l<r){
		int mid=l+r>>1;
		if (ll(R-a[mid])*X<=Y) r=mid;
		else l=mid+1;
	}
	z+=X*(R*1LL*(_r-l+1)-(c[_r]-c[l-1]));
	z+=Y*(l-_l);
	return z;
}

ll P_to_W(int L,int R){
	ll z=(R-L)*X+ll(upper_bound(a+1,a+n+1,R)-upper_bound(a+1,a+n+1,L)-1)*Y;
	int l=upper_bound(b+1,b+m+1,L)-b,_l(l);
	int r=upper_bound(b+1,b+m+1,R)-b,_r(r-1);
	z+=g[l-1];
//	if (l==r) return z;
	while (l<r){
		int mid=l+r>>1;
		if (ll(R-b[mid])*X<=Y) r=mid;
		else l=mid+1;
	}
	z+=X*(R*1LL*(_r-l+1)-(d[_r]-d[l-1]));
	z+=Y*(l-_l);
	return z;
}

ll _W_to_P(int x,int y){
	return W_to_P(a[x],b[y]);
}
ll _P_to_W(int x,int y){
	return P_to_W(b[x],a[y]);
}

struct Q{
	int n;
	struct S{
		int l,r,p;
	}s[100010]; int h,t;
	Q():h(1){}
	
	void ins(int q,int p,ll W(int,int)){
		while (h<=t&&W(p,s[t].l)<W(s[t].p,s[t].l)) --t;
		if (h>t){
			s[++t]=(S){q,n,p};
//			rep(i,h,t) debug("  s %d: %d %d %d\n",i,s[i].l,s[i].r,s[i].p);
//			debug("===================\n");
			return;
		}
		if (W(p,s[t].r)<W(s[t].p,s[t].r)){
			int l=s[t].l,r=s[t].r,mid;
			while (l<r){
				mid=l+r>>1;
				if (W(p,mid)<W(s[t].p,mid)) r=mid;
				else l=mid+1;
			}
			s[t].r=l-1; ++t,s[t]=(S){l,n,p};
		}
		else if (s[t].r!=n) ++t,s[t]=(S){s[t-1].r+1,n,p};
//		rep(i,h,t) debug("  s %d: %d %d %d\n",i,s[i].l,s[i].r,s[i].p);
//		debug("===================\n");
		return;
	}
	
	int pop(){
		if (h>t) return -1;
		int p=s[h].p;
		if (s[h].l<s[h].r) ++s[h].l;
		else ++h;
		return p;
	}
	
}A,B;

void solve(){
	int lim=read(); X=read(),Y=read();
	rep(i,1,lim){
		int t=read();
		char s[2]; scanf("%s",s);
		if (s[0]=='W') a[++n]=t;
		else b[++m]=t;
	}
	{
	int t=read();
	a[++n]=t,b[++m]=t;
	a[n+1]=b[m+1]=1e9;
	}
	rep(i,1,n) c[i]=c[i-1]+a[i];
	rep(i,1,m) d[i]=d[i-1]+b[i];
	int i=1,j=1; A.n=n,B.n=m;
	while (i<=n||j<=m){
		if (a[i]<b[j]){
			int p=A.pop();
			if (~p) f[i]=P_to_W(b[p],a[i]);
			else f[i]=1e18;
			f[i]=min(f[i],P_to_W(-1,a[i])-(a[i]+1)*X);
//			debug("f %d:\n  p %d cand %lld\n",i,p,~p?P_to_W(b[p],a[i]):-1);
//			debug("  p %d cand %lld\n",0,P_to_W(-1,a[i])-(a[i]+1)*X);
			if (i^n) B.ins(j,i,_W_to_P);
			++i;
		}
		else{
			int q=B.pop();
			if (~q) g[j]=W_to_P(a[q],b[j]);
			else g[j]=1e18;
			g[j]=min(g[j],W_to_P(-1,b[j])-(b[j]+1)*X);
//			debug("g %d:\n  q %d cand %lld\n",j,q,~q?W_to_P(a[q],b[j]):-1);
//			debug("  q %d cand %lld\n",0,W_to_P(-1,b[j])-(b[j]+1)*X);
			if (j^m) A.ins(i,j,_P_to_W);
			++j;
		}
	}
//	rep(i,1,n) debug("f %d = %lld\n",i,f[i]);
//	rep(i,1,m) debug("g %d = %lld\n",i,g[i]);
	printf("%lld\n",min(f[n],g[m]));
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}