#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
double num[200010],now[200010],pre[200010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%lf",&num[i]);
    double l=-10000,r=10000;
    for(int k=1;k<=300;k++)
    {
        double mid1=(l+(r-l)*49.0/100.0),mid2=(r-(r-l)*49.0/100.0);
        for(int i=1;i<=n;i++)
            now[i]=num[i]+mid1;
        double mn=0,mx=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+now[i];
            ans=max(pre[i]-mn,max(ans,mx-pre[i]));
            mn=min(mn,pre[i]);
            mx=max(mx,pre[i]);
        }
        double mn2=0,mx2=0,ans2=0;
        for(int i=1;i<=n;i++)
            now[i]=num[i]+mid2;
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+now[i];
            ans2=max(pre[i]-mn2,max(ans2,mx2-pre[i]));
            mn2=min(mn2,pre[i]);
            mx2=max(mx2,pre[i]);
        }
        if(ans<ans2)
            r=mid2;
        else
            l=mid1;
    }
        for(int i=1;i<=n;i++)
            now[i]=num[i]+l;
        double mn=0,mx=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+now[i];
            ans=max(pre[i]-mn,max(ans,mx-pre[i]));
            mn=min(mn,pre[i]);
            mx=max(mx,pre[i]);
        }   
        printf("%.10f",ans);
}