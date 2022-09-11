#include<stdio.h>
int a[110];
main(){
    int n,l,i,j,k,an=0;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=l;;i++){
        k=0;
        for(j=0;j<n;j++)
            k+=a[j]/i*i;
        if(!k)break;
        if(an<k)an=k;
    }
    printf("%d\n",an);
}