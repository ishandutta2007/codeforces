#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 366666;
int n,m,A[N],B[N],gg[N],ans[N],res;Vi e[N];
void solve(){
	static int sta[N],deg[N];int top=0;
	memset(deg,0,sizeof(deg));rep(u,1,n)for(int v:e[u])deg[v]++;
	rep(i,1,n)if(!deg[i])sta[++top]=i;int lst=n,front=1;
	while(front<=top){
		int u=sta[front++];lst--;
		if(top-front+1>=2)gg[u]=1;
		else if(top-front+1==0)ans[u]+=lst;
		else{ans[u]+=lst-1;for(int v:e[sta[front]])if(deg[v]==1)gg[u]=1;}//ans[u]-=deg[v]==1;}
		for(int v:e[u])if(!--deg[v])sta[++top]=v;
	}
}
int main() {
	read(n);read(m);
	rep(i,1,m)read(A[i]),read(B[i]);
	rep(i,1,m)e[A[i]].pb(B[i]);
	solve();
	rep(i,1,n)e[i].clear();
	rep(i,1,m)e[B[i]].pb(A[i]);
	solve();
	rep(i,1,n)res+=!gg[i]&&ans[i]>=n-2;//,printf("%d:%d %d\n",i,gg[i],ans[i]);
	cout<<res;
	return 0;
}