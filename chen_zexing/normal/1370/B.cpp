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
queue <int> e,o;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        while(!e.empty()) e.pop();
        while(!o.empty()) o.pop();
        int n,even=0,odd=0,t;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++)
        {
            scanf("%d",&t);
            if(t%2)
            {
                o.push(i);
                odd++;
            }
            else
            {
                e.push(i);
                even++;
            }
        }
        if(odd%2)
        {
            for(int i=1;i<=odd/2;i++)
            {
                printf("%d ",o.front());
                o.pop();
                printf("%d\n",o.front());
                o.pop();
            }
            for(int i=1;i<=even/2;i++)
            {
                printf("%d ",e.front());
                e.pop();
                printf("%d\n",e.front());
                e.pop();
            }
        }
        else{
            if(even) {
                for (int i = 1; i <= odd / 2; i++) {
                    printf("%d ", o.front());
                    o.pop();
                    printf("%d\n", o.front());
                    o.pop();
                }
                for (int i = 1; i <= even / 2-1; i++) {
                    printf("%d ", e.front());
                    e.pop();
                    printf("%d\n", e.front());
                    e.pop();
                }
            }
            else{
                for (int i = 1; i <= odd / 2-1; i++) {
                    printf("%d ", o.front());
                    o.pop();
                    printf("%d\n", o.front());
                    o.pop();
                }
                for (int i = 1; i <= even / 2; i++) {
                    printf("%d ", e.front());
                    e.pop();
                    printf("%d\n", e.front());
                    e.pop();
                }
            }
        }
    }
    return 0;
}