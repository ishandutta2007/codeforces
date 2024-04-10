#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef pair<db,db> pts;
#define mkp make_pair
#define fi first
#define se second
const db EPS=1e-2,pi=acos(-1);
pts a,b,c;
db la,lb,lc;
db dis(pts A,pts B){
	return sqrt((A.fi-B.fi)*(A.fi-B.fi)+(A.se-B.se)*(A.se-B.se));
}
double gcd(db a,db b){
    if(fabs(b)<EPS)return a;
 	if(fabs(a)<EPS)return b;
    return gcd(b,fmod(a,b));
}
double Acos(db a){
	if(fabs(a)>1.0){
		if(a<0)a=-2-a;
		if(a>0)a=2-a;
	}
	return acos(a);
}
int main(){
	scanf("%lf%lf",&a.fi,&a.se);
	scanf("%lf%lf",&b.fi,&b.se);
	scanf("%lf%lf",&c.fi,&c.se);
	la=dis(b,c),lb=dis(a,c),lc=dis(a,b);
	db p=(la+lb+lc)*0.5;
	db areas=sqrt(p*(p-la)*(p-lb)*(p-lc));
	db R=la*lb*lc/areas*0.25;
	db cos1=Acos(1-la*la/(2*R*R)),cos2=Acos(1-lb*lb/(2*R*R));
	db cos3=2*pi-cos1-cos2;
	db t=gcd(gcd(cos1,cos2),cos3);
	printf("%.6lf",(pi*R*R*sin(t))/t);
}