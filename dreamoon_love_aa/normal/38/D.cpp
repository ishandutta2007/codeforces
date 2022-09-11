#include<stdio.h>
#define Err 1e-12
struct Cube{
    int x[2],y[2];
    void scan(){
        scanf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);
        int tmp;
        if(x[0]>x[1]){
            tmp=x[0];
            x[0]=x[1];
            x[1]=tmp;
        }
        if(y[0]>y[1]){
            tmp=y[0];
            y[0]=y[1];
            y[1]=tmp;
        }
    }
}a[128];
double pow(double x,int y){
    double an=1;
    while(y){
        if(y&1)an*=x;
        x*=x;
        y>>=1;
    }
    return an;
}
main(){
    int n,i,j,an;
    double nowX,nowY,w;
    scanf("%d",&n);
    for(i=1;i<=n;i++)a[i].scan();
    an=n;
    for(i=1;i<=an;i++){
        nowX=0;
        nowY=0;
        w=0;
        for(j=i+1;j<=an;j++){
            nowX=((a[j].x[0]+a[j].x[1])*0.5*pow(a[j].x[1]-a[j].x[0],3)+nowX*w)/(pow(a[j].x[1]-a[j].x[0],3)+w);
            nowY=((a[j].y[0]+a[j].y[1])*0.5*pow(a[j].y[1]-a[j].y[0],3)+nowY*w)/(pow(a[j].y[1]-a[j].y[0],3)+w);
            w+=pow(a[j].x[1]-a[j].x[0],3);
            if(nowX+Err<a[i].x[0]||nowX>a[i].x[1]+Err)break;
            if(nowY+Err<a[i].y[0]||nowY>a[i].y[1]+Err)break;
        }
        an=j-1;
    }
    printf("%d\n",an);
}