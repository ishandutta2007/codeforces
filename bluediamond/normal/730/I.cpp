#include <bits/stdc++.h>

using namespace std;

const int N=3000+5;

int n;
int ca,cb;

struct info
{
    int a;
    int b;
    int i;
};

info v[N];

bool cmp(info f,info s)
{
    return f.a>s.a;
}

int dp[N][N];
pair<int,int>kid[N][N];
int p[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dp[i][j]=-(1<<30);
        }
    }
    cin>>n>>ca>>cb;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].a;
        v[i].i=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].b;
    }
    sort(v+1,v+n+1,cmp);
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=min(cb,i);j++)
        {
            int tot=i-j;
            /// take a
            if(tot<=ca)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j]+v[i].a);
                if(dp[i-1][j]+v[i].a==dp[i][j])
                {
                    kid[i][j]={i-1,j};
                    p[i][j]=1;
                }
            }
            else
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if(dp[i-1][j]==dp[i][j])
                {
                    kid[i][j]={i-1,j};
                    p[i][j]=0;
                }
            }
            /// take b
            if(j>=1)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+v[i].b);
                if(dp[i-1][j-1]+v[i].b==dp[i][j])
                {
                    kid[i][j]={i-1,j-1};
                    p[i][j]=2;
                }
            }
        }
    }
    /**for(int i=0;i<=n;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(dp[i][j]==-(1<<30)) continue;
            cout<<"\t\t"<<i<<" "<<j<<" = "<<dp[i][j]<<"\n";
        }
    } **/
    cout<<dp[n][cb]<<"\n";
    vector<int>a;
    vector<int>b;
    int i=n;
    int j=cb;
    while(i)
    {
      ///  cout<<i<<" "<<j<<"\t\t"<<p[i][j]<<"\n";
        if(p[i][j]==1) a.push_back(v[i].i);
        if(p[i][j]==2) b.push_back(v[i].i);
        pair<int,int>aux=kid[i][j];
        i=aux.first;
        j=aux.second;
    }
    for(auto &x:a) cout<<x<<" "; cout<<"\n";
    for(auto &x:b) cout<<x<<" "; cout<<"\n";
    return 0;
}