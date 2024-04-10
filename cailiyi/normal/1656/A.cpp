#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,a[N+5];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int i=1,j=1;
        for(int k=1;k<=n;++k)
        {
            scanf("%d",a+k);
            if(a[k]<a[i]) i=k;
            if(a[k]>a[j]) j=k;
        }
        printf("%d %d\n",i,j);
    }
    return 0;
}