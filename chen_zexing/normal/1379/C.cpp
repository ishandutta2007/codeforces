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
struct flower
{
    long long a,b;
}a[100005];
long long sum[100005],s[100005],cnt[100005];
bool cmp1(flower a,flower b)
{
    return a.b>b.b;
}
bool cmp2(int a,int b)
{
    return a>b;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%lld%lld",&a[i].a,&a[i].b);
            s[i]=a[i].a;
        }
        sort(a+1,a+m+1,cmp1);
        sort(s+1,s+m+1,cmp2);
        int now=1;
        long long k=0;
        for(int i=1;i<=m;i++)
        {
            while(s[now]>=a[i].b&&now<=n&&now<=m)
            {
                k+=s[now];
                now++;
            }
            sum[i]=k;
            cnt[i]=now-1;
        }
        long long ans=0,t;
        for(int i=1;i<=m;i++)
        {
            t=sum[i];
            if(cnt[i]==n);
            else if(a[i].a>=a[i].b) t+=(n-cnt[i])*a[i].b;
            else t+=a[i].a+(n-cnt[i]-1)*a[i].b;
            if(ans<t)
            {
                ans=t;
                //printf("%d %lld\n",i,sum[i]);
            }
        }
        printf("%lld\n",ans);
    }
}