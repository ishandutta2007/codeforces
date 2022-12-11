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
#define forall(x,y) for (const int &y: e[x])
const int lim=1e9;

int n,m;
int w[5010];

void solve(){
	n=read(),m=read();
	//puts("test");
	if (n<=2){
		if (m) puts("-1"),exit(0);
		rep(i,1,n) printf("%d ",i);
		return;
	}
	w[1]=1,w[2]=2;
	int pos=2;
	rep(i,3,n){
		if (!m) break;
		pos=i;
		w[i]=i;
		int c=pos-1>>1;
		while (m-c<0){
			++w[i];
			c=pos-1-(w[i]-i)>>1;
		}
		m-=c;
	}
	if (m) puts("-1"),exit(0);
	rep(i,pos+1,n) w[i]=800000000+i*20000;
	rep(i,1,n) printf("%d ",w[i]);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}