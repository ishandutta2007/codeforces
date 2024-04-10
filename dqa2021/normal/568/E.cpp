#pragma GCC optimize(2,3,"Ofast")
#pragma GCC optimize("unroll-loops")

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
const int INF=1e9+7;

int n,m,lim;
int a[100010],b[100010];
int pre[200010],suf[200010];
bool mrk[200010];

P tri[200010];
inline void ins(int x,const P &w){
	for (;x;x-=x&-x) tri[x]=max(tri[x],w);
}
inline P ask(int x){
	P z(0,n+1);
	for (;x<=lim;x+=x&-x) z=max(z,tri[x]);
	return z;
}

int f[100010],g[2][200010];
int s[100010],t[2][200010];

vector<int> S;

void work(int o,int &z,int &q){
	if (~a[o]){
		const auto &[w,p]=ask(a[o]+1);
		if (w+1>f[o]) f[o]=w+1,s[o]=p;
		ins(a[o],P(f[o],o));
		//printf("get %d %d %d\n",f[o],o,s[o]);
		if (f[o]>z) z=f[o],q=o;
		return;
	}
	static bool e=0; e^=1;
	auto g=::g[e],h=::g[e^1],t=::t[e],d=::t[e^1];
	for (int i=suf[0];i<=lim;i=suf[i]) g[i]=1,t[i]=n+1;
	rep(i,o+1,n)
		if (~a[i]){
			const int &p=pre[a[i]];
			if (!p) continue;
			if (f[i]>=g[p]) g[p]=f[i]+1,t[p]=i;
		}
	for (int i=suf[0];i<=lim;i=suf[i]){
		const int &j=pre[i];
		if (!j) continue;
		if (h[i]>=g[j]) g[j]=h[i]+1,t[j]=d[i];
	}
	for (int i=pre[lim+1];i;i=pre[i]){
		const int &j=pre[i];
		if (!j){
			//printf("get %d %d %d\n",g[i],o,t[i]);
			s[o]=t[i];
			if (g[i]>z) z=g[i],q=o;
			break;
		}
		if (g[i]>g[j]) g[j]=g[i],t[j]=t[i];
	}
	
	//printf("  dp %d =",o);
	//for (int i=suf[0];i<=lim;i=suf[i]) printf("  %d,%d,%d",S[i],g[i],t[i]);
	//puts("");
	
	rep(i,1,o-1) if (~a[i]){
		const int &p=suf[a[i]];
		if (p>lim) continue;
		if (g[p]>=f[i]) f[i]=g[p]+1,s[i]=t[p];
	}
}

void solve(){
	n=read();
	rep(i,1,n) a[i]=read();
	m=read();
	rep(i,1,m) b[i]=read();
	sort(b+1,b+m+1);
	S.pb(0);
	rep(i,1,n) if (~a[i]) S.pb(a[i]);
	S.insert(S.end(),b+1,b+m+1);
	sort(all(S));
	S.erase(unique(all(S)),S.end());
	rep(i,1,S.size()-1) if (binary_search(b+1,b+m+1,S[i])) mrk[i]=1;
	rep(i,1,n) if (~a[i]) a[i]=lower_bound(all(S),a[i])-S.begin();
	rep(i,1,m) b[i]=lower_bound(all(S),b[i])-S.begin();
	lim=S.size()-1;
	//rep(i,1,lim) printf("mrk %d = %d\n",i,mrk[i]);
	{
	int p=0;
	rep(i,1,lim+1){
		pre[i]=p;
		if (mrk[i]) p=i;
	}
	}
	{
	int p=lim+1;
	per(i,0,lim){
		suf[i]=p;
		if (mrk[i]) p=i;
	}
	}
	rep(i,1,lim) tri[i]=P(0,n+1),t[0][i]=n+1;
	rep(i,1,n) s[i]=n+1;
	int z=0,p=-1;
	per(i,1,n) work(i,z,p);
	
	multiset<int> st(b+1,b+m+1);
	static int c[100010];
	rep(i,1,n) c[i]=a[i];
	for (int i=p;i<=n;i=s[i]){
		int l=i,r=s[i]-1,dlim=~a[l]?a[l]:0,ulim=r<n?a[r+1]:INF;
		//printf("test %d %d\n",l,r);
		rep(j,l,r){
			if (~c[j]) continue;
			const auto it=st.upper_bound(dlim);
			if (it==st.end()||*it>=ulim) continue;
			dlim=c[j]=*it; st.erase(it);
		}
	}
	rep(i,1,n) if (!~c[i]) c[i]=*st.begin(),st.erase(st.begin());
	//printf("%d\n",z);
	rep(i,1,n) printf("%d ",S[c[i]]);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}