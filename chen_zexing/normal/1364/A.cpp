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
        int n,x,sum=0;
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]%=x;
            sum+=a[i];
        }
        if(sum%x) printf("%d\n",n);
        else{
            int mx1=0,mx2=0,i;
            for(i=1;i<=n;sum-=a[i++]) if(a[i]!=sum%x) break;
            mx1=n-i;
            for(i=n;i>=1;sum-=a[i--]) if(a[i]!=sum%x) break;
            mx2=i-1;
            if(max(mx1,mx2)>0) printf("%d\n",max(mx1,mx2));
            else printf("-1\n");
        }
    }
    return 0;
}