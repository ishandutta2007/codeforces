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

int n;
vector<int> e[1010];
int d[1010];
bool mrk[1010];

int getlca(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	return read();
}

void report(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}

void solve(){
	n=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
		++d[u],++d[v];
	}
	int m=n>>1;
	while (m--){
		int u=-1,v=-1;
		rep(i,1,n) if (!mrk[i]){
			if (d[i]==1){
				if (u==-1) u=i;
				else v=i;
			}
		}
		assert(~v);
		int l=getlca(u,v);
		if (l==u||l==v) report(l==u?u:v);
		mrk[u]=mrk[v]=1;
		for (int x: e[u]) --d[x];
		for (int x: e[v]) --d[x];
	}
	rep(i,1,n) if (!mrk[i]) report(i);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}