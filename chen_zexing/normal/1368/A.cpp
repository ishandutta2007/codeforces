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
        long long a,b,n;
        int ans=0;
        scanf("%lld%lld%lld",&a,&b,&n);
        while(a<=n&&b<=n)
        {
            if(a<b) a+=b;
            else b+=a;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}