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
#define all(x) (x).begin(),(x).end()

int n,p[100010];
bool mrk[100010];
int L[100010],R[100010];
int f[100010],g[100010];
void solve(){
	n=read();
	rep(i,1,n) p[i]=read();
	int c=0;
	rep(i,1,n){
		if (i==1||i==n||(p[i]<p[i+1])==(p[i]<p[i-1])){
			mrk[i]=1; L[i]=c,R[c]=i; c=i;
//			printf("pos %d\n",i);
		}
	}
	rep(i,2,n){
		if (mrk[i]){
			f[i]=max(f[L[i]],i-L[i]);
		}
	}
	per(i,1,n-1){
		if (mrk[i]){
			g[i]=max(g[R[i]],R[i]-i);
		}
	}
	int tot=0;
	rep(i,2,n-1){
		if (!mrk[i]) continue;
		if (p[i]<p[i+1]) continue;
		if (max(i-L[i],R[i]-i)<=max(f[L[i]],g[R[i]])) continue;
		int len=i-L[i];
		if (len&1); else --len;
		if (len>=R[i]-i) continue;
		len=R[i]-i;
		if (len&1); else --len;
		if (len>=i-L[i]) continue;
		tot++;
	}
	printf("%d\n",tot);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}