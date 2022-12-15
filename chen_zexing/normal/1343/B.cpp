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
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n%4==2) printf("NO\n");
        else{
            printf("YES\n");
            long long count1=0,count2=0;
            for(int i=1;i<=n/2;i++)
            {
                printf("%d ",i*2);
                count1+=i*2;
            }
            for(int i=1;i<n/2;i++)
            {
                printf("%d ",i*2-1);
                count2+=i*2-1;
            }
            printf("%lld\n",count1-count2);
        }

    }
    return 0;
}