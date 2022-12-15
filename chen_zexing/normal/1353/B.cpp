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
int a[50],b[50];
bool cmp1(int a,int b)
{
    return a<b;
}
bool cmp2(int a,int b)
{
    return a>b;
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(b+1,b+n+1,cmp2);
        //for(int i=1;i<=n;i++) printf("%d ",b[i]);
        int ans=0;
        for(int i=1;i<=k;i++)
        {
            if(a[i]>=b[i]) break;
            ans+=b[i]-a[i];
        }
        //printf("%d ",ans);
        for(int i=1;i<=n;i++) ans+=a[i];
        printf("%d\n",ans);
    }
    return 0;
}