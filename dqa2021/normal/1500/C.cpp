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
typedef vector<int> V;
typedef pair<V,int> P;
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

int n,m;
int a[1510][1510],b[1510][1510];
int p[1510],q[1510];
bitset<1510> S[1510],T[1510],E;
void solve(){
	n=read(),m=read();
	set<P> st;
	rep(i,1,n) rep(j,1,m) a[i][j]=read();
	rep(i,1,n) rep(j,1,m) b[i][j]=read();
	bool f=1;
	rep(i,1,n) rep(j,1,m) f=f&&a[i][j]==b[i][j];
	if (f) puts("0"),exit(0);
	rep(i,1,n){
		vector<int> S(a[i]+1,a[i]+m+1);
		st.insert(P(S,i));
	}
	rep(i,1,n){
		vector<int> T(b[i]+1,b[i]+m+1);
		auto it=st.lower_bound(P(T,0));
		if (it==st.end()||it->fi!=T) puts("-1"),exit(0);
		p[it->se]=i,q[i]=it->se; st.erase(it);
	}
	rep(j,1,m){
		S[j].set();
		rep(i,1,n-1) if (a[q[i]][j]<a[q[i+1]][j]) S[j].reset(i);
	}
	rep(j,1,m){
		rep(i,1,n-1) if (a[q[i]][j]>a[q[i+1]][j]) T[j].set(i);
	}
	E.set();
	static int que[1510],hd,tl,vis[1510];
	rep(j,1,m) if ((E&T[j]).none()) que[++tl]=j,vis[j]=1;
	while (hd<tl){
		int u=que[++hd];
		E&=S[u];
		rep(v,1,m) if (!vis[v]&&(E&T[v]).none()) vis[v]=1,que[++tl]=v;
	}
	rep(i,1,n-1) if (q[i]>q[i+1]&&E[i]) puts("-1"),exit(0);
	printf("%d\n",tl);
	per(i,1,tl) printf("%d ",que[i]);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}