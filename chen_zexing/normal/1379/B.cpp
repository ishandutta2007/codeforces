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
#include <bitset>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long l,r,m;
        scanf("%lld%lld%lld",&l,&r,&m);
        long long a,b,c,n;
        long long s=r-l;
        long long mn=m-s,mx=m+s;
        for(long long i=l;i<=r;i++)
            if(mx/i>(mn-1)/i)
            {
                a=i;
                s=mx/i*i-m;
                break;
            }
        if(s>=0)
        {
            c=r;
            b=r-s;
        }
        else{
            b=r;
            c=r+s;
        }
        printf("%lld %lld %lld\n",a,b,c);
    }
}