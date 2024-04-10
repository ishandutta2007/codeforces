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

int n;
bool c[1210];
int m;
int w[1210]; bool g[1210];
int stk[1210],top;
int f[1210],d[1210];
bool used[1210];
void solve(){
	n=read();
	rep(i,1,3*n) c[read()]=1;
	rep(i,1,6*n){
		if (!top||c[stk[top]]^c[i]) w[i]=++m,g[m]=c[i],stk[++top]=i;
		else if (top==1||c[stk[top-1]]^c[i]) w[i]=w[stk[top]],stk[++top]=i;
		else{
			w[i]=w[stk[top]];
			top-=2;
			++d[f[w[i]]=w[stk[top]]];  //caution 0
		}
	}
	assert(top==0);
	bool e=0;
	int gtot=0;
	rep(i,1,m) gtot+=g[i]==0&&!f[i];
	assert(gtot);
	rep(i,1,2*n){
		e^=1; int o=-1;
		rep(j,1,m){
			if (g[j]^e) continue;
			if (used[j]) continue;
			if (d[j]) continue;
			if (i<2*n&&!e&&!f[j]&&gtot==1) continue;
			o=j; break;
		}
		assert(~o);
		gtot-=!e&&!f[o];
		d[f[o]]--;
		used[o]=1;
		rep(j,1,6*n) if (w[j]==o) printf("%d ",j);
		puts("");
	}
}
int main()
{
	for (int T=1;T--;) solve();
}