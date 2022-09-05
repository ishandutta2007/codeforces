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
const int N = 1<<12|3;
int k,n,a[N],p[N],q[N];
int main() {
	read(k);n=1<<k;int s=0;
	rep(i,0,n-1)read(a[i]),s^=a[i],p[i]=q[i]=-1;
	if(s){puts("Fou");return 0;}
	while(1){
		static int pval[N],qpos[N];
		rep(i,0,n-1)pval[i]=0,qpos[i]=-1;
		rep(i,0,n-1)if(p[i]!=-1)pval[p[i]]=1;
		rep(i,0,n-1)if(q[i]!=-1)qpos[q[i]]=i;
		static int sp[N],val[N];int sz=0;
		rep(i,0,n-1)if(p[i]==-1)sp[sz++]=i;
		sz=0;rep(i,0,n-1)if(!pval[i])val[sz++]=i;
		if(!sz)break;
		int x=sp[R()%sz];
//		cerr<<sz<<endl;
//		rep(i,0,n-1)printf("%d ",p[i]);puts("");
//		rep(i,0,n-1)printf("%d ",q[i]);puts("");
		rep(i,0,sz-1)if(qpos[a[x]^val[i]]==-1){
			p[x]=val[i];q[x]=a[x]^val[i];
			break;
		}
		if(p[x]==-1){
			p[x]=val[R()%sz];q[x]=a[x]^p[x];
			int y=qpos[q[x]];assert(q[y]==q[x]);q[y]=p[y]=-1;
		}
	}
	puts("Shi");
	rep(i,0,n-1)printf("%d ",p[i]);puts("");
	rep(i,0,n-1)printf("%d ",q[i]);puts("");
	return 0;
}