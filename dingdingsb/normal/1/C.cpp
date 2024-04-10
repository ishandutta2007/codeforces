#include<cstdio>
#include<cmath>
const double Pi=acos(-1.0);        //
const double EPS=1E-2;            //
struct Point {
    double x,y;
}P[3];
double len[3],a[3];        //lena
double Get(int i,int j) {    //
    return sqrt((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y));
}
double gcd(double a,double b) {    //double
    if(fabs(b)<EPS)
        return a;
    if(fabs(a)<EPS)
        return b;
    return gcd(b,fmod(a,b));    //fmod(a,b), double
}
int main() {
    double t=0.0,A,r;
    for(int i=0;i<3;++i)
        scanf("%lf%lf",&P[i].x,&P[i].y);
    for(int i=0;i<3;t+=len[i],++i)
        len[i]=Get(i,(i+1)%3);
    t/=2;
    A=sqrt(t*(t-len[0])*(t-len[1])*(t-len[2]));    //
    r=len[0]*len[1]*len[2]/(4*A);                //
    for(int i=0;i<2;++i)
        a[i]=acos(1-len[i]*len[i]/(2*r*r));        //
    a[2]=2*Pi-a[0]-a[1];                        //360
    t=gcd(a[0],gcd(a[1],a[2]));                    //
    printf("%.6lf",(Pi*r*r*sin(t))/t);            //
    return 0;
}