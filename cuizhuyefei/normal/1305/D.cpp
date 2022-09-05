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
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int n,d[N];Vi e[N];bool c[N];
int sta[N],top;
void find(int x){printf("! %d\n",x);fflush(stdout);exit(0);}
int main() {
	read(n);rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	rep(i,1,n){d[i]=SZ(e[i]);if(d[i]==1)sta[++top]=i;}
	while(top>=2){
		int u=sta[top--];int v=sta[top--];c[u]=c[v]=1;
		printf("? %d %d\n",u,v);fflush(stdout);int x;read(x);
		if(x==u)find(u);
		if(x==v)find(v);
		for(int x:e[u])--d[x];
		for(int x:e[v])--d[x];
		Vi s;for(int x:e[u])if(d[x]==1)s.pb(x);
		for(int x:e[v])if(d[x]==1)s.pb(x);
		sort(ALL(s));s.erase(unique(ALL(s)),s.end());
		for(int x:s)sta[++top]=x;
	}
	rep(i,1,n)if(!c[i])find(i);
//	find(sta[1]);
	return 0;
}