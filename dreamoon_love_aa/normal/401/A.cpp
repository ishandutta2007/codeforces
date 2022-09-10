#include<cstdio>
int main(){
    int n,x,me=0;
    scanf("%d%d",&n,&x);
    while(n--){
        int y;
        scanf("%d",&y);
        me+=y;
    }
    if(me<0)me=-me;
    printf("%d\n",(me+x-1)/x);
    return 0;
}