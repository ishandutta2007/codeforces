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
struct position
{
    int p,v;
}a[200005];
int used[200005],up[200005],down[200005];
bool cmp(position a,position b)
{
    return a.v<b.v;
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].v);
        a[i].p=i;
    }
    sort(a+1,a+n+1,cmp);
    if(k%2==0)
    {
        int ans1,ans2,c=0,i;
        for(i=1;c<k/2;i++)
        {
            if(a[i].p==1) continue;
            used[a[i].p]=1;
            if(up[a[i].p+1]) up[a[i].p]=up[a[i].p+1];
            else up[a[i].p]=a[i].p;
            if(down[a[i].p-1]) down[a[i].p]=down[a[i].p-1];
            else down[a[i].p]=a[i].p;
            c+=(up[a[i].p]-down[a[i].p])/2+1;
            if(up[a[i].p+1]) c-=(up[a[i].p+1]-a[i].p+1)/2;
            if(down[a[i].p-1]) c-=(a[i].p-down[a[i].p-1]+1)/2;
            up[down[a[i].p]]=up[a[i].p];
            down[up[a[i].p]]=down[a[i].p];
        }
        ans1=a[i-1].v;
        c=0;
        memset(used,0,sizeof(used));
        memset(up,0,sizeof(up));
        memset(down,0,sizeof(down));
        for(i=1;c<k/2;i++)
        {
            if(a[i].p==n) continue;
            used[a[i].p]=1;
            if(up[a[i].p+1]) up[a[i].p]=up[a[i].p+1];
            else up[a[i].p]=a[i].p;
            if(down[a[i].p-1]) down[a[i].p]=down[a[i].p-1];
            else down[a[i].p]=a[i].p;
            c+=(up[a[i].p]-down[a[i].p])/2+1;
            if(up[a[i].p+1]) c-=(up[a[i].p+1]-a[i].p+1)/2;
            if(down[a[i].p-1]) c-=(a[i].p-down[a[i].p-1]+1)/2;
            up[down[a[i].p]]=up[a[i].p];
            down[up[a[i].p]]=down[a[i].p];
        }
        ans2=a[i-1].v;
        //printf("%d %d\n",ans1,ans2);
        printf("%d\n",min(ans1,ans2));
    }
    else{
        int ans1,ans2,c=0,i;
        for(i=1;c<k/2;i++)
        {
            if(a[i].p==1||a[i].p==n) continue;
            used[a[i].p]=1;
            if(up[a[i].p+1]) up[a[i].p]=up[a[i].p+1];
            else up[a[i].p]=a[i].p;
            if(down[a[i].p-1]) down[a[i].p]=down[a[i].p-1];
            else down[a[i].p]=a[i].p;
            c+=(up[a[i].p]-down[a[i].p])/2+1;
            if(up[a[i].p+1]) c-=(up[a[i].p+1]-a[i].p+1)/2;
            if(down[a[i].p-1]) c-=(a[i].p-down[a[i].p-1]+1)/2;
            up[down[a[i].p]]=up[a[i].p];
            down[up[a[i].p]]=down[a[i].p];
        }
        ans1=a[i-1].v;
        c=0;
        memset(used,0,sizeof(used));
        memset(up,0,sizeof(up));
        memset(down,0,sizeof(down));
        for(i=1;c<=k/2;i++)
        {
            used[a[i].p]=1;
            if(up[a[i].p+1]) up[a[i].p]=up[a[i].p+1];
            else up[a[i].p]=a[i].p;
            if(down[a[i].p-1]) down[a[i].p]=down[a[i].p-1];
            else down[a[i].p]=a[i].p;
            c+=(up[a[i].p]-down[a[i].p])/2+1;
            if(up[a[i].p+1]) c-=(up[a[i].p+1]-a[i].p+1)/2;
            if(down[a[i].p-1]) c-=(a[i].p-down[a[i].p-1]+1)/2;
            up[down[a[i].p]]=up[a[i].p];
            down[up[a[i].p]]=down[a[i].p];
        }
        ans2=a[i-1].v;
        printf("%d\n",min(ans1,ans2));
    }
    return 0;
}