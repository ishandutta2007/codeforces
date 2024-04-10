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

int n; vector<int> e[2010];
int c[2010];
int d[2010];

vector<int> dfs(int x){
	vector<int> w;
	forall(x,y){
		auto o=dfs(y);
		w.insert(w.end(),all(o));
	}
	if (c[x]>w.size()) puts("NO"),exit(0);
	w.pb(x);
	int p=w.size()-1;
	while (p>c[x]) swap(w[p],w[p-1]),--p;
	return w;
}

void solve(){
	n=read();
	int rt=-1;
	rep(i,1,n){
		int f=read(); c[i]=read();
		if (f) e[f].pb(i);
		else rt=i;
	}
	auto w=dfs(rt);
	rep(i,0,w.size()-1) d[w[i]]=i+1;
	puts("YES");
	rep(i,1,n) printf("%d ",d[i]);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}