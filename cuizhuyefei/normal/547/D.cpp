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
const int N = 266666;
int n,a[N];Vi e[N];
struct dot{
	int x,y,idx;
}s[N];
bool cmp1(dot a, dot b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
bool cmp2(dot a, dot b){return a.y!=b.y?a.y<b.y:a.x<b.x;}
void dfs(int u, int c){
	a[u]=c;rep(i,0,SZ(e[u])-1)if(a[e[u][i]]==-1)
		dfs(e[u][i],c^1);
}
int main() {
	read(n);memset(a,-1,sizeof(a));
	rep(i,1,n)read(s[i].x),read(s[i].y),s[i].idx=i;
	sort(s+1,s+n+1,cmp1);
	rep(i,1,n)if(s[i].x==s[i+1].x)
		e[s[i].idx].pb(s[i+1].idx),e[s[i+1].idx].pb(s[i].idx),i++;
	sort(s+1,s+n+1,cmp2);
	rep(i,1,n)if(s[i].y==s[i+1].y)
		e[s[i].idx].pb(s[i+1].idx),e[s[i+1].idx].pb(s[i].idx),i++;
	rep(i,1,n)if(a[i]==-1)dfs(i,0);
	rep(i,1,n)printf("%c",a[i]?'b':'r');
	return 0;
}