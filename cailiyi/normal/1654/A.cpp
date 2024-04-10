#include<bits/stdc++.h>
#define N 1000
using namespace std;
int T,n,max1,max2;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n),max1=max2=0;
        for(int i=1,a;i<=n;++i)
        {
            scanf("%d",&a);
            if(a>=max1) max2=max1,max1=a;
            else if(a>max2) max2=a;
        }
        printf("%d\n",max1+max2);
    }
    return 0;
}