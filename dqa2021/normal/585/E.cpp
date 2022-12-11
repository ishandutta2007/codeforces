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
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
int prm[1000010],mu[10000010];
bool vis[10000010];
void sieve(int x){
	mu[1]=1;
	rep(i,2,x){
		if (!vis[i]) prm[++*prm]=i,mu[i]=mod-1;
		rep(j,1,*prm){
			const int v=i*prm[j];
			if (v>x) break;
			vis[v]=1;
			if (i%prm[j]==0) break;
			mu[v]=upd(-mu[i]);
		}
	}
	//printf("%d\n",*prm);
}

int n,m,pw[500010];
int c[10000010],d[10000010];
void solve(){
	n=read();
	pw[0]=1; rep(i,1,n) pw[i]=upd((pw[i-1]<<1)-mod);
	rep(i,1,n){
		int x=read();
		m=max(m,x);
		++c[x];
	}
	sieve(m);
	rep(i,1,*prm){
		const int &x=prm[i];
		per(j,1,m/x) c[j]+=c[x*j];
	}
	rep(i,1,m) d[i]=pw[c[i]]-1;
	int S=0;
	rep(i,2,m) iadd(S,1LL*mu[i]*d[i]%mod);
	d[1]=S;
	int z=0;
	rep(i,1,m){
		add(z,1LL*d[i]*c[i]%mod*mu[i]%mod);
		//printf("test %d: c %d d %d mu %d\n",i,c[i],d[i],mu[i]);
	}
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}