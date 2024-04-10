#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=5000+5;
int n;
ll v[N];
ll dp[N][5];
int dad[N][5];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    ll sum=0LL;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
        dp[i][1]=sum;
    }
    for(int k=2;k<=4;k++)
    {
        int who=0;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            ll add;
            if(k%2)
            {
                add=v[i];
            }
            else
            {
                add=-v[i];
            }
            ans=max(ans+add,dp[i][k-1]);
            if(ans==dp[i][k-1])
            {
                who=i;
            }
            dp[i][k]=ans;
            dad[i][k]=who;
        }
    }
    vector<int>ans;
    int now=n;
    for(int i=4;i>1;i--)
    {
        now=dad[now][i];
        ans.push_back(now);
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
    cout<<"\t\tLOL - > "<<dad[n][4]<<"\n";
    for(int k=1;k<=4;k++)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<dp[i][k]<<" ";
        }
        cout<<"\n";
    }
    cout<<"ANS = "<<dp[n][4]<<"\n";
    return 0;
}
/**

3
-7 2 3

**/