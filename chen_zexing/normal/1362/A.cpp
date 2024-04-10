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
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(a>b)
        {
            long long c;
            c=a;
            a=b;
            b=c;
        }
        int cnt=0;
        while(a<b)
        {
            a*=2;
            if(b%a!=0)
            {
                cnt=-1;
                break;
            }
            cnt++;
        }
        int ans;
        if(cnt==-1) ans=cnt;
        else if(cnt%3) ans=cnt/3+1;
        else ans=cnt/3;
        printf("%d\n",ans);
    }
    return 0;
}