#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    int a=0,b=0;
    for(int i=0;i<num;i++)
    {
        int z;
        scanf("%d",&z);
        a|=z;
    }
    for(int i=0;i<num;i++)
    {
        int z;
        scanf("%d",&z);
        b|=z;
    }
    printf("%d\n",a+b);
}