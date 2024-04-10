#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define V 100000
#define DB double
using namespace std;
int n,cnt;struct P
{
	DB x,y;I P(Con DB& a=0,Con DB& b=0):x(a),y(b){}
	I P operator + (Con P& o) Con {return P(x+o.x,y+o.y);}
	I P operator - (Con P& o) Con {return P(x-o.x,y-o.y);}
	I P operator * (Con DB& o) Con {return P(x*o,y*o);}
	I P operator / (Con DB& o) Con {return P(x/o,y/o);}
	I DB operator * (Con P& o) Con {return x*o.x+y*o.y;}
	I DB operator ^ (Con P& o) Con {return x*o.y-y*o.x;}
	I bool operator < (Con P& o) Con {return x!=o.x?x<o.x:y<o.y;} 
	I bool operator == (Con P& o) Con {return x==o.x&&y==o.y;} 
	I DB L() {return sqrt((*this)*(*this));}
	I P Ro(Con DB& g) {return P(x*cos(g)-y*sin(g),x*sin(g)+y*cos(g));}
}p[8*N+5];
int T;P s[8*N+5];I void Get()
{
	#define pd(A,B,C) (((C-B)^(B-A))>0||(((C-B)^(B-A))==0&&(A<B)==(B<C)))
	RI i;sort(p+1,p+cnt+1),cnt=unique(p+1,p+cnt+1)-p-1;
	for(sort(p+1,p+cnt+1),i=1;i<=cnt;s[++T]=p[i++]) W(T>1&&pd(s[T-1],s[T],p[i])) --T;
	for(i=cnt-1;i;s[++T]=p[i--]) W(T>1&&pd(s[T-1],s[T],p[i])) --T;--T;
}
struct S {P A,B;I S(Con P& a=P(),Con P& b=P()):A(a),B(b){}};
I S MidVer(Con P& A,Con P& B) {P mid=(A+B)/2,t=B-mid;return S(mid,mid+P(t.y,-t.x));}
I DB Calc(Con P& A,Con P& B,Con P& C)
{
	S S1=MidVer(A,B),S2=MidVer(A,C);DB w1=(S1.A-S2.A)^(S2.B-S2.A),w2=(S2.B-S2.A)^(S1.B-S2.A);
	P O=S1.A+(S1.B-S1.A)*w1/(w1+w2);return (A-O).L();
}
int main()
{
	RI i,x,y,z;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d%d%d",&x,&y,&z),
		x+z<=V?p[++cnt]=P(x+z,y):(p[++cnt]=P(V,min(y+z-(V-x),V)),p[++cnt]=P(V,max(y-z+(V-x),0))),
		y+z<=V?p[++cnt]=P(x,y+z):(p[++cnt]=P(min(x+z-(V-y),V),V),p[++cnt]=P(max(x-z+(V-y),0),V)),
		x-z>=0?p[++cnt]=P(x-z,y):(p[++cnt]=P(0,min(y+z-x,V)),p[++cnt]=P(0,max(y-z+x,0))),
		y-z>=0?p[++cnt]=P(x,y-z):(p[++cnt]=P(min(x+z-y,V),0),p[++cnt]=P(max(x-z+y,0),0));
	RI t;DB f,g=0;for(Get(),s[T+1]=s[1],s[T+2]=s[2],i=1;i<=T;++i) (f=Calc(s[i],s[i+1],s[i+2]))>g&&(g=f,t=i);
	return printf("%.0lf %.0lf\n%.0lf %.0lf\n%.0lf %.0lf\n",s[t].x,s[t].y,s[t+1].x,s[t+1].y,s[t+2].x,s[t+2].y),0;
}