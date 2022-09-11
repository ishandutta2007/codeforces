#include<stdio.h>
#define SIZE 320
long long a[SIZE][SIZE];
long long min(long long x,long long y){return x<y?x:y;}
main(){
    int n,i,j,K,x,y,z;
    long long an;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)scanf("%I64d",&a[i][j]);
    scanf("%d",&K);
    while(K--){
        scanf("%d%d%d",&x,&y,&z);
        an=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][x]+a[y][j]+z);
                a[i][j]=min(a[i][j],a[i][y]+a[x][j]+z);
                an+=a[i][j];
            }
        printf("%I64d",an/2);
        if(K)putchar(' ');
    }
    puts("");
}