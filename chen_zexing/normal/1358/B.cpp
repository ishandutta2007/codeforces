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
bool cmp(int a,int b)
{
    return a<b;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,ans=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
            if(i>=a[i])
                ans=i+1;
        printf("%d\n",ans);
    }
    return 0;

}