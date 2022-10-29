#include<stdio.h>
#include<algorithm>
using namespace std;
int ans[100];
int main()
{
    int num,d;
    scanf("%d%d",&num,&d);
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<num;j++)
        {
            char z;
            scanf(" %c",&z);
            ans[i]+=z-'0';
        }
    }
    int maxi=0;
    int now=0;
    for(int i=0;i<d;i++)
    {
        if(ans[i]!=num)now++;
        else now=0;
        maxi=max(maxi,now);
    }
    printf("%d\n",maxi);
}