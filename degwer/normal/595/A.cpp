#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int r=0;
    for(int i=0;i<a*b;i++)
    {
        int za,zb;
        scanf("%d%d",&za,&zb);
        if(za+zb>=1)r++;
    }
    printf("%d\n",r);
}