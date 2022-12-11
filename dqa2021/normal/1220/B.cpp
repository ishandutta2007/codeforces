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
const int mod=998244353;

int n;
int w[1024][1024];

int work(int a,int b,int c){
	for (int i=1;i*i<=a;++i)
		if (a%i==0){
			int x=i,y=a/i;
			if (b%x==0&&c%y==0&&b/x==c/y) return x;
			swap(x,y);
			if (b%x==0&&c%y==0&&b/x==c/y) return x;
		}
}

void solve(){
	n=read();
	rep(i,1,n) rep(j,1,n) w[i][j]=read();
	rep(i,1,n){
		int a=i,b=1,c=2;
		while (b==a) ++b;
		while (c==a||c==b) ++c;
		printf("%d ",work(w[a][b],w[a][c],w[b][c]));
	}
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}