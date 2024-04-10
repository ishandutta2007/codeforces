#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n;
ll a[100010];
int getbt(ll x){
	int z=0;
	while ((1LL<<z)<=x) ++z;
	//printf("getbt %lld = %d\n",x,z);
	return z-1;
}
void solve(){
	n=read();
	rep(i,1,n) a[i]=read();
	int mx=-1;
	rep(i,2,n){
		if (a[i]>=a[i-1]) continue;
		mx=max(mx,getbt(a[i-1]-a[i]));
		a[i]=a[i-1];
	}
	printf("%d\n",mx+1);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}