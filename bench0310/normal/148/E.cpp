#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> dp(m+1,0);
    while(n--)
    {
        int k;
        scanf("%d",&k);
        vector<int> v(k+2,0);
        for(int i=1;i<=k;i++) scanf("%d",&v[i]);
        vector<int> l(k+2,0);
        vector<int> r(k+2,0);
        for(int i=1;i<=k;i++) l[i]=l[i-1]+v[i];
        for(int i=k;i>=1;i--) r[i]=r[i+1]+v[i];
        vector<int> best(k+1,0);
        for(int i=0;i<=k;i++) for(int j=i+1;j<=k+1;j++) best[i+(k-j+1)]=max(best[i+(k-j+1)],l[i]+r[j]);
        for(int i=m;i>=0;i--) for(int j=1;j<=k;j++) if(i+j<=m) dp[i+j]=max(dp[i+j],dp[i]+best[j]);
    }
    printf("%d\n",dp[m]);
    return 0;
}