#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
long long n,a[101000];
int main()
{
    scanf("%I64d",&n);
    if(n==1)printf("0");
    else if(n==2)printf("1");
    else
    {
    int i=1;a[0]=1;a[1]=2;
    for(;;)
    {
        i++;
        a[i]=a[i-1]+a[i-2];
        if(a[i]>n)break;
    }
    printf("%d",i-1);
    }
    return 0;
}