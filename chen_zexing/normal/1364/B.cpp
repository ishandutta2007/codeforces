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
int a[100005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        int n,cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if((a[i]>a[i-1]&&a[i]<a[i+1]||a[i]<a[i-1]&&a[i]>a[i+1])&&(i!=1&&i!=n))
                cnt++;
        }
        printf("%d\n",n-cnt);
        for(int i=1;i<=n;i++)
        {
            if((a[i]>a[i-1]&&a[i]<a[i+1]||a[i]<a[i-1]&&a[i]>a[i+1])&&(i!=1&&i!=n))
                continue;
            printf("%d ",a[i]);
            //printf("%d\n",i);
        }
        printf("\n");
    }
    return 0;
}