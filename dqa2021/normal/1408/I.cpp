#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<assert.h>
#define pb push_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;
const int mod=998244353;
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
inline int upd(int x){return x+(x>>31&mod);}
inline void add(int &x,int y){x=upd(x+y-mod);}
inline void iadd(int &x,int y){x=upd(x-y);}
inline void add(int &x,ll y){x=(x+y)%mod;}
inline void iadd(int &x,ll y){x=upd(x-y%mod);}
int inv[20],fac[20],ifac[20];
void init(int x){
	inv[1]=1;
	for (int i=2;i<=x;i++) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=ifac[0]=1;
	for (int i=1;i<=x;i++){
		fac[i]=1LL*fac[i-1]*i%mod;
		ifac[i]=1LL*ifac[i-1]*inv[i]%mod;
	}
}

int n,K,U,lim;
int a[65540];
vector<int> R[1000]; int m;
int tot[1000];
bool vis[1000];
int A[65536][17],B[65536][17],C[65536];  //ln ans coef
int ans[65536];
void getln(int *F,int *G){
	assert(F[0]==1);
	G[0]=0;
	for (int i=1;i<=K;i++){
		int t=0;
		for (int j=1;j<i;j++) add(t,1LL*G[j]*j%mod*F[i-j]);
		t=1LL*t*inv[i]%mod;
		G[i]=upd(F[i]-t);
	}
}
void getexp(int *F,int *G){
	assert(F[0]==0);
	for (int i=0;i<=K;i++) F[i]=1LL*F[i]*i%mod;
	G[0]=1;
	for (int i=1;i<=K;i++){
		int &t=G[i]; t=0;
		for (int j=0;j<i;j++) add(t,1LL*G[j]*F[i-j]);
		t=1LL*t*inv[i]%mod;
	}
}
void work(const vector<int> &S,int tot){
	for (int i=0;i<lim;i++){
		bool t=__builtin_parity(i&S[0]);
		C[i]^=t&&tot&1;
		int msk=0;
		for (int j=1;j<=K;j++) if (__builtin_parity(i&S[j])^t) msk|=1<<j-1;
		int *F=A[msk],*G=B[i];
		for (int j=0;j<=K;j++) add(G[j],1LL*F[j]*tot);
	}
}
int main()
{
	n=read(),K=read(),U=read(); lim=1<<U;
	init(K);
	for (int i=1;i<=n;i++) a[i]=read(),*a ^=a[i];
	int md=1;
	while (1<<md < K+1) md++;
	for (int i=0;i+K< 1<<md;i++){
		++m; R[m].reserve(K+1);
		for (int s=i+K,t=s;s>=i;s--)
			R[m].pb(s^t);
	}
	for (int i=md;i<U;i++){
		int lim=1<<i;
		for (int j=lim-K;j<lim;j++){
			++m; R[m].reserve(K+1);
			for (int t=j+K,s=t;s>=j;s--)
				R[m].pb(t^s);
		}
	}
	stable_sort(R+1,R+m+1);
	m=unique(R+1,R+m+1)-R-1;
	for (int i=1;i<=n;i++){
		vector<int> S; S.reserve(K+1);
		for (int j=0;j<=K;j++) S.pb(a[i]^(a[i]-j));
		int p=lower_bound(R+1,R+m+1,S)-R;
		tot[p]++;
	}
	
	for (int i=0;i<1<<K;i++){
		static int D[17];
		D[0]=1;
		for (int j=1;j<=K;j++)
			if (i>>j-1&1) D[j]=mod-ifac[j];
			else D[j]=ifac[j];
		getln(D,A[i]);
	}
	
	for (int i=0;i+K< 1<<md;i++){
		vector<int> S; S.reserve(K+1);
		for (int s=i+K,t=s;s>=i;s--)
			S.pb(s^t);
		int p=lower_bound(R+1,R+m+1,S)-R;
		assert(p<=m&&R[p]==S);
		if (vis[p]) continue;
		vis[p]=1;
		work(S,tot[p]);
	}
	for (int i=md;i<U;i++){
		int lim=1<<i;
		for (int j=lim-K;j<lim;j++){
			vector<int> S; S.reserve(K+1);
			for (int t=j+K,s=t;s>=j;s--)
				S.pb(t^s);
			int p=lower_bound(R+1,R+m+1,S)-R;
			assert(p<=m&&R[p]==S);
			assert(!vis[p]);
			vis[p]=1;
			work(S,tot[p]);
		}
	}
	
	for (int i=1;i<=m;i++) assert(vis[i]);
	
	for (int i=0,t=qpow(n,mod-K-1)*1LL*qpow(2,mod-1-U)%mod;i<lim;i++){
		static int D[17];
		getexp(B[i],D);
		ans[i]=1LL*D[K]*fac[K]%mod*t%mod;
		if (C[i]) ans[i]=upd(-ans[i]);
	}
	for (int i=0;i<U;i++)
		for (int j=0;j<lim;j++)
			if (j>>i&1){
				int u=j^(1<<i),v=j;
				int x=ans[u],y=ans[v];
				ans[u]=upd(x+y-mod);
				ans[v]=upd(x-y);
			}
	static int _ans[65536];
	for (int i=0;i<lim;i++) _ans[*a ^ i]=ans[i];
	for (int i=0;i<lim;i++) printf("%d ",_ans[i]);
	puts("");
	return 0;
}