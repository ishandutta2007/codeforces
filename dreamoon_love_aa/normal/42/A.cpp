#include<stdio.h>
int a[22],b[22];
main(){
    int n,V,i;
    double mi=100000,an=0;
    scanf("%d%d",&n,&V);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    for(i=0;i<n;i++)
        if((double)b[i]/a[i]<mi)mi=(double)b[i]/a[i];
    for(i=0;i<n;i++)an+=mi*a[i];
    if(an>V)an=V;
    printf("%lf\n",an);
}