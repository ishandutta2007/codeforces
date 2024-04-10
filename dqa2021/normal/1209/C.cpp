#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])


int n;
char s[200010];
int c[200010];
//bool ok[200010];

void solve(){
	n=read(); scanf("%s",s+1);
	rep(i,1,n) c[i]=s[i]-'0';
	rep(e,0,9){
		bool g=1;
		int a=0,p=0;
		rep(i,1,n){
			if (c[i]<e){
				if (c[i]<a){
					g=0;
				}
				a=c[i]; p=i;
			}
		}
		int b=9,q=n+1;
		per(i,1,n){
			if (c[i]>e){
				if (c[i]>b){
					g=0;
				}
				b=c[i]; q=i;
			}
		}
		rep(i,1,n) if (c[i]==e&&i<=p&&i>=q) g=0;
		if (!g) continue;
//		printf("e %d g %d p %d q %d\n",e,g,p,q);
		rep(i,1,n){
			if (c[i]<e) putchar('1');
			else if (c[i]>e) putchar('2');
			else putchar(i<=p?'2':'1');
		}
		puts("");
		return;
	}
	puts("-");
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}