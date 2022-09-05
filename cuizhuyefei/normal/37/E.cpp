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
const int N = 505, M = 25005000, inf = 0x3f3f3f3f;
int n,m,num,dfn[N][N],dis[N];
bool mtr[2505][2505],v[2505];
char s[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int q[2505],head[2505],nxt[M],to[M],edgenum;
void addedge(int u, int v) {to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;}
inline void dfs(int x, int y) {
	dfn[x][y]=num;
	rep(i,0,3) {
		int nx=x+dx[i],ny=y+dy[i];
		if (nx>=1&&nx<=n&&ny>=1&&ny<=m) {
			if (s[nx][ny]==s[x][y]&&!dfn[nx][ny]) dfs(nx,ny);
			if (s[nx][ny]!=s[x][y]&&dfn[nx][ny])
				mtr[num][dfn[nx][ny]]=mtr[dfn[nx][ny]][num]=1;
		}
	}
}
inline int getdis(int s) {
	memset(dis,inf,sizeof(dis));
	int res=0,f=0,r=1; q[f]=s; dis[s]=0;
	while (f!=r) {
		int u=q[f++]; res=max(res,dis[u]);
		L(i,u) if (dis[to[i]]>dis[u]+1) {
			dis[to[i]]=dis[u]+1; q[r++]=to[i];
		}
	}
	return res;
}
int main() {
	read(n);read(m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m)if(!dfn[i][j]){++num;v[num]=s[i][j]=='B';dfs(i,j);}
	rep(i,1,num) rep(j,1,num) if (mtr[i][j]) addedge(i,j);
	int ans=1e9;
	rep(i,1,num) {int d=getdis(i); ans=min(ans,d+(((d+v[i])&1)?1:0));}
	cout<<ans;
	return 0;
}