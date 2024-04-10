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
#define forall(x,y) for (const int &y: e[x])

int n;
struct D{
	int w; char s[200010];
	void work(){
		w=0;
		rep(i,1,n*2){
			if (s[i]=='1') ++w;
			else --w;
		}
	}
}a,b,c;
int f[200010],g[200010];
char t[300010];
void solve(){
	scanf("%d%s%s%s",&n,a.s+1,b.s+1,c.s+1);
	a.work(),b.work(),c.work();
	if (a.w>b.w) swap(a,b);
	if (a.w>c.w) swap(a,c);
	if (b.w>c.w) swap(b,c);
	if (b.w<=0){
		int top;
		top=0;
		rep(i,1,n*2){
			if (a.s[i]=='0') f[++top]=i;
			if (top==n) break;
		}
		top=0;
		rep(i,1,n*2){
			if (b.s[i]=='0') g[++top]=i;
			if (top==n) break;
		}
		
		top=0;
		f[n+1]=g[n+1]=n<<1|1;
		rep(i,1,n+1){
			rep(j,f[i-1]+1,f[i]-1) t[++top]=a.s[j];
			rep(j,g[i-1]+1,g[i]-1) t[++top]=b.s[j];
			if (i<=n) t[++top]='0';
		}
	}
	else{
		int top;
		top=0;
		rep(i,1,n*2){
			if (b.s[i]=='1') f[++top]=i;
			if (top==n) break;
		}
		top=0;
		rep(i,1,n*2){
			if (c.s[i]=='1') g[++top]=i;
			if (top==n) break;
		}
		
		top=0;
		f[n+1]=g[n+1]=n<<1|1;
		rep(i,1,n+1){
			rep(j,f[i-1]+1,f[i]-1) t[++top]=b.s[j];
			rep(j,g[i-1]+1,g[i]-1) t[++top]=c.s[j];
			if (i<=n) t[++top]='1';
		}
	}
	rep(i,1,n*3) putchar(t[i]);
	puts("");
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}