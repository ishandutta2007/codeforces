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

int n,d[100010],w[100010];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) d[i]=0;
	ll ans=0;
	for (int i=1;i<=n;i++) w[i]=read(),ans+=w[i];
	for (int i=1;i<n;i++){
		int u=read(),v=read();
		d[u]++,d[v]++;
	}
	vector<int> S;
	for (int i=1;i<=n;i++){
		for (int j=1;j<d[i];j++) S.pb(w[i]);
	}
	sort(S.begin(),S.end());
	reverse(S.begin(),S.end());
	printf("%I64d",ans);
	for (int x: S) ans+=x,printf(" %I64d",ans);
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
}