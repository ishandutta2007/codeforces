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
typedef vector<double> Vd;
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
int n,m;
struct yzr{
	double p[3333],val,qz[3333];
	vector<Vd>f;
	void init(){
		rep(i,1,n)p[i]/=1000;
		f.resize(1);f[0].resize(n+1);//0..n
		f[0][0]=1;rep(i,1,n)f[0][i]=f[0][i-1]*(1-p[i]);
		qz[0]=f[0][n];val=1-qz[0];
	}
	void upd(){
		f.pb(Vd());int j=SZ(f)-1;f[j].resize(n+1);
		f[j][0]=0;rep(i,1,n)f[j][i]=f[j-1][i-1]*p[i]+f[j][i-1]*(1-p[i]);
		qz[j]=qz[j-1]+f[j][n];val=1-qz[j];
	}
}a[303];
typedef pair<double,int> Pdi;
priority_queue<Pdi>heap;
int main() {
	read(n);read(m);
	rep(i,1,n)rep(j,1,m){int x;read(x);a[j].p[i]=x;}
	rep(i,1,m)a[i].init(),heap.push(Pdi(a[i].val,i));
	double res=0;
	rep(i,1,n){
		Pdi tmp=heap.top();heap.pop();res+=tmp.fi;
		a[tmp.se].upd();heap.push(Pdi(a[tmp.se].val,tmp.se));
	}
	printf("%.9lf",res);
	return 0;
}