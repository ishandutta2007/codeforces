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
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        long long ans=0;
        scanf("%d",&n);
        for(long long i=1;i*2<n;i++)
            ans+=8*i*i;
        printf("%lld\n",ans);
    }
    return 0;
}