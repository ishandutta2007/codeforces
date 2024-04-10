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


void solve(){
	int q=read();
	while (q--){
		ll u=read(),v=read();
		if (u>v){puts("NO");continue;}
		int l=0,r=0; bool f=1;
		rep(i,0,29){
			const int s=u>>i&1,t=v>>i&1;
			l+=s,r+=s; r<<=1;
			while (l<=r&&(l&1)!=t) l++;
			while (l<=r&&(r&1)!=t) r--;
			if (l>r){
				f=0; break;
			}
			l>>=1,r>>=1;
		}
		if (l>0) f=0;
		puts(f?"YES":"NO");
	}
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}