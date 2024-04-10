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
        int n,ans=0;
        long long mx=LLONG_MIN,t,c=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&t);
            if(t>=mx) mx=t;
            if(mx-t>c) c=mx-t;
        }
        while(c)
        {
            c/=2;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}