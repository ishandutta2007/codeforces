#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 466666;
int n,m,res;Vi e[N];bool vis[N];
void dfs(int u){
	vis[u]=1;
	rep(i,0,SZ(e[u])-1)if(!vis[e[u][i]])dfs(e[u][i]);
}
int main() {
	read(n);read(m);
	rep(i,1,m){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	res=n;
	rep(i,1,n)if(!vis[i]){
		res--;dfs(i);
	}
	cout<<m-res;
	return 0;
}