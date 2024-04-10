#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
struct dot{
	double x,y;dot(double X=0,double Y=0){x=X;y=Y;}
	void r(){scanf("%lf%lf",&x,&y);}
}s,t;
double a,b,c;
vector<dot>x,y;
double Abs(double x){return x>=0?x:-x;}
void qaq(dot p, vector<dot>&t){
	if(Abs(b)>0.5)t.pb(dot(p.x,(-c-a*p.x)/b));
	if(Abs(a)>0.5)t.pb(dot((-c-b*p.y)/a,p.y));
}
double getdis(dot a, dot b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
int main() {
	scanf("%lf%lf%lf",&a,&b,&c);
	s.r();t.r();
	double res=Abs(s.x-t.x)+Abs(s.y-t.y);
	qaq(s,x);qaq(t,y);
	rep(i,0,SZ(x)-1)rep(j,0,SZ(y)-1)
		res=min(res,getdis(x[i],y[j])+getdis(s,x[i])+getdis(y[j],t));
	printf("%.9lf",res);
	return 0;
}