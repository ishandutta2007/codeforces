#include<stdio.h>
#include<math.h>
#define Err 1e-12
struct Point{
    double x,y,z;
    void scan(){scanf("%lf%lf%lf",&x,&y,&z);}
    bool operator==(Point b)const{return fabs(x-b.x)<Err&&fabs(y-b.y)<Err&&fabs(z-b.z)<Err;}
    Point operator*(double v){return (Point){x*v,y*v,z*v};}
    Point operator-(Point b){return (Point){x-b.x,y-b.y,z-b.z};}
    Point operator+(Point b){return (Point){x+b.x,y+b.y,z+b.z};}
}p[10001],Harry;
double vp,vs;
double sqr(double x){return x*x;}
double Dis(Point X,Point Y){
    return sqrt(sqr(X.x-Y.x)+sqr(X.y-Y.y)+sqr(X.z-Y.z));
}
bool f(double now,int x){
    if(now+Dis(p[x],p[x+1])/vs+Err<Dis(Harry,p[x+1])/vp)return 0;
    double left=0,right=1,mid;
    Point tmp;
    while(left+Err<right){
        mid=(left+right)/2;
        tmp=p[x]+(p[x+1]-p[x])*mid;
        if(now+Dis(tmp,p[x])/vs<Dis(Harry,tmp)/vp)left=mid;
        else right=mid;
    }
    puts("YES");
    printf("%.9lf\n",Dis(tmp,Harry)/vp);
    printf("%.9lf %.9lf %.9lf\n",tmp.x,tmp.y,tmp.z);
    return 1;
}
main(){
    int n,i,j;
    double now=0;
    scanf("%d",&n);
    for(i=0;i<=n;i++)p[i].scan();
    scanf("%lf%lf",&vp,&vs);
    Harry.scan();
    if(Harry==p[0]){
        puts("YES\n0.000000000");
        printf("%.9lf %.9lf %.9lf\n",p[0].x,p[0].y,p[0].z);
    }
    else{
        for(i=0;i<n;i++){
            if(f(now,i))break;
            now+=Dis(p[i],p[i+1])/vs;
        }
        if(i==n)puts("NO");
    }
}