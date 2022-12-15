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
        int n,a,b,f1=0,f2=0;
        scanf("%d",&n);
        for(int i=2;i<=1000;i++)
        {
            if(n%i==0)
            {
                a=i;
                f1=1;
                break;
            }
        }
        if(f1==0)
        {
            printf("NO\n");
            continue;
        }
        n/=a;
        for(int i=2;i<sqrt(n);i++)
            if(n%i==0&&i!=a)
            {
                b=i;
                f2=1;
                break;
            }
        if(f2==0)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n%d %d %d\n",a,b,n/b);
    }
    return 0;
}