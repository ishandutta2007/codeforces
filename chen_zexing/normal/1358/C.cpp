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
    while(T--)
    {
        long long x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        printf("%lld\n",(x2-x1)*(y2-y1)+1);
    }
    return 0;

}