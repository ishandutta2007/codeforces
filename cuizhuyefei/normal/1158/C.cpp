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
const int N = 555555;
int n,p[N],sta[N],top,ans[N];
Vi e[N];int deg[N];
void ins(int u, int v){
	e[u].pb(v);deg[v]++;
}
void solve(){
	rep(i,0,n+1)deg[i]=0,e[i].clear();
	top=0;sta[++top]=n+1;
	per(i,n,1){
		if(p[i]<0)p[i]=sta[top];
		while(top&&sta[top]!=p[i])ins(sta[top],i),top--;
		if(!top){puts("-1");return;}
		ins(i,sta[top]);sta[++top]=i;
	}
	top=0;rep(i,1,n+1)if(!deg[i])sta[++top]=i;int cnt=0;
	while(top){
		int u=sta[top--];ans[u]=++cnt;
		rep(i,0,SZ(e[u])-1)if(!--deg[e[u][i]])
			sta[++top]=e[u][i];
	}
	rep(i,1,n)printf("%d ",ans[i]);puts("");
}
int main() {
	int T;read(T);
	while(T--){
		read(n);rep(i,1,n)read(p[i]);
		solve();
	}
	return 0;
}