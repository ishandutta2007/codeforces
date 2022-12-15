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
#include <bitset>
#include <vector>
using namespace std;
int a[200005];
int main()
{
    int n,t,k,mn=0,mx=0;
    cin>>n>>t>>k;
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<a[i-1]) mn+=a[i-1]-a[i];
        mx+=a[i]-1;
    }
    mx++;
    mn+=a[t];
    if(k<mn||k>mx)
    {
        printf("-1\n");
        return 0;
    }
    int rest=k-mn,now=a[1]+2;
    printf("%d\n",n);
    //printf("%d\n",rest);
    for(int i=1;i<=t;i++)
    {
        if(i==1)
        {
            for(int j=2;j<=a[1]+1;j++)
                printf("1 %d\n",j);
            continue;
        }
        for(int j=now;j<=now+a[i]-1;j++)
        {
            if(rest&&j!=now&&a[i-1]>1&&j-a[i-1]<now)
            {
                printf("%d %d\n",now-a[i-1],j);
                rest--;
            }
            else if(j-a[i-1]<now)
                printf("%d %d\n",j-a[i-1],j);
            else printf("%d %d\n",now-a[i-1],j);
        }
        now+=a[i];
    }
}