#include<stdio.h>

int main()
{
    int a,b;
    
    scanf("%d%d",&a,&b);
    if(b>a) a=b;
    a=6-a+1;
    if(a%6==0) printf("1/1\n");
    else if(a%2==0) printf("%d/3\n",a/2);
    else if(a%3==0) printf("%d/2\n",a/3);
    else printf("%d/6\n",a);
    
    return 0;
}