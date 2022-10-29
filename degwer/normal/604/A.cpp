#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int a[5],b[5];
    for(int i=0;i<5;i++)scanf("%d",&a[i]);
    for(int i=0;i<5;i++)scanf("%d",&b[i]);
    int r=0;
    for(int i=0;i<5;i++)
    {
        int t=(i+1)*500;
        r+=max(t*3/10,t*(250-a[i])/250-50*b[i]);
    }
    int za,zb;
    scanf("%d%d",&za,&zb);
    printf("%d\n",r+za*100-zb*50);
}