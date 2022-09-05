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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2002000;
int n,k,head[N],to[N],nxt[N],edgenum,deg[N];
void add(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
void dfs(int u, int fa, int &dep, int &cnt){
	cnt=0;Vi s;
	L(i,u)if(to[i]!=fa){int a,b;dfs(to[i],u,a,b);s.pb(a+1);cnt+=b;}
	if(!SZ(s)){dep=0;cnt=1;return;}
	sort(s.begin(),s.end());int i;for(i=0;i<SZ(s)-1;i++)if(s[i]+s[i+1]>k)break;
	dep=s[i];cnt-=i;//printf("%d:%d %d\n",u,dep,cnt);
}
int main() {
	read(n);read(k);rep(i,2,n){int u,v;read(u);read(v);add(u,v);add(v,u);deg[u]++;deg[v]++;}
	int rt=1;per(i,n,1)if(deg[i]>1)rt=i;int a,b;dfs(rt,0,a,b);
	printf("%d",b);
	return 0;
}