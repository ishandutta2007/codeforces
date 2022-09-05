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
const int N = 2666666,inf=0x3f3f3f3f;
char S[N];int n,m,vis[N],vis1[N],cnt[N];
Pii getpos(int x){
	int c=x%m;if(!c)c=m;return Pii((x-1)/m+1,c);
}
int getdy(int x, int y){
	return (x-1)*m+y;
}
int getcost(int x, int y){
	if(x>=1&&x<=n&&y>=1&&y<=m)
		return S[(x-1)*m+y]=='.';
	return inf;
}
void dfs(int x, int y){
	if(vis[getdy(x,y)])return;vis[getdy(x,y)]=1;
//	cerr<<x<<' '<<y<<endl;
	if(x+1<=n&&1==getcost(x+1,y))dfs(x+1,y);
	if(y+1<=m&&1==getcost(x,y+1))dfs(x,y+1);
}
void dfs1(int x, int y){
	if(vis1[getdy(x,y)])return;vis1[getdy(x,y)]=1;
	if(x-1>=1&&1==getcost(x-1,y))dfs1(x-1,y);
	if(y-1>=1&&1==getcost(x,y-1))dfs1(x,y-1);
}
int main() {
	read(n);read(m);int tot=0;
	rep(i,1,n){
		static char t[N];
		scanf("%s",t+1);
		rep(j,1,m)S[++tot]=t[j];
	}
	dfs(1,1);dfs1(n,m);
	if(!vis[getdy(n,m)]){puts("0");return 0;}
	rep(i,1,n)rep(j,1,m)cnt[i+j]+=vis[getdy(i,j)]&&vis1[getdy(i,j)];
	rep(i,3,n+m-1)if(cnt[i]==1){puts("1");return 0;}
	cout<<2;
	return 0;
}