#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
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
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,p[4010];
bitset<4010> dp;
void ins(int x){
//	if (x>n) return;
	dp|=dp<<x;
}
void solve(){
	n=read();
	rep(i,1,n<<1) p[i]=read();
	dp.reset(); dp.set(0);
	for (int l=1,r;l<=n*2;l=r+1){
		for (r=l;r<n*2&&p[r+1]<p[l];++r);
		ins(r-l+1);
	}
	puts(dp[n]?"YES":"NO");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}