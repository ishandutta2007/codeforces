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

int n,p[5010];
struct Pt{
	ll x,y;
}pt[5010];
Pt operator-(Pt x,Pt y){return (Pt){x.x-y.x,x.y-y.y};}
ll dot(Pt x,Pt y){
	return x.x*y.x+x.y*y.y;
}
void solve(){
	n=read();
	rep(i,1,n) pt[i]=(Pt){read(),read()},p[i]=i;
	rep(i,3,n){
		per(j,2,i-1)
			if (dot(pt[p[j-1]]-pt[p[j]],pt[p[j+1]]-pt[p[j]])<=0) swap(p[j],p[j+1]);
			else break;
	}
	rep(i,2,n-1) assert(dot(pt[p[i-1]]-pt[p[i]],pt[p[i+1]]-pt[p[i]])>0);
	rep(i,1,n) printf("%d ",p[i]);
}
int main()
{
	for (int T=1;T--;) solve();
}