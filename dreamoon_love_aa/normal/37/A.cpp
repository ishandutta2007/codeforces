#include<stdio.h>
int d[1010];
main(){
    int n,x,an1=0,an2=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        d[x]++;
    }
    for(x=1;x<=1000;x++){
        if(d[x]>an1)an1=d[x];
        if(d[x])an2++;
    }
    printf("%d %d\n",an1,an2);
}