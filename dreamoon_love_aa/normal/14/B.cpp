#include<stdio.h>
#define MAX 2000000000
main(){
    int n,x0,x,y,left,right,i,tmp;
    scanf("%d%d",&n,&x0);
    left=-MAX;
    right=MAX;
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        if(x>y){
            tmp=x;
            x=y;
            y=tmp;
        }
        if(x>left)left=x;
        if(y<right)right=y;
    }
    if(right<left)puts("-1");
    else{
        if(x0>=left&&x0<=right)puts("0");
        else if(x0<left)printf("%d\n",left-x0);
        else printf("%d\n",x0-right);
    }
}