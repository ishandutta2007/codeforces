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
int n,m,p[N],s[N],b[N],inc[N],pref[N],ans[N];
int x[N],y[N],c[N],d[N],sz,v[N];
inline void modify(int p, int x){while(p)v[p]+=x,p-=p&-p;}
inline int query(int p){int r=0;while(p<=sz)r+=v[p],p+=p&-p;return r;}
struct dot{
	int x,y,idx;
}a[N];
bool cmp(const dot &a,const dot &b){return a.x!=b.x?a.x>b.x:a.idx<b.idx;}
void solve(int tp){
	int len=0;
	rep(i,1,n)a[i].x=c[i],a[i].y=d[i],a[i].idx=0;len=n;
	rep(i,1,m)len++,a[len].x=x[i],a[len].y=y[i],a[len].idx=i;
	sort(a+1,a+len+1,cmp);
	static int s[N];rep(i,1,len)s[i]=a[i].y;
	sort(s+1,s+len+1);rep(i,1,len)a[i].y=lower_bound(s+1,s+len+1,a[i].y)-s;
	sz=len;memset(v,0,sizeof(v));
	rep(i,1,len){
		if(!a[i].idx)modify(a[i].y,tp);
		else ans[a[i].idx]+=query(a[i].y);
	}
}
int main() {
	read(n);read(m);
	rep(i,1,n)read(p[i]);
	rep(i,1,n)read(s[i]);
	rep(i,1,n)read(b[i]);
	rep(i,1,m)read(inc[i]);
	rep(i,1,m)read(pref[i]);
	//(pref,inc)
	
	rep(i,1,n)c[i]=s[i],d[i]=b[i]-p[i];
	rep(i,1,m)x[i]=inc[i],y[i]=pref[i]-inc[i];
	solve(1);
	
	rep(i,1,n)c[i]=s[i],d[i]=b[i]+p[i]-1;
	rep(i,1,m)x[i]=inc[i],y[i]=pref[i]+inc[i];
	solve(-1);
	
	rep(i,1,n)c[i]=b[i]+p[i]-1,d[i]=-(b[i]-p[i]+1);
	rep(i,1,m)x[i]=inc[i]+pref[i],y[i]=inc[i]-pref[i];
	solve(1);
	rep(i,1,m)printf("%d ",ans[i]);
	return 0;
}