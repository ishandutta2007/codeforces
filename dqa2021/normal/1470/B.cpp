#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
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
/*
typedef pair<int,int> P;
*/
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

bool vis[1000010];
vector<int> e[1000010];
int f[1000010];
void prepare(){
	rep(i,2,1e6){
		if (vis[i]) continue;
		for (int j=i;j<=1e6;j+=i)
			vis[j]=1,e[j].pb(i);
	}
	rep(i,1,1e6){
		int S=1,T=i;
		for (int x: e[i]){
			bool g=0;
			while (T%x==0) T/=x,g^=1;
			if (g) S*=x;
		}
		f[i]=S;
	}
}
int n,a[300010];
int tot[1000010];
bool mrk[1000010];
void solve(){
	n=read();
	int A=0,B=0,C=0;
	rep(i,1,n){
		a[i]=read(),tot[f[a[i]]]++;
//		printf("test get %d\n",f[a[i]]);
	}
	rep(i,1,n){
		if (mrk[f[a[i]]]) continue;
		mrk[f[a[i]]]=1;
		int t=tot[f[a[i]]];
		if (f[a[i]]>1&&t%2==1) A=max(A,t);
		else B=max(B,t),C+=t;
	}
	rep(i,1,n) mrk[f[a[i]]]=0;
	int q=read();
	while (q--){
		if (read()) printf("%d\n",max(A,C));
		else printf("%d\n",max(A,B));
	}
	rep(i,1,n) tot[f[a[i]]]=0;
}
int main()
{
	prepare();
	for (int T=read();T--;) solve();
}