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
int main() {
    int n,f=0,cnt=0;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if(t>0)
            ans+=t-1;
        if(t<0)
        {
            ans+=-1-t;
            cnt++;
        }
        if(t==0)
        {
            f=1;
            ans++;
        }
    }
    if(cnt%2==0) printf("%lld\n",ans);
    else if(cnt%2&&f) printf("%lld\n",ans);
    else printf("%lld\n",ans+2);
}