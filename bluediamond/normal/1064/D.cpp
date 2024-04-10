/**
    Contact me if you want to make F.U. Money
**/

#include <bits/stdc++.h>

using namespace std;

const int N=2000+5;

int n,m;
int r1,c1;
int x,y;

int v[N][N];
int dp[N][N];

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

bool valid(int r,int c)
{
    if(1<=r && 1<=c && r<=n && c<=m && v[r][c]==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>r1>>c1;
    cin>>x>>y;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            v[i][j]=(s[j-1]=='*');
            dp[i][j]=(1<<30);
        }
    }
    dp[r1][c1]=0;
    deque<pair<int,int>>q;
    q.push_back({r1,c1});
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop_front();
        for(int k=0;k<4;k++)
        {
            int rn=r+dr[k];
            int cn=c+dc[k];
            if(valid(rn,cn))
            {
                int cost;
                if(k==1)
                {
                    cost=dp[r][c]+1;
                }
                else
                {
                    cost=dp[r][c];
                }
                if(cost<dp[rn][cn])
                {
                    dp[rn][cn]=cost;
                    if(k==1)
                    {
                        q.push_back({rn,cn});
                    }
                    else
                    {
                        q.push_front({rn,cn});
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int l=dp[i][j];
            /// c1+l-r=j
            int r=c1+l-j;
            if(l<=y && r<=x)
            {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}