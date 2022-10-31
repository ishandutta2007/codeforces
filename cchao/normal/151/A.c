#include <stdio.h>
int main()
{
    int n,k,l,c,d,p,nl,np;
    scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
    int n1,n2,n3,min;
    n1=k*l/nl;
    n2=c*d;
    n3=p/np;
    min=n1;
    if(n2<min)min=n2;
    if(n3<min)min=n3;
    printf("%d",min/n);
    return 0;
}