#include<stdio.h>
int a[1010],b[1010],c[1010];
main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    b[0]=1;
    for(i=1;i<n;i++){
        if(a[i]>=a[i-1])b[i]=b[i-1]+1;
        else b[i]=1;
    }
    c[n-1]=1;
    for(i=n-2;i>=0;i--){
        if(a[i]>=a[i+1])c[i]=c[i+1]+1;
        else c[i]=1;
    }
    int an=0;
    for(i=0;i<n;i++){
        if(an<b[i]+c[i]-1)an=b[i]+c[i]-1;
    }
    printf("%d\n",an);
}