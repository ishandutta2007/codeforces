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

int n; char s[100010];
int c[26];
ll calc1(char x){
	int res=0;
	rep(i,1,n) res+=s[i]==x;
	return res;
}
ll calc2(char x,char y){
	int tot=0;
	ll res=0;
	rep(i,1,n){
		if (s[i]==y) res+=tot;
		if (s[i]==x) tot++;
	}
	return res;
}
void solve(){
	scanf("%s",s+1); n=strlen(s+1);
	ll ans=0;
	rep(i,0,25) ans=max(ans,calc1('a'+i));
	rep(i,0,25) rep(j,0,25) ans=max(ans,calc2('a'+i,'a'+j));
	printf("%lld\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}