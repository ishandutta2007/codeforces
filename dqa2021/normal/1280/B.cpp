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
//typedef pair<int,int> P;
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

int n,m;
char a[64][64];
#define mp a
void solve(){
	n=read(),m=read();
	rep(i,1,n) scanf("%s",a[i]+1);
	int tot=0;
	rep(i,1,n) rep(j,1,m) tot+=a[i][j]=='A';
	if (!tot) return puts("MORTAL"),void();
	if (tot==n*m) return puts("0"),void();
	{
	bool g=1;
	rep(i,1,n) g=g&&mp[i][1]=='A';
	if (g) return puts("1"),void();
	g=1;
	rep(i,1,n) g=g&&mp[i][m]=='A';
	if (g) return puts("1"),void();
	g=1;
	rep(i,1,m) g=g&&mp[1][i]=='A';
	if (g) return puts("1"),void();
	g=1;
	rep(i,1,m) g=g&&mp[n][i]=='A';
	if (g) return puts("1"),void();
	}
	{
	for (int x: {1,n})
		for (int y: {1,m})
			if (mp[x][y]=='A')
				return puts("2"),void();
	rep(i,1,n){
		bool g=1;
		rep(j,1,m) g=g&&mp[i][j]=='A';
		if (g) return puts("2"),void(); 
	}
	rep(j,1,m){
		bool g=1;
		rep(i,1,n) g=g&&mp[i][j]=='A';
		if (g) return puts("2"),void(); 
	}
	}
	{
	rep(i,1,n) rep(j,1,m){
		if (mp[i][j]=='A'&&(i==1||i==n||j==1||j==m)) return puts("3"),void();
	}
	}
	puts("4");
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}