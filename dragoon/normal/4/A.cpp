#include<stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
    
    if(a%2==1 || a<4) printf("NO\n"); else printf("YES\n");
    
    return 0;
}