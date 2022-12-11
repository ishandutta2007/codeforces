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

int n,m;

struct C{
	int u,v,t;
}c[155];

struct D{
	bitset<155> b[155];
}d[155][32];

D operator*(const D &x,const D &y){
	static D z;
	rep(i,1,n){
		z.b[i].reset();
		rep(j,1,n) if (x.b[i][j]) z.b[i]|=y.b[j];
	}
	return z;
}

bitset<155> operator*(const bitset<155> &x,const D &y){
	static bitset<155> z;
	z.reset();
	rep(j,1,n) if (x[j]) z|=y.b[j];
	return z;
}

bool check(const int t){
	bitset<155> S;
	S.set(1);
	int s=0;
	c[m+1].t=2e9;
	rep(i,1,m){
		const int v=min(t,c[i+1].t)-s;
		rep(j,0,29) if (v>>j&1) S=S*d[i][j];
		s+=v; if (s==t) break;
	}
	return S[n];
}

void solve(){
	n=read(),m=read();
	rep(i,1,m) c[i]=(C){read(),read(),read()};
	c[++m]=(C){n,n,0};
	sort(c+1,c+m+1,[&](const C &x,const C &y){return x.t<y.t;});
	rep(i,1,m){
		d[i][0]=d[i-1][0];
		d[i][0].b[c[i].u].set(c[i].v);
		rep(j,1,29) d[i][j]=d[i][j-1]*d[i][j-1];
	}
	int l=1,r=c[m].t+n+10,mid;
	if (!check(r)) return puts("Impossible"),void();
//	printf("test check %d = %d\n",3,check(3));
	while (l<r){
		mid=l+r>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}