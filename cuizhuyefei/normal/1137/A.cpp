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
const int N = 1020;
int n,m,a[N][N];
struct QQ{
	int s[N],n;
	void init(int *a, int nn){
		n=nn;rep(i,1,n)s[i]=a[i];
		sort(s+1,s+n+1);n=unique(s+1,s+n+1)-s-1;
	}
	int q(int x){return lower_bound(s+1,s+n+1,x)-s;}
	int query1(int x){return q(x)-1;}
	int query2(int x){return n-q(x);}
}l[N],r[N];
int main() {
	read(n);read(m);rep(i,1,n)rep(j,1,m)read(a[i][j]);
	static int s[N];
	rep(i,1,n){
		rep(j,1,m)s[j]=a[i][j];
		l[i].init(s,m);
	}
	rep(j,1,m){
		rep(i,1,n)s[i]=a[i][j];
		r[j].init(s,n);
	}
	rep(i,1,n){
		rep(j,1,m){
			printf("%d ",1+max(l[i].query1(a[i][j]),r[j].query1(a[i][j]))+max(l[i].query2(a[i][j]),r[j].query2(a[i][j])));
		}
		puts("");
	}
	return 0;
}