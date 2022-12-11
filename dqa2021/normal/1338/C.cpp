#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
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


int jump(int x,int t){
	while (t--){
		++x;
		if (x>3) x=1;
	}
	return x;
}

void solve(){
	//static int cnt=0; ll x=++cnt;
	ll x=read();
	int bt=1; ll lim=3,rk=0;
	while (rk+lim<x) rk+=lim,++bt,lim*=4;
	int t=1;
	while (x%3!=1) --x,++t;
	x=(x-1-rk)/3;
	ll z=t*(1LL<<(bt-1)*2);
	//printf("bt %d = %d\n",bt,t);
	rep(i,0,bt-2){
		const int v=x>>i>>i&3;
		int u;
		if (v==0) u=0;
		else u=jump(v,t-1);
		z+=u*(1LL<<(i*2));
		//printf("bt %d = %d\n",i+1,u);
	}
	printf("%lld\n",z);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}