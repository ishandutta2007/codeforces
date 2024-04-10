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

int n; char s[500010];
struct C{
	int p,L;
}stk[500010]; int top;
ll getsum(int l,int r){
	return (l+r)*1LL*(r-l+1)/2;
}
ll coef(int o){
	if (!o) return 0;
	const C &v=stk[o];
	int P=stk[o+1].p-v.p;
	return getsum(stk[o+1].L+1,stk[o].L)+(P-stk[o].L+stk[o+1].L)*1LL*stk[o+1].L;
}
void solve(){
	n=read(); scanf("%s",s+1);
	ll ans=0,tot=0;
	rep(i,1,n){
		if (s[i]=='0'){
			ans+=tot;
			if (top) ans+=getsum(1,stk[top].L)+stk[1].L*1LL*(stk[1].p-1);
			//printf("ans %d = %lld\n",i,ans);
			continue;
		}
		if (i==1||s[i-1]=='0'){
			stk[++top]=(C){i,1};
			tot+=coef(top-1);  //top=0
		}
		else{
			C v=stk[top--]; v.L++;
			while (top&&v.L>stk[top].L) tot-=coef(top),top--;
			tot-=coef(top);
			stk[++top]=v; tot+=coef(top-1);
		}
		ans+=tot;
		ans+=getsum(1,stk[top].L)+stk[1].L*1LL*(stk[1].p-1);
		//printf("ans %d = %lld\n",i,ans);
	}
	printf("%lld\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
}