#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define SZ(x) ((int)x.size())
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
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
const int N = 3030, mo = 1e9+7;
int n,D,fa[N],f[N][N],y[N],Inv[N]; Vi e[N];
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void dfs(int u){
	rep(i,1,n+1)f[u][i]=1;
	per(i,SZ(e[u])-1,0){
		dfs(e[u][i]);int v=e[u][i];
		for(int j=1,now=0;j<=n+1;j++){
			add(now,f[v][j]);f[u][j]=1LL*f[u][j]*now%mo;
		}
	}
}
inline void exgcd(int a, int b, int &x, int &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);y-=a/b*x;
}
inline int inv(int a){int x,y;exgcd(a,mo,x,y);return x>=0?x:x+mo;}
inline int F(int x, int k){ //f(x) with k dots
	int res=0;rep(i,0,k)Inv[i]=inv(i);
	rep(i,1,k){
		int now=y[i];rep(j,1,k)if(j!=i)now=1LL*now*(j-x)%mo*(j-i>0?Inv[j-i]:-Inv[i-j])%mo;
		res+=now;res%=mo;
	}
	return (res+mo)%mo;
}
int main() {
	read(n);read(D);rep(i,2,n)read(fa[i]),e[fa[i]].push_back(i);
	dfs(1); for (int i=1;i<=n+1;i++)y[i]=y[i-1],add(y[i],f[1][i]);
//	rep(i,1,n+1)printf("%d\n",y[i]);
	cout<<F(D,n+1);
	return 0;
}