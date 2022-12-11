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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n;
int d[100010];
int p[200010],m;

void solve(){
	n=read();
	rep(i,1,n) d[i]=read(),p[i]=i*2-1;
	sort(p+1,p+n+1,[&](int x,int y){
		return d[x+1>>1]>d[y+1>>1];
	});
	//rep(i,1,n-1) printf("%d %d\n",p[i]*2-1,p[i+1]*2-1);
	m=n;
	rep(i,1,n){
		int o=p[i]+1>>1; //p[i]=p[i]*2-1;
		if (i+d[o]>m){
			assert(i+d[o]==m+1);
			p[++m]=o*2;
		}
		else{
			printf("%d %d\n",p[i+d[o]-1],o*2);
		}
	}
	rep(i,1,m-1) printf("%d %d\n",p[i],p[i+1]);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}