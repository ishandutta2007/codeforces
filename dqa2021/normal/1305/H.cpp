#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
typedef vector<ll> V;
#define NO puts("-1 -1"),exit(0)

int n,m,q; ll T;
int L[100010],R[100010];
int b[100010];
ll lim[100010];

struct Pt{
	int x; ll y;
}pt[100010];
Pt operator+(const Pt &x,const Pt &y){return (Pt){x.x+y.x,x.y+y.y};}
Pt operator-(const Pt &x,const Pt &y){return (Pt){x.x-y.x,x.y-y.y};}
ll cross(const Pt &x,const Pt &y){return x.x*y.y-x.y*y.x;}
bool operator<(const Pt &x,const Pt &y){
	if (x.x^y.x) return x.x<y.x;
	return x.y<y.y;
}
bool operator==(const Pt &x,const Pt &y){
	return x.x==y.x&&x.y==y.y;
}


V solve(V w,const ll &T){
	V z(m+2);
	sort(all(w));
	rep(i,1,n) w[i]+=w[i-1];
	
	static int stk[100010];
	int top=0;
	rep(i,0,n){
		pt[i]=(Pt){i,T-w[i]+n-i};
	}
	sort(pt,pt+n+1);
	rep(i,0,n){
		while (top>1&&cross(pt[stk[top]]-pt[stk[top-1]],pt[i]-pt[stk[top]])>=0) --top;
		stk[++top]=i;
	}
	for (int i=1,j=1;i<=m+1;++i){
		while (j<top){
			const Pt &u=pt[stk[j]],&v=pt[stk[j+1]];
			if (u.x*1LL*i+u.y<v.x*1LL*i+v.y) ++j;
			else break;
		}
//		printf("  test choice %d: %d\n",i,j);
		const Pt &u=pt[stk[j]];
		z[i]=u.x*1LL*i+u.y-1LL*n*i;
	}

//	rep(i,1,m+1){
//		ll &u=z[i]; u=-1e18;
//		rep(j,0,n) u=max(u,T-w[j]-1LL*(n-j)*(i-1));
//	}
	
	return z;
}

int check1(int o){
//	printf("check1 %d\n",o);
	static int a[100010];
	ll sum=0,W=0; int L=0;
	per(i,o+1,m){
//		printf("  into %d\n",i);
		if (~b[i]){
			a[i]=b[i]; sum+=a[i]; //L=0;
			if (a[i]<a[i+1]) return -1;
			W+=1LL*L*(a[i]-a[i+1]); L=0;
			if (sum>=lim[i]) continue;
			W-=lim[i]-sum; sum=lim[i]; if (W<0) return -1;
//			printf("  test %d: sum %lld W %lld L %d\n",i,sum,W,L);
			continue;
		}
		a[i]=a[i+1]; sum+=a[i];
		L=i==m||~b[i+1]?1:L+1;
		if (sum>=lim[i]) continue;
		if (W>=lim[i]-sum){W-=lim[i]-sum,sum=lim[i]; continue;}
		sum+=W; W=0;
		const ll d=(lim[i]-sum+L-1)/L;
		if (a[i]+d>n) return -1;
		a[i]+=d; W+=d*L-(lim[i]-sum); sum=lim[i];
		if (sum>T) return -1;
//		printf("  test %d: sum %lld W %lld L %d\n",i,sum,W,L);
	}
//	printf("  front %d sum %lld W %lld L %d\n",a[o+1],sum,W,L);
	
//	const auto check2=[&](int w,ll sum,ll W,int L){
//		printf("  check2 %d: sum %lld W %lld L %d\n",w,sum,W,L);
//		if (w<a[o+1]) return 1;
//		rep(i,1,o) if (sum+(o-i+1)*1LL*w<lim[i]) return 1;
//		sum+=o*1LL*w;
//		if (sum>T) return -1;
//		W+=(w-a[o+1])*1LL*L;
//		if (T-sum>W) return 1;
//		return 0;
//	};
	const auto check2=[&](int w,ll sum,ll W,int L){
//		printf("  check2 %d: sum %lld W %lld L %d\n",w,sum,W,L);
		if (w<a[o+1]) return 1;
		W+=1LL*L*(w-a[o+1]);
		rep(i,1,o){
			const ll e=sum+1LL*(o-i+1)*w;
			if (e<lim[i]){
				if (W<lim[i]-e) return 1;
				W-=lim[i]-e,sum+=lim[i]-e;
			}
		}
		sum+=1LL*o*w;
		if (sum>T) return -1;
		if (W<T-sum) return 1;
		return 0;
	};
	
	int fixed=-1;
	rep(i,1,o)
		if (~b[i]){
			fixed=b[i]; break;
		}
	if (~fixed){
		return check2(fixed,sum,W,L)?-1:fixed;
	}
	
	int l=0,r=n,mid,z=-1;
	while (l<=r){
		mid=l+r>>1;
		const int w=check2(mid,sum,W,L);
		if (!w) z=mid;
		if (w>=0) l=mid+1;
		else r=mid-1;
	}
//	printf("  z %d\n",z);
	return z;
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) L[i]=read(),R[i]=read();
	q=read(); memset(b,-1,sizeof b);
	while (q--){
		int p=read(),w=read();
		b[p]=w;
	}
	scanf("%lld",&T);
	ll W=0; rep(i,1,n) W+=L[i];
	const auto F=solve(V(L,L+n+1),W);
	const auto G=solve(V(R,R+n+1),T);
	rep(i,1,m+1) lim[i]=max(F[i],G[i]);
//	rep(i,1,m+1) printf("lim %d = %lld  %lld %lld\n",i,lim[i],F[i],G[i]);
	
	if (lim[m+1]>0) NO;
	int fixed=-1,ok;
	rep(i,1,m){
		if (~b[i]){
			if (~fixed&&fixed!=b[i]) break;
			fixed=b[i];
		}
		ok=i;
	}
	
//	printf("test check1 1 %d\n",check1(1));
//	return;
	
	int l=1,r=ok,mid;
	while (l<r){
		mid=l+r+1>>1;
		if (check1(mid)>=0) l=mid;
		else r=mid-1;
//		int w=check1(mid);  // !!!
//		printf("  z %d\n",w);
//		if (w>=0) l=mid;
//		else r=mid-1;
	}
	const int w=check1(l);
	if (w<0) NO;
	printf("%d %d\n",l,w);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}