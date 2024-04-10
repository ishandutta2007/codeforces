#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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

int n,m,q,k;
P c[3010];
vector<int> f[3010];  // colomn
vector<int> g[3010];  // row

int L[3010],R[3010];

int A[3010],B[3010];

inline int jumpr(int x,int k){
	while (x&&k--) x=R[x]; return x;
}

ll work(int o){
	ll Z=0,S=0;
	rep(i,1,m) f[i].clear();
	rep(i,o,n)
		for (const auto &x: g[i])
			f[c[x].se].pb(x);
	memset(L,0,sizeof L);
	memset(R,0,sizeof R);
	memset(A,0,sizeof A);
	memset(B,0,sizeof B);
	int lst=0;
	rep(i,1,m)
		for (const auto &x: f[i])
			L[x]=lst,R[lst]=x,lst=x;
	L[0]=lst,R[lst]=0;
	for (int i=R[0],j=jumpr(R[0],k-1);i;i=R[i],j=j?R[j]:0){
		A[i]=c[i].se-c[L[i]].se; B[i]=j?m+1-c[j].se:0;
		S+=1LL*A[i]*B[i];
	}
	Z+=S;
	//printf("test %d %d: %lld\n",o,n,S);
	//for (int e=R[0];e;e=R[e]) printf("  %d (%d, %d]: %d %d\n",e,c[L[e]].se,c[e].se,A[e],B[e]);
	per(t,o+1,n){
		for (const auto &x: g[t]){
			//printf("erase %d\n",x);
			S-=1LL*A[x]*B[x];
			const int l=L[x],r=R[x];
			R[l]=r,L[r]=l;
			if (r){
				S-=1LL*A[r]*B[r];
				A[r]=c[r].se-c[l].se;
				S+=1LL*A[r]*B[r];
			}
			int st=l;
			for (int s=0;s<k&&st;++s,st=L[st]);
			st=R[st]; int ed=jumpr(st,k-1);
			while (st!=r){
				S-=1LL*A[st]*B[st];
				B[st]=ed?m+1-c[ed].se:0;
				S+=1LL*A[st]*B[st];
				st=R[st],ed=ed?R[ed]:0;
			}
		}
		Z+=S;
		//printf("test %d %d: %lld\n",o,t-1,S);
		//for (int e=R[0];e;e=R[e]) printf("  %d (%d, %d]: %d %d\n",e,c[L[e]].se,c[e].se,A[e],B[e]);
	}
	return Z;
}

void solve(){
	n=read(),m=read(),q=read(),k=read();
	rep(i,1,q) c[i].fi=read(),c[i].se=read(),g[c[i].fi].pb(i);
	ll ans=0;
	rep(l,1,n) ans+=work(l);
	printf("%lld\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}