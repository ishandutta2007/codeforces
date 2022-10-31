#include <cstdio>
#include <cstdlib>
#include <cmath>
double dis(double x, double y, double xx, double yy){
    return fabs(x/y - xx/yy);
}
double x,y,n,ax,ay,m=10e9;
void update(double xx, double yy){
    double d = dis(x,y,xx,yy);
    if(d<m){m=d, ax=xx, ay=yy;}
}
int main(){
    scanf("%lf%lf%lf", &x, &y, &n);
    for(int i = 1; i <= n; ++i){
        double tmp = i/y;
        double tx=x*tmp, ty=i;
        update(floor(tx),i);
        update(ceil(tx),i);
    }
    printf("%.0f/%.0f\n", ax, ay);
    return 0;
}