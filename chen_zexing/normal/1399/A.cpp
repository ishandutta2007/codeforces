#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
#include <cstring>
using namespace std;
int a[105];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        int n,mx=INT_MIN,mn=INT_MAX,t;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            mx=max(t,mx);
            mn=min(t,mn);
            a[t]=1;
        }
        int f=1;
        for(int i=mn;i<=mx;i++)
            if(a[i]==0)
                f=0;
        if(f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}