#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define Err 1e-9
double an[12];
struct Ball{
    double x,v,m;
    int No;
    void scan(){scanf("%lf%lf%lf",&x,&v,&m);}
    bool operator<(Ball b)const{return x<b.x;}
}a[12];
void tran(Ball X,Ball Y,double &v1,double &v2){
    v1=((X.m-Y.m)*X.v+2*Y.m*Y.v)/(X.m+Y.m);
    v2=((Y.m-X.m)*Y.v+2*X.m*X.v)/(X.m+Y.m);
}
main(){
    int n,t,i,ball;
    scanf("%d%d",&n,&t);
    for(i=0;i<n;i++)a[i].scan(),a[i].No=i;
    sort(a,a+n);
    double now=0,first;
    while(1){
        first=t+Err;
        for(i=0;i<n;i++){
            if(a[i].v>0){
                if(i+1==n||a[i+1].v+Err>a[i].v)continue;
                if(now+(a[i+1].x-a[i].x)/(a[i].v-a[i+1].v)<first){
                    first=now+(a[i+1].x-a[i].x)/(a[i].v-a[i+1].v);
                    ball=i;
                }
            }
            else{
                if(i==0||a[i-1].v<a[i].v+Err)continue;
                if(now+(a[i].x-a[i-1].x)/(a[i-1].v-a[i].v)<first){
                    first=now+(a[i].x-a[i-1].x)/(a[i-1].v-a[i].v);
                    ball=i-1;
                }
            }
        }
        if(first<t){
            for(i=0;i<n;i++)
                a[i].x+=a[i].v*(first-now);
            tran(a[ball ],a[ball+1],a[ball].v,a[ball+1].v);
            now=first;
        }
        else break;
    }
    for(i=0;i<n;i++)
        a[i].x+=a[i].v*(t-now);
    for(i=0;i<n;i++)an[a[i].No]=a[i].x;
    for(i=0;i<n;i++)printf("%.8lf\n",an[i]);
}