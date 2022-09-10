#include<stdio.h>
#include<math.h>
#define sqr(x) ((x)*(x))
#define SIZE 10000
double x[SIZE],y[SIZE],z[SIZE];
main(){
    double tmp,mi,ma,xx,yy,zz,q;
    int n,i,j,k;
    while(scanf("%d",&n)==1){
        xx=yy=zz=0;
        q=0.1;
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
            xx+=x[i];
            yy+=y[i];
            zz+=z[i];
        }
        xx/=n;
        yy/=n;
        zz/=n;
        for(i=0;i<20000;i++){
            ma=-1;
            for(j=0;j<n;j++)
                if((tmp=sqr(x[j]-xx)+sqr(y[j]-yy)+sqr(z[j]-zz))>ma){
                    ma=tmp;
                    k=j;
                }
            xx+=(x[k]-xx)*q;
            yy+=(y[k]-yy)*q;
            zz+=(z[k]-zz)*q;
            q*=0.9993;
        }
        printf("%.8lf %.8lf %.8lf\n",xx,yy,zz);
    }
}