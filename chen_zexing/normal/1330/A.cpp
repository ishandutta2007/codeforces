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
int a[105],used[505];
bool cmp(int a,int b)
{
    return a<b;
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        memset(used,0,sizeof(used));
        int n,x,t=1;
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            used[a[i]]=1;
        }
        while(x>=0)
        {
            if(!used[t]) x--;
            t++;
        }
        printf("%d\n",t-2);
    }
    return 0;
}