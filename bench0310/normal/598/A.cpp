#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%I64d",&n);
        long long res=(n*(n+1)/2);
        for(long long i=0;(1ll<<i)<=n;i++) res-=2*(1ll<<i);
        printf("%I64d\n",res);
    }
    return 0;
}