#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 202000, inf = 0x3f3f3f3f;
int head[N],n,m,s,k,to[N],nxt[N],edgenum;
void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u];head[u]=edgenum;
}
int dis[102][102000],a[N],q[N],v[N];
void gety(int x) {
	memset(dis[x],inf,sizeof(dis[x]));
	int f=0,r=0; rep(i,1,n) if (a[i]==x) dis[x][i]=0,q[r++]=i;
	while (f!=r) {
		int u=q[f++];
		L(i,u) if (dis[x][to[i]]>dis[x][u]+1) {
			dis[x][to[i]]=dis[x][u]+1; q[r++]=to[i];
		}
	}
}
int main() {
	read(n);read(m);read(k);read(s);
	rep(i,1,n) read(a[i]);
	rep(i,1,m) {int u,v;read(u);read(v);add(u,v);add(v,u);}
	rep(i,1,k) gety(i);
	rep(i,1,n) {
		rep(j,1,k) v[j]=dis[j][i];
		sort(v+1,v+k+1); ll res=0;
		rep(i,1,s) res+=v[i];
		cout<<res<<' ';
	}
	return 0;
}