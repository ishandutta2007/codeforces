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
typedef pair<int,int> P;
vector<P> S;

int n,a[100010];
void solve(){
	n=read();
	rep(i,1,n) a[i]=read();
	vector<int> A,B;
	per(i,1,n){
		if (!a[i]) continue;
		if (a[i]==1){
			S.pb(P(i,i));
			A.pb(i);
			continue;
		}
		if (a[i]==2){
			if (A.empty()) puts("-1"),exit(0);
			int u=A.back(); A.pop_back();
			S.pb(P(u,i));
			B.pb(i);
			continue;
		}
		if (A.size()+B.size()==0) puts("-1"),exit(0);
		int u;
		if (B.size()) u=B.back(),B.pop_back();
		else u=A.back(),A.pop_back();
		S.pb(P(i,i));
		S.pb(P(i,u));
		B.pb(i);
	}
	printf("%d\n",int(S.size()));
	for (auto x: S) printf("%d %d\n",x.fi,x.se);
}
int main()
{
	for (int T=1;T--;) solve();
}