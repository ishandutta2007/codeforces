#include<stdio.h>
int main(){
    int n,t,max=0;
    scanf("%d\n%d",&n,&t);
    if(t!=0) {printf("1");return 0;}
    for(int i=2;i<=n;i++){
        scanf("%d",&t);
        if(t>max+1){printf("%d",i);return 0;}
        if(t>max)max=t;
    }
    printf("-1");
}