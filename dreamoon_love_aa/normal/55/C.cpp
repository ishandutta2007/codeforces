#include<stdio.h>
main(){
    int n,m,k,an=0,x,y;
    scanf("%d%d%d",&n,&m,&k);
    while(k--){
        scanf("%d%d",&x,&y);
        if(x-1<5)an=1;
        else if(y-1<5)an=1;
        else if(n-x<5)an=1;
        else if(m-y<5)an=1;
    }
    if(an==1)puts("YES");
    else puts("NO");
}