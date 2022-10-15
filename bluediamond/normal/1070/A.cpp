#include <bits/stdc++.h>

using namespace std;

const int N=5000+5;
const int MOD=500+5;

int dp[N][MOD];
pair<int,int>ant[N][MOD];

queue<pair<int,int>>q;

int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<MOD;j++)
        {
            dp[i][j]=-1;
        }
    }
    int mod,tot;
    cin>>mod>>tot;
    for(int i=1;i<=9;i++)
    {
        q.push({i,i%mod});
        dp[i][i%mod]=i;
    }
    while(!q.empty())
    {
        int s0=q.front().first,r0=q.front().second;
        q.pop();
        for(int i=0;i<=9;i++)
        {
            int s=s0+i;
            int r=(10*r0+i)%mod;
            if(s>tot || dp[s][r]!=-1) continue;
            dp[s][r]=i;
            ant[s][r]={s0,r0};
            q.push({s,r});
        }
    }
    if(dp[tot][0]==-1)
    {
        cout<<"-1\n";
        return 0;
    }
    vector<int>ans;
    int s=tot;
    int r=0;
    while(s)
    {
        ans.push_back(dp[s][r]);
        pair<int,int>rof=ant[s][r];
        s=rof.first;
        r=rof.second;
    }
    reverse(ans.begin(),ans.end());
    for(auto &x:ans)
    {
        cout<<x;
    }
    cout<<"\n";
    return 0;
}