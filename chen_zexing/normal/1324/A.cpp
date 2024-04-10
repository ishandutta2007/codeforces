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
        int a[105];
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int f=1,t=a[1]%2;
        for(int i=2;i<=n;i++)
        {
            if(a[i]%2!=t)
            {
                f=0;
                break;
            }
        }
        if(f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}