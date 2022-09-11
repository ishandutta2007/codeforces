#include<math.h>
#include<stdio.h>
int a[128];
#define Err 1e-9
long long sqr(long long x){return x*x;}
main(){
    int n,vb,vs,i,j,x,y,an,an2;
    double tmp,mi=1e12;
    scanf("%d%d%d",&n,&vb,&vs);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d%d",&x,&y);
    for(i=1;i<n;i++){
        tmp=(double)a[i]/vb+sqrt(sqr(x-a[i])+(long long)y*y)/vs;
        if(fabs(tmp-mi)>Err&&tmp<mi){
            mi=tmp;
            an=i+1;
            an2=sqr(y)+sqr(x-a[i]);
        }
        else if(fabs(tmp-mi)<Err&&an2>sqr(y)+sqr(x-a[i])){
            an=i+1;
            an2=sqr(y)+sqr(x-a[i]);
        }
    }
    printf("%d\n",an);
}