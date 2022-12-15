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
long long gcd(long long a,long long b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        long long m,d,w;
        scanf("%lld%lld%lld",&m,&d,&w);
        if((d-1)%w==0) printf("%lld\n",min(m,d)*(min(m,d)-1)/2);
        else
        {
            w/=gcd(w,d-1);
            long long mx=min(m,d),ans=0;
            long long st=mx-w,ed=mx%w;
            long long n=(st-ed)/w+1;
            ans=(st+ed)*n/2;
            printf("%lld\n",ans);
        }
    }
    return 0;
}