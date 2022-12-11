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

int n,a[100];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	set<int> st;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			st.insert(a[j]-a[i]);
	printf("%d\n",int(st.size()));
}
int main()
{
	for (int T=read();T--;) solve();
}