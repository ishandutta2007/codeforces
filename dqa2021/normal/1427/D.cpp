#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
typedef long long ll;
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
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

int n,p[64],q[64];
vector<vector<int> > S;
vector<int> work(int a,int b){
	vector<int> T; if (a^1) T.pb(a-1);
	while (b>a&&p[b-1]%n+1==p[b]) b--;
	assert(b>a);
	T.pb(b-a);
	T.pb(n-b+1);
	int top=0;
	rep(i,b,n) q[++top]=p[i];
	rep(i,a,b-1) q[++top]=p[i];
	rep(i,1,a-1) q[++top]=p[i];
	memcpy(p,q,sizeof p);
	return T;
}
bool check(){
	rep(i,1,n-1) if (p[i]%n+1!=p[i+1]) return 0;
	return 1;
}
void solve(){
	n=read();
	rep(i,1,n) p[i]=read();
	while (!check()){
		//rep(i,1,n) printf("%d ",p[i]); puts("");
		int b=n,a;
		rep(i,1,n-1) if (p[n]%n+1==p[i]) a=i;
		S.pb(work(a,b));
	}
	int a;
	rep(i,1,n) if (p[i]==1) a=i;
	if (a!=1){
		vector<int> T;
		T.pb(a-1); T.pb(n-a+1);
		S.pb(T);
	}
	printf("%d\n",int(S.size()));
	for (const auto &T: S){
		printf("%d ",int(T.size()));
		for (int x: T) printf("%d ",x);
		puts("");
	}
}
int main()
{
	for (int T=1;T--;) solve();
}