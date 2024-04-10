#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    string s;
    cin >> s;
    int n=s.size();
    s="$"+s;
    vector<int> mt(n+1,0);
    stack<int> t;
    vector<int> ord;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(') t.push(i);
        else
        {
            mt[t.top()]=i;
            ord.push_back(t.top());
            t.pop();
        }
    }
    vector<vector<array<ll,4>>> dp(n+1,vector<array<ll,4>>(n+1,{0,0,0,0}));
    auto solve=[&](int l,int r)->array<ll,5>
    {
        if(l+1==r) return {1,1,1,1,4};
        int x=l+1;
        vector<vector<ll>> now(3,vector<ll>(3,0));
        now[1][0]=dp[x][mt[x]][0];
        now[2][0]=dp[x][mt[x]][1];
        now[0][1]=dp[x][mt[x]][2];
        now[0][2]=dp[x][mt[x]][3];
        x=mt[x]+1;
        while(x<r)
        {
            vector<vector<ll>> nxt(3,vector<ll>(3,0));
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<4;k++)
                    {
                        if((j==1&&k==0)||(j==2&&k==1)) continue;
                        int z=0;
                        if(k==2) z=1;
                        if(k==3) z=2;
                        nxt[i][z]=(nxt[i][z]+now[i][j]*dp[x][mt[x]][k])%mod;
                    }
                }
            }
            now=nxt;
            x=mt[x]+1;
        }
        array<ll,5> res={0,0,0,0,0};
        ll sum=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i!=1) res[0]=(res[0]+now[i][j])%mod;
                if(i!=2) res[1]=(res[1]+now[i][j])%mod;
                if(j!=1) res[2]=(res[2]+now[i][j])%mod;
                if(j!=2) res[3]=(res[3]+now[i][j])%mod;
                sum=(sum+now[i][j])%mod;
            }
        }
        res[4]=sum;
        return res;
    };
    for(int a:ord)
    {
        array<ll,5> x=solve(a,mt[a]);
        for(int i=0;i<4;i++) dp[a][mt[a]][i]=x[i];
    }
    cout << solve(0,n+1)[4] << "\n";
    return 0;
}