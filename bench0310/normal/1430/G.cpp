#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=18;
ll dp[N][N+1][(1<<N)];
bool p[N][N+1][(1<<N)];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n];
    vector<int> in(n,0);
    vector<ll> c(n,0);
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;
        v[a].push_back(b);
        in[b]++;
        c[a]+=w;
        c[b]-=w;
    }
    vector<int> ord;
    for(int i=0;i<n;i++) if(in[i]==0) ord.push_back(i);
    for(int o=0;o<n;o++)
    {
        for(int to:v[ord[o]])
        {
            in[to]--;
            if(in[to]==0) ord.push_back(to);
        }
    }
    vector<int> reach(n,0);
    for(int i=0;i<n;i++)
    {
        function<void(int)> dfs=[&](int a)
        {
            reach[i]^=(1<<a);
            for(int to:v[a]) if(((1<<to)&reach[i])==0) dfs(to);
        };
        dfs(i);
        reach[i]^=(1<<i);
    }
    const ll inf=(1ll<<60);
    for(int i=0;i<n;i++) for(int j=0;j<=n;j++) for(int k=0;k<(1<<n);k++) dp[i][j][k]=inf;
    for(int i=0;i<n;i++) for(int j=0;j<=n;j++) for(int k=0;k<(1<<n);k++) p[i][j][k]=0;
    dp[0][0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<(1<<n);k++)
            {
                if(j==n)
                {
                    if(i<n-1)
                    {
                        dp[i+1][0][k]=dp[i][j][k];
                        p[i+1][0][k]=0;
                    }
                }
                else
                {
                    int a=ord[j];
                    ll d=c[a]*i;
                    if(dp[i][j][k]<dp[i][j+1][k])
                    {
                        dp[i][j+1][k]=dp[i][j][k];
                        p[i][j+1][k]=0;
                    }
                    int nk=k^(1<<a);
                    if((k&(1<<a))==0&&(reach[a]&k)==reach[a]&&dp[i][j+1][nk]>dp[i][j][k]+d)
                    {
                        dp[i][j+1][nk]=dp[i][j][k]+d;
                        p[i][j+1][nk]=1;
                    }
                }
            }
        }
    }
    vector<int> res(n,0);
    int i=n-1,j=n,k=(1<<n)-1;
    while(k>0)
    {
        if(p[i][j][k]==1)
        {
            res[ord[j-1]]=i;
            k^=(1<<ord[j-1]);
        }
        j--;
        if(j==0)
        {
            j=n;
            i--;
        }
    }
    for(int a:res) cout << a << " ";
    cout << "\n";
    return 0;
}