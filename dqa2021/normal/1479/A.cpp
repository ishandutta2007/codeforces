#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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

int n;
int ask(int x){
	printf("? %d\n",x);  fflush(stdout);
	return read();
}
void solve(){
	n=read();
	if (n==1) return printf("! 1\n"),fflush(stdout),void();
	if (ask(1)<ask(2)) return printf("! 1\n"),fflush(stdout),void();
	if (ask(n)<ask(n-1)) return printf("! %d\n",n),fflush(stdout),void();
	int l=1,r=n-1,mid;
	while (l<r){
		mid=l+r>>1;
		if (ask(mid)<ask(mid+1)) r=mid;
		else l=mid+1;
	}
	printf("! %d\n",l); fflush(stdout);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}