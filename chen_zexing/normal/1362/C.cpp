#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
using namespace std;
long long sum[100];
int main() {
    int x=1;
    sum[0]=1;
    sum[1]=3;
    while(sum[x]<LLONG_MAX/2)
    {
        x++;
        sum[x]=2*sum[x-1]+1;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n,ans=0;
        scanf("%lld",&n);
        while(n)
        {
            long long i=0;
            while(pow(2,i)<=n) i++;
            i--;
            ans+=sum[i];
            n-=pow(2,i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}