#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define MAX 500000
LL a[MAX],b[MAX];
int main()
{
    LL t;
    while(scanf("%I64d",&t)==1)
    {
        for(LL i=0;i<t;i++)
            scanf("%I64d",&a[i]);
        memset(b,0,sizeof b);
        for(LL i=t-1,q=0;i>=0;i--)
        {
            q=-q;
            b[i]=a[i]-q;
            q+=b[i];
        }
        printf("%I64d",b[0]);
        for(LL i=1;i<t;i++)
            printf(" %I64d",b[i]);
        puts("");
    }

    return 0;
}