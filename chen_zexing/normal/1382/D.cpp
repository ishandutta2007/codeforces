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
int a[4005],l[4005],reach[4005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        memset(reach,0,sizeof(reach));
        int n;
        cin>>n;
        for(int i=1;i<=n*2;i++)
            scanf("%d",&a[i]);
        int now=a[1],t=1,len=1;
        for(int i=2;i<=n*2;i++)
        {
            if(a[i]<now) len++;
            else
            {
                now=a[i];
                l[t++]=len;
                len=1;
            }
        }
        l[t++]=len;
        reach[0]=1;
        for(int i=1;i<t;i++)
            for(int j=n*2;j>=l[i];j--)
                if(reach[j-l[i]]) reach[j]=1;
        if(reach[n]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}