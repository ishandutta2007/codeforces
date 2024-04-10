#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 105;
int n,m,ans;
char s[N][N],p[N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int a[6],used[6];
int sx,sy,tx,ty;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int solve() {
	int x=sx,y=sy; int len=strlen(p+1);
	rep(i,1,len) {
		int d=a[p[i]-'0'];
		x+=dx[d]; y+=dy[d];
		if (x<1||x>n||y<1||y>m||s[x][y]=='#') return 0;
		if (s[x][y]=='E') return 1;
	}
	return 0;
}
inline void dfs(int dep) {
	if (dep>3) {
	//	rep(i,0,3) printf("%d ",a[i]); puts("");
		ans+=solve();
		return;
	}
	rep(i,0,3) if (!used[i]) {
		used[i]=1; a[dep]=i; dfs(dep+1);
		used[i]=0; a[dep]=0;
	}
}
int main() {
	read(n); read(m); rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,m) {
		if (s[i][j]=='S') {sx=i; sy=j;}
		if (s[i][j]=='E') {tx=i; ty=j;}
	}
	scanf("%s",p+1);
	dfs(0); printf("%d",ans);
	return 0;
}