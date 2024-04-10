#include<stdio.h>
#define MID 50005
int used[100010],to[100010];
main(){
    int n,x,d,answer=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&x,&d);
        x+=MID;
        used[x]=1;
        to[x]=x+d;
        if(used[x]&&to[to[x]]==x)answer=1;
    }
    if(answer)puts("YES");
    else puts("NO");
}