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
int a[1005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,x=0,y=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2&&i%2==0) x++;
            else if(a[i]%2==0&&i%2) y++;
        }
        if(x==y) printf("%d\n",x);
        else printf("-1\n");
    }
    return 0;
}