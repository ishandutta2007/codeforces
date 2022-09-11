#include<stdio.h>
int max(int x,int y){return x>y?x:y;}
main(){
    int a[3],i,an=0;
    for(i=0;i<3;i++)scanf("%d",&a[i]);
    for(i=0;i<3;i++){
        an=max(an,(a[i]+1)/2*3-3+i);
    }
    printf("%d\n",an+30);
}