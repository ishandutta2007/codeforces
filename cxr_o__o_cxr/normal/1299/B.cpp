//starusc
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cassert>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
struct poin{
	double x,y;
	poin(double xx=0,double yy=0):x(xx),y(yy){}
	inline poin operator +(const poin &a)const{
		return poin(x+a.x,y+a.y);
	}
	inline poin operator -(const poin &a)const{
		return poin(x-a.x,y-a.y);
	}
	inline poin operator *(double a)const{
		return poin(x*a,y*a);
	}
	inline poin operator /(double a)const{
		return poin(x/a,y/a);
	}
	inline double operator *(const poin &a)const{
		return x*a.y-y*a.x;
	}
	inline double operator ^(const poin &a)const{
		return x*a.x+y*a.y;
	}
};
const double eps=1e-8,pi=acos(-1.0);
inline int cmp(double x){
	if(fabs(x)<eps)return 0;
	return (x<0)?-1:1;
}
inline poin inters(poin xa,poin xb,poin ya,poin yb){
	double v=((ya-xa)*(xb-xa))/((xb-xa)*(yb-ya));
	return ya+(yb-ya)*v;
}
inline poin rotate(poin a,double th){
	return poin(a.x*cos(th)-a.y*sin(th),a.x*sin(th)+a.y*cos(th));
}
inline double distan(const poin &a){
	return sqrt(a.x*a.x+a.y*a.y);
}
const int N=1e5+4;
poin p[N],o;
int main(){
	int n=read();
	if(n&1){puts("NO");return (0-0);}
	for(int i=1;i<=n;i++){
		p[i].x=read();p[i].y=read();
	}
	n/=2;
	o=(p[1]+p[n+1])/2;
	for(int i=1;i<=(n<<1);i++)p[i]=p[i]-o;
	for(int i=1;i<=n;i++)
		if(cmp(((p[i]+p[i+n])/2).x)||cmp(((p[i]+p[i+n])/2).y)){puts("NO");return (0-0);}
	puts("YES");
	return (0-0);
}