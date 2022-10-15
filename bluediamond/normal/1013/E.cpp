#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=5000+5;
int n,v[N];
int dp[N][N]; /// dp[cnt][lst_ind]

inline int cost(int a,int i,int b)
{
    int ans=0;
    if(a>=v[i])
    {
        ans+=a-v[i]+1;
    }
    if(b>=v[i])
    {
        ans+=b-v[i]+1;
    }
    return ans;
}

inline int dr(int i)
{
    return min(v[i]-1,v[i+1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    v[0]=v[n+1]=-(1<<30);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=cost(v[i-1],i,v[i+1]);
    }
    int len=(n+1)/2;
    for(int cnt=2;cnt<=len;cnt++)
    {
        int mi=(1<<30);
        for(int i=2*cnt-1;i<=n;i++)
        {
            dp[cnt][i]=dp[cnt-1][i-2]+cost(dr(i-2),i,v[i+1]);
            dp[cnt][i]=min(dp[cnt][i],mi+cost(v[i-1],i,v[i+1]));
            mi=min(mi,dp[cnt-1][i-2]);
        }
    }
    for(int cnt=1;cnt<=len;cnt++)
    {
        int mi=(1<<30);
        for(int j=2*cnt-1;j<=n;j++)
        {
            mi=min(mi,dp[cnt][j]);
        }
        cout<<mi<<" ";
    }
    cout<<"\n";
    return 0;
}