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
int n,m,dis[N],q[N],k,a[N],buc[N];Vi e[N];
int main() {
	read(n);read(m);
	rep(i,1,m){
		int u,v;read(u);read(v);e[v].pb(u);
	}
	read(k);rep(i,1,k)read(a[i]);
	int f=0,r=1;q[f]=a[k];
	rep(i,1,n)dis[i]=inf;dis[q[f]]=0;
	while(f!=r){
		int u=q[f++];
		for(int v:e[u])if(dis[v]>dis[u]+1)
			dis[v]=dis[u]+1,q[r++]=v;
	}
	rep(u,1,n)for(int v:e[u])if(dis[v]==dis[u]+1)buc[v]++;
	int ans1=0,ans2=0;
	rep(i,1,k-1)ans1+=dis[a[i]]!=dis[a[i+1]]+1,ans2+=dis[a[i]]!=dis[a[i+1]]+1||buc[a[i]]>1;
	printf("%d %d",ans1,ans2);
	return 0;
}