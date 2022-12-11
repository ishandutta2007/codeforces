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

int n,m;
vector<int> e[200010];
int c[200010];
void solve(){
	n=read(),m=read();
	rep(i,1,n) e[i].clear();
	rep(i,1,m){
		int u=read(),v=read();
		e[v].pb(u);
	}
	vector<int> S;
	rep(u,1,n){
		int a=0,b=0;
		for (int v: e[u]){
			if (c[v]==1) a++;
			else if (c[v]==0) b++;
		}
		if (a) c[u]=2,S.pb(u);
		else if (b) c[u]=1;
		else c[u]=0;
	}
	assert(int(S.size())<=n*4/7);
	printf("%d\n",int(S.size()));
	for (int x: S) printf("%d ",x);
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}