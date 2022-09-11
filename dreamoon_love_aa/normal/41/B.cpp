#include<stdio.h>
int a[1010];
main(){
    int n,B,i,j,an;
    scanf("%d%d",&n,&B);
    an=B;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    j=0;
    for(i=n-1;i>=0;i--){
        if(an<B+(B/a[i])*(j-a[i]))
            an=B+(B/a[i])*(j-a[i]);
        if(a[i]>j)j=a[i];
    }
    printf("%d\n",an);
}