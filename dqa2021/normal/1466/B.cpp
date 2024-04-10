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
const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,int y){x=upd(x+y-mod);}
inline void iadd(int &x,int y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

int n,w[100010];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) w[i]=read();
	int ans=0;
	for (int i=n;i;i--){
		if (i==n||w[i+1]>w[i]+1) ++w[i],++ans;
		else if (w[i+1]==w[i]+1) ++ans;
	}
	printf("%d\n",ans);
}
int main()
{
	for (int T=read();T--;) solve();
}