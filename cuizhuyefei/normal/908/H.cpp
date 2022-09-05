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
const int N = 55, mo = 1e9+9;
int n,fa[N],sz[N];char t[N][N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x, int y){
	x=find(x);y=find(y);if(x!=y){fa[x]=y;sz[y]+=sz[x];}
}
int len,e[N][N],bh[N],f[1<<23|3],g[1<<23|3],cnt[1<<23|3],dy[1<<23|3];
inline int A(int x){return x<mo?x:x-mo;}
inline int solve(int n){
	if(!n)return 0;int all=(1<<n)-1;rep(i,0,n)dy[1<<i]=i;
	//rep(i,1,n){rep(j,1,n)printf("%d",e[i][j]);puts("");}
	f[0]=1;rep(i,1,all){
		int bit=i&-i;f[i]=f[i^bit];int u=dy[bit]+1;
		rep(j,1,n)if(i>>j-1&1)f[i]&=!e[u][j];
	}
	//rep(i,0,all)printf("%d:%d\n",i,f[i]);
	rep(j,0,n-1)rep(s,0,all)f[s]=s>>j&1?A(f[s]+f[s^(1<<j)]):f[s];
	//rep(i,0,all)printf("%d:%d\n",i,f[i]);
	rep(i,0,all)g[i]=1;rep(i,1,all)cnt[i]=cnt[i>>1]+(i&1);
	rep(t,1,n){
		rep(i,0,all)g[i]=1LL*g[i]*f[i]%mo;
		int r=0;rep(i,0,all)r=A(r+((n-cnt[i]&1)?mo-g[i]:g[i]));
		if(r)return t;
	}
	return 6666;
}
int main() {
	read(n);rep(i,1,n)scanf("%s",t[i]+1);
	rep(i,1,n)fa[i]=i,sz[i]=1;
	rep(i,1,n)rep(j,1,n)if(t[i][j]=='A')merge(i,j);
	rep(i,1,n)rep(j,1,n)if(t[i][j]=='X')if(find(i)==find(j)){puts("-1");return 0;}
	rep(i,1,n)if(find(i)==i&&sz[i]>1)len++,bh[i]=len;
	rep(i,1,n)rep(j,1,n)if(t[i][j]=='X')e[bh[find(i)]][bh[find(j)]]=1;//WA 
	cout<<n-1+solve(len);
	return 0;
}