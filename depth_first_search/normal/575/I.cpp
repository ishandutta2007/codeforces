#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 5000
#define M 100000
using namespace std;
int n,Qt,ans[M+5];struct OP {int op,x,y,d,l;}q[M+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
struct TreeArray
{
	int a[2*N+5];I void Cl() {for(RI i=0;i<=2*n;++i) a[i]=0;}
	I void U_(RI x,CI v) {W(x<=2*n) a[x]+=v,x+=x&-x;}I int Q(RI x,RI t=0) {W(x) t+=a[x],x-=x&-x;return t;}
	I void U(CI x,CI y) {U_(x,1),U_(y+1,-1);}
}T;
struct TreeArray2
{
	int a[2*N+5][N+5];I void Cl() {for(RI i=0;i<=2*n;++i) for(RI j=0;j<=n;++j) a[i][j]=0;}
	I void U1(int* a,RI x,RI v) {W(x) a[x]+=v,x-=x&-x;}
	I void U2(RI x,CI y,CI v) {W(x<=2*n) U1(a[x],y,v),x+=x&-x;}
	I void U(CI x1,CI x2,CI y) {U2(x1,y,1),U2(x2+1,y,-1);}
	I int Q(int* a,RI x,RI t=0) {W(x<=n) t+=a[x],x+=x&-x;return t;}
	I int Q(RI x,CI y,RI t=0) {W(x) t+=Q(a[x],y),x-=x&-x;return t;}
}X,Y;
int main()
{
	RI i;for(read(n,Qt),i=1;i<=Qt;++i) read(q[i].op),
		q[i].op==1?(read(q[i].d,q[i].x,q[i].y,q[i].l),q[i].d>2&&(q[i].d=7-q[i].d)):(read(q[i].x,q[i].y),0);
	for(RI D=1,l,r;D<=4;++D) for(T.Cl(),X.Cl(),Y.Cl(),i=1;i<=Qt;swap(q[i].x,q[i].y),q[i].x=n-q[i].x+1,++i)
		q[i].op==1&&q[i].d==D&&(T.U(l=q[i].x+q[i].y,r=q[i].x+q[i].y+q[i].l),X.U(l,r,q[i].x-1),Y.U(l,r,q[i].y-1),0),
		q[i].op==2&&(ans[i]+=T.Q(q[i].x+q[i].y)-X.Q(q[i].x+q[i].y,q[i].x)-Y.Q(q[i].x+q[i].y,q[i].y));
	for(i=1;i<=Qt;++i) q[i].op==2&&(writeln(ans[i]),0);return clear(),0;
}