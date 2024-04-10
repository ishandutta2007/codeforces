#include<stdio.h>
int an;
struct data{
    int x,y;
}a[110];
main(){
    int n,P[3],T[2],i;
    scanf("%d",&n);
    for(i=0;i<3;i++)scanf("%d",&P[i]);
    for(i=0;i<2;i++)scanf("%d",&T[i]);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        an+=(a[i].y-a[i].x)*P[0];
        if(i){
            if(a[i].x-a[i-1].y<=T[0])
                an+=(a[i].x-a[i-1].y)*P[0];
            else if(a[i].x-a[i-1].y<=T[1]+T[0])
                an+=T[0]*P[0]+(a[i].x-a[i-1].y-T[0])*P[1];
            else an+=T[0]*P[0]+T[1]*P[1]+(a[i].x-a[i-1].y-T[1]-T[0])*P[2];
        }
    }
    printf("%d\n",an);
}