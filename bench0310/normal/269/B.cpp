#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n,z;
    scanf("%d%d",&n,&z);
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        double t;
        scanf("%d%lf",&v[i],&t);
    }
    vector<int> dp(n+1,(1<<30));
    dp[0]=0;
    for(int x:v)
    {
        int l=0,r=n;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(x<dp[m]) r=m;
            else l=m;
        }
        dp[r]=x;
    }
    int res=n;
    for(int i=1;i<=n;i++) res-=(dp[i]!=(1<<30));
    printf("%d\n",res);
    return 0;
}