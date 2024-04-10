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
char s[100005];
int pre[100005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,x,cnt=0;
        cin>>n>>x;
        scanf("%s",s);
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='0') pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1]-1;
        }
        int sum=pre[n];
        if(sum==0)
        {
            int f=0;
            for(int i=0;i<=n;i++)
                if(pre[i]==x)
                {
                    f=1;
                    break;
                }
            if(f) printf("-1\n");
            else printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++)
            if(pre[i]-x==(pre[i]-x)/sum*sum&&(x-pre[i])/sum>=0)
                cnt++;
        if(x==0) cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}