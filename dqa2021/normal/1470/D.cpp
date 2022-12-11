#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
/*
typedef pair<int,int> P;
*/
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

int n,m;
struct E{
	int t,n;
}e[600010];
int cnt,last[300010];  //cnt=1
void addedge(int x,int y){
	e[++cnt]=(E){y,last[x]},last[x]=cnt;
	e[++cnt]=(E){x,last[y]},last[y]=cnt;
}
bool mrk[300010];
bool vis[300010];
void dfs(int x,bool c){
	vis[x]=1;
	for (int i=last[x],v;i;i=e[i].n){
		v=e[i].t; if (!vis[v]) continue;
		if (mrk[v]) c=0;
	}
	mrk[x]=c;
	for (int i=last[x],v;i;i=e[i].n){
		v=e[i].t; if (vis[v]) continue;
		dfs(v,c^1);
	}
}
void solve(){
	n=read(),m=read();
	cnt=1; rep(i,1,n) last[i]=mrk[i]=vis[i]=0;  //init
	rep(i,1,m) addedge(read(),read());
	dfs(1,1);
	rep(i,1,n) if (!vis[i]) return puts("NO"),void();
	puts("YES");
	vector<int> S;
	rep(i,1,n) if (mrk[i]) S.pb(i);
	printf("%d\n",int(S.size()));
	for (int x: S) printf("%d ",x);
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
}