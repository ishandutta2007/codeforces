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
#include <string>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        long long n,r;
        scanf("%lld%lld",&n,&r);
        long long ans=0,mx=n-1;
        if(mx>r) mx=r;
        ans=(mx+1)*mx/2;
        if(r>=n) ans++;
        printf("%lld\n",ans);
    }
    return 0;
}