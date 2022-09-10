#include<stdio.h>
int main(){
    int n,m,h,x,sum=0,my,i;
    scanf("%d%d%d",&n,&m,&h);
    for(i=1;i<=m;i++){
        scanf("%d",&x);
        if(i==h)my=x;
        sum+=x;
    }
    if(sum<n){
        puts("-1");
        return 0;
    }
    my--;
    sum--;
    n--;
    if(n==0||my==0){
        puts("0");
        return 0;
    }
    if(sum-my<n){
        puts("1");
        return 0;
    }
    double an=1;
    for(i=0;i<n;i++){
        an*=sum-my-i;
        an/=sum-i;
    }
    printf("%.12lf\n",1-an);

    return 0;
}