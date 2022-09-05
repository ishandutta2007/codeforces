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
const int N = 202000;
int n,e[N][2],top,sz[N],sta[N];
void dfs(int u){
	while(sz[u]){        
		int k=sz[u]-1,v=e[u][sz[u]-1];sz[u]--;dfs(v);
	//	sta[++top]=Pii(u,v);
		sta[++top]=2*u+k;
	}
}
int main() {
	read(n);if(n&1){puts("-1");return 0;}
	rep(i,0,n/2-1)e[i][0]=2*i*2/2%(n/2),e[i][1]=(2*i+1)*2/2%(n/2),sz[i]=2;
//	rep(i,0,n/2-1)printf("%d:%d %d\n",i,e[i][0],e[i][1]);
	dfs(0);sta[++top]=0;
	per(i,top,1)printf("%d ",sta[i]);
	return 0;
}