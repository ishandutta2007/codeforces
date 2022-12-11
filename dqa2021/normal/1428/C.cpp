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

int n; char s[200010];
int stk[200010],top;  //0 1
void solve(){
	scanf("%s",s+1); n=strlen(s+1);
	top=0;
	per(i,1,n){
		if (s[i]=='A'){
			if (top&&stk[top]==1) --top;
			else stk[++top]=0;
		}
		else stk[++top]=1;
	}
	int tot=0;
	while (top){
		if (top>1&&stk[top-1]==1&&stk[top]==1) top-=2;
		else tot++,top--;
	}
	printf("%d\n",tot);
}
int main()
{
	for (int T=read();T--;) solve();
}