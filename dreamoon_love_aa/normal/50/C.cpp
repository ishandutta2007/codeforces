#include<stdio.h>
#define MAX 200000000
main(){
    int x,y,N,mi_x=MAX,mi_y=MAX,ma_x=-MAX,ma_y=-MAX;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d",&x,&y);
        if(x+y>ma_x)ma_x=x+y;
        if(x+y<mi_x)mi_x=x+y;
        if(x-y>ma_y)ma_y=x-y;
        if(x-y<mi_y)mi_y=x-y;
    }
    printf("%d\n",(ma_x-mi_x+4+ma_y-mi_y));
}