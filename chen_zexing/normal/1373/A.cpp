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
long long ans[2000005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        if(a*b<=c) printf("1 -1\n");
        else
        {
            if(a<c) printf("1 %lld\n",b);
            else printf("-1 %lld\n",b);
        }
    }
    return 0;
}