#include<stdio.h>
int To(int x){
    int an=0,d[12],i=0;
    while(x){
        d[i++]=x&1;
        x>>=1;
    }
    for(i--;i>=0;i--){
        an*=10;
        if(d[i])an++;
    }
    return an;
}
main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;;i++)
        if(To(i+1)>n)break;
    printf("%d\n",i);
}