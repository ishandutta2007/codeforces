#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define G getchar()
typedef long long ll;
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
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,int y){x=upd(x+y-mod);}
inline void iadd(int &x,int y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

int n; ll w[500010];
int tot[64];
void solve(){
	n=read();
	memset(tot,0,sizeof tot);
	for (int i=1;i<=n;i++){
		w[i]=read();
		for (int j=0;j<60;j++)
			if (w[i]>>j&1) tot[j]++;
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		int A=0,B=0;
		for (int j=0;j<60;j++)
			if (w[i]>>j&1){
				add(A,(1LL<<j)%mod*tot[j]%mod);
			}
		for (int j=0;j<60;j++)
			if (w[i]>>j&1){
				add(B,(1LL<<j)%mod*n%mod);
			}
			else{
				add(B,(1LL<<j)%mod*tot[j]%mod);
			}
		add(ans,1LL*A*B%mod);
	}
	printf("%d\n",ans);
}
int main()
{
	for (int T=read();T--;) solve();
}