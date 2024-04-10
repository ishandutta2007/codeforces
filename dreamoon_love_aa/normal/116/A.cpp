#include<stdio.h>
main(){
    int n,an=0,now=0;
    scanf("%d",&n);
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        now+=y-x;
        if(now>an)an=now;
    }
    printf("%d\n",an);
}