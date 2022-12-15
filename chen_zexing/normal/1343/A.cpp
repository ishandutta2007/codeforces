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
using namespace std;
long long table[50];
int main() {
    long long count=1,now=2;
    for(int i=1;i<=40;i++)
    {
        count+=now;
        now*=2;
        table[i]=count;
    }
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=40;i++)
            if(n%table[i]==0)
            {
                printf("%lld\n",n/table[i]);
                break;
            }

    }
    return 0;
}