#include<stdio.h>
int a[33],b[33];
main(){
    int n,d,mi=0,ma=0,u=0,i;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
        mi+=a[i];
        ma+=b[i];
    }
    if(d<mi||d>ma)puts("NO");
    else{
        puts("YES");
        u=d-mi;
        for(i=0;i<n;i++){
            if(i)putchar(' ');
            if(u>b[i]-a[i]){
                printf("%d",b[i]);
                u-=b[i]-a[i];
            }
            else{
                printf("%d",a[i]+u);
                u=0;
            }
        }
        puts("");
    }
}