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
char s[15]={'0','c','o','d','e','f','o','r','c','e','s'};
int main() {
    long long t;
    scanf("%lld",&t);
    long long now=1;
    int a=1,b=10;
    while(now<t)
    {
        if(b==10)
        {
            now/=a;
            a++;
            b=1;
            now*=a;
        }
        else
        {
            now/=(a-1);
            now*=a;
            b++;
        }
    }
    for(int i=1;i<=b;i++)
        for(int j=1;j<=a;j++)
            printf("%c",s[i]);
    for(int i=b+1;i<=10;i++)
        for(int j=1;j<=a-1;j++)
            printf("%c",s[i]);
    return 0;
}