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
int a[2005],ch[5005],good[5005];
bool cmp(int a,int b)
{
    return a<b;
}
int main() {
    int n,p,cnt=0;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    int now=1;
    for(int i=1;i<=5000;i++)
    {
        while(a[now]<i&&now<=n) now++;
        ch[i]=now-1;
    }
    for(int i=1;i<=2000;i++)
    {
        int ans=1;
        for(int j=1;j<=n;j++)
        {
            int t=ch[j+i]-j+1;
            //printf("%d %d %d\n",i,j,t);
            if(t<=0||t%p==0)
            {
                ans=0;
                break;
            }
        }
        good[i]=ans;
        if(ans) cnt++;
    }
    printf("%d\n",cnt);
    for(int i=1;i<=2000;i++)
        if(good[i])
            printf("%d ",i);
    printf("\n");
    return 0;
}