#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1222222;
int n,m;Vi nxt[N],pre[N];bool vis[N],cho[N];
void solve(int u){
	per(i,SZ(nxt[u])-1,0)vis[nxt[u][i]]=1;vis[u]=1;
	int p=u;while(p<=n&&vis[p])p++;
	if(p>n){cho[u]=1;return;}solve(p);
	cho[u]=1;per(i,SZ(pre[u])-1,0)if(cho[pre[u][i]])cho[u]=0;
}
int main() {
	read(n);read(m);rep(i,1,m){
		int u,v;read(u);read(v);nxt[u].pb(v);pre[v].pb(u);
	}
	solve(1);int len=0;static int s[N];rep(i,1,n)if(cho[i])s[++len]=i;
	printf("%d\n",len);rep(i,1,len)printf("%d ",s[i]);
	return 0;
}