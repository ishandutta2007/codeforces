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
const int N = 666666,inf=0x3f3f3f3f;
int n,m,k,a[N],d1[N],d2[N];Vi e[N];
void bfs(int s, int *dis){
	rep(i,1,n)dis[i]=inf;dis[s]=0;
	static int q[N];int f=0,r=1;q[f]=s;
	while(f!=r){
		int u=q[f++];
		for(int v:e[u])if(dis[v]>dis[u]+1){
			dis[v]=dis[u]+1;q[r++]=v;
		}
	}
}
bool cmp(int x, int y){return d1[x]-d2[x]<d1[y]-d2[y];}
int main() {
	read(n);read(m);read(k);
	rep(i,1,k)read(a[i]);
	rep(i,1,m){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	bfs(1,d1);bfs(n,d2);
	int ori=d1[n],mx=0;
	sort(a+1,a+k+1,cmp);
	for(int i=1,j=0;i<=k;i++){
	//	printf("qwq %d %d\n",d2[a[i]],j);
		if(i>1)umax(mx,1+d2[a[i]]+j);umax(j,d1[a[i]]);
	}
	cout<<min(ori,mx);
	return 0;
}