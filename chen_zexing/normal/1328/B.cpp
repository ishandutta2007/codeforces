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
int a[100005];
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,k;
        scanf("%d%d",&a,&k);
        for(int i=1;i<=a-1;i++)
        {
            if(k>i){
                k-=i;
                continue;
            }
            int t1,t2;
            t1=i+1;
            t2=k;
            for(int j=a;j>=1;j--)
            {
                if(j==t1||j==t2) printf("b");
                else printf("a");
            }
            break;
        }
        printf("\n");
    }
    return 0;
}