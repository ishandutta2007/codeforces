#include<stdio.h>
int a[100001];
main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n<3)puts("0");
    else{
        for(k=1;k+1<=n;k++)
            if(a[k]!=a[k+1])break;
        if(k==n)puts("0");
        else{
            if(a[k+1]>a[k]){
                for(i=k+2;i<=n;i++)
                    if(a[i-1]>a[i])break;
                if(i>n)puts("0");
                else printf("3\n%d %d %d\n",k,i-1,i);
            }
            else{
                for(i=k+2;i<=n;i++)
                    if(a[i-1]<a[i])break;
                if(i>n)puts("0");
                else printf("3\n%d %d %d\n",k,i-1,i);
            }
        }
    }
}