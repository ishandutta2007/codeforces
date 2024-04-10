#include<stdio.h>
int a[100000],b[100000];
main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n/3;i++){
        if(n%i==0){
            for(j=0;j<n;j++){
                if(j<i)b[j]=a[j];
                else b[j]=a[j]+b[j-i];
                if(b[j]==n/i)break;
            }
            if(j<n)break;
        }
    }
    if(i<=n/3)puts("YES");
    else puts("NO");
}