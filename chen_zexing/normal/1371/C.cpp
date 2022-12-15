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
        long long a,b,n,m;
        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        if(a+b<n+m)
        {
            printf("No\n");
            continue;
        }
        long long mn=b;
        if(mn>a) mn=a;
        if(mn>=m) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}