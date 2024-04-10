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

int n;
struct E{
	int t,n,g;
}e[400010];
int cnt=1,last[200010];
inline void addedge(int x,int y){
	e[++cnt]=(E){y,last[x],0},last[x]=cnt;
	e[++cnt]=(E){x,last[y],0},last[y]=cnt;
}
bool fib[200010];

int siz[200010],I,S;
void getsiz(int x,int f){
	siz[x]=1;
	for (int i=last[x],v;i;i=e[i].n)
		if (!e[i].g&&(v=e[i].t)^f){
			getsiz(v,x); siz[x]+=siz[v];
		}
}
void getedge(int x,int f){
	for (int i=last[x],v;i;i=e[i].n)
		if (!e[i].g&&(v=e[i].t)^f){
			if (fib[siz[v]]&&fib[S-siz[v]]){
				I=i>>1; return;
			}
			getedge(v,x);
		}
}

void solve(int x){
//	printf("solve %d\n",x);
	getsiz(x,0);
	if (siz[x]==1) return;
	I=-1; S=siz[x]; getedge(x,0);
	if (!~I) puts("NO"),exit(0);
	e[I<<1].g=e[I<<1|1].g=1;
//	printf("mrk %d %d\n",e[I<<1].t,e[I<<1|1].t);
	int u=e[I<<1].t,v=e[I<<1|1].t;
	solve(u);
	solve(v);
}

void solve(){
	n=read();
	rep(i,1,n-1) addedge(read(),read());
	int a=1,b=1; fib[1]=1;
	while (1){
		int c=a+b; if (c>n) break;
		fib[c]=1; a=b,b=c;
	}
	if (!fib[n]) puts("NO"),exit(0);
	solve(1);
	puts("YES");
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}