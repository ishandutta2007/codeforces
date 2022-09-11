#include<stdio.h>
main(){
    int w,h,an1=0,an2=0,i,k;
    scanf("%d%d",&w,&h);
    for(i=1;i<=w;i<<=1){
        if(i>2)k=i/4*5;
        else k=i;
        if(h>=k){
            an1=i;
            an2=k;
        }
        else{
            if(h>=i*0.8-1e-9){
                an1=i;
                an2=h;
            }
        }
    }
    for(i=1;i<=h;i<<=1){
        if(i>2)k=i/4*5;
        else k=i;
        if(w>=k){
            if((long long)an1*an2<(long long)k*i||((long long)an1*an2==(long long)k*i&&an1<k)){
                an1=k;
                an2=i;
            }
        }
        else{
            if(w>=i*0.8-1e-9&&(long long)an1*an2<=(long long)w*i){
                an1=w;
                an2=i;
            }
        }
    }
    printf("%d %d\n",an1,an2);
}