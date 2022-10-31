#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
int n;
int a[1100000];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; scanf("%d",&x);
        a[x]=1;
    }
    int ans=0;
    for(int i=1;i<=1000000;i++)
    {
        int now=-1;
        for(int j=1;j<=1000000;j++)
        {
            if (i*j>1000000)break;
            if (!a[i*j])continue;
            if (now==-1)now=i*j;
            else now=__gcd(now,i*j);
        }
        if (now==i && !a[i])ans++;
    }
    cout<<ans<<endl;
}