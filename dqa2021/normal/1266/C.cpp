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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,m;
void solve(){
	n=read(),m=read();
	if (n==1&&m==1) return puts("0"),void();
	if (n==1){
		rep(i,1,m) printf("%d ",i+1);
		exit(0);
	}
	if (m==1){
		rep(i,1,n) printf("%d\n",i+1);
		exit(0);
	}
	rep(i,1,n)
		rep(j,1,m)
			printf("%d%c",(i+m)*j," \n"[j==m]);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}