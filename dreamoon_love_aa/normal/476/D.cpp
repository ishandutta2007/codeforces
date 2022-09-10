#include<cstdio>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",(n*6-1)*k);
    for(int i=0;i<n;i++)
        printf("%d %d %d %d\n",(i*6+1)*k,(i*6+2)*k,(i*6+3)*k,(i*6+5)*k);
    return 0;
}