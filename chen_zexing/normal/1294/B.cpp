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
struct node
{
    int x,y;
}a[1005];
bool cmp(node a,node b)
{
    return a.x+a.y<b.x+b.y;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,f=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++) if(a[i].x<a[i-1].x||a[i].y<a[i-1].y) f=0;
        if(f==0) printf("NO\n");
        else{
            printf("YES\n");
            for(int i=0;i<n;i++)
            {
                for(int j=a[i].x;j<a[i+1].x;j++) printf("R");
                for(int j=a[i].y;j<a[i+1].y;j++) printf("U");
            }
            printf("\n");
        }
    }
    return 0;
}