#include<cstdio>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int an=0;
    for(int i=1;i<=n;i++)an+=m%i==0&&m/i<=n;
    printf("%d",an);
    return 0;
}