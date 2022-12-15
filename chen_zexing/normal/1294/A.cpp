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
int a[200005];
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int t=a+b+c+d;
        if(t%3==0&&a<=t/3&&b<=t/3&&c<=t/3) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}