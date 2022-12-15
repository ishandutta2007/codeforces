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
int a[5005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int f=0;
        for(int i=1;i<=n-2;i++)
        {
            for(int j=i+2;j<=n;j++)
                if(a[i]==a[j])
                {
                    f=1;
                    break;
                }
            if(f) break;
        }
        if(f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}