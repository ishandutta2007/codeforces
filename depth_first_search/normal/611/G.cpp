#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
#define X 1000000007
#define LL long long
#define ull unsigned long long
using namespace std;
int n;struct P
{
	int x,y;I P(CI a=0,CI b=0):x(a),y(b){}
	I P operator - (Con P& o) Con {return P(x-o.x,y-o.y);}
}p[2*N+5];
struct MP
{
	int x,y;I MP(CI a=0,CI b=0):x(a),y(b){}I MP(Con P& p):x((p.x%X+X)%X),y((p.y%X+X)%X){} 
	I void operator += (Con MP& o) {x=(x+o.x)%X,y=(y+o.y)%X;}
	I void operator -= (Con MP& o) {x=(x-o.x+X)%X,y=(y-o.y+X)%X;}
	I MP operator * (CI o) Con {return MP(1LL*x*o%X,1LL*y*o%X);}
};
I ull S (Con P& A,Con P& B) {return abs(1LL*A.x*B.y-1LL*A.y*B.x);}
I int S (Con MP& A,Con MP& B) {return (1LL*A.x*B.y-1LL*A.y*B.x%X+X)%X;}
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define D isdigit(oc=tc())
	int Ff;char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0,Ff=1;W(!D) Ff=oc^'-'?1:-1;W(x=(x<<3)+(x<<1)+(oc&15),D);x*=Ff;}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int main()
{
	RI i,j;for(read(n),i=1;i<=n;++i) read(p[i].x,p[i].y),p[n+i]=p[i];
	ull s=0;for(i=2;i^n;++i) s+=S(p[i]-p[1],p[i+1]-p[1]);
	RI c=0,w=0,t=0;ull f=0,g;MP sp;for(i=j=1;i<=n;++i)
	{
		W(1) if(2*(f+(g=S(p[j]-p[i],p[j+1]-p[i])))<s) w=(w+(f+=g))%X,sp+=p[++j]-p[i];else {2*(f+g)==s&&++c;break;}
		t=(t+w)%X,f-=S(p[j]-p[i],p[j]-p[i+1]),w=(w-S(sp,p[i+1]-p[i])+X)%X,sp-=MP(p[i+1]-p[i])*(j-i);
	}return printf("%d\n",((1LL*n*(n-3)-c)/2%X*(s%X)-2*t+2*X)%X),0;
}