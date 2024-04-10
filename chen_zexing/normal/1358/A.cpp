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
        int a,b;
        scanf("%d%d",&a,&b);
        if(a*b%2) printf("%d\n",(a*b+1)/2);
        else printf("%d\n",a*b/2);
    }
    return 0;

}