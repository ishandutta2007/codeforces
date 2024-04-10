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
int a[200005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        long long cnt=0,ans=0,sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=(i%2==0)*a[i];
        }
        for(int i=0;i<n/2;i++)
        {
            cnt+=a[i*2+1]-a[i*2];
            if(cnt<0) cnt=0;
            if(cnt>ans) ans=cnt;
        }
        cnt=0;
        for(int i=1;i<(n+1)/2;i++)
        {
            cnt+=a[i*2-1]-a[i*2];
            if(cnt<0) cnt=0;
            if(cnt>ans) ans=cnt;
        }
        printf("%lld\n",ans+sum);
    }
    return 0;
}