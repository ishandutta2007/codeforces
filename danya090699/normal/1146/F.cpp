#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, mod=998244353;
vector <int> sv[sz];
int q[sz][2];
void dfs(int v)
{
    if(sv[v].size())
    {
        int dp[3]={1, 0, 0}, dp2[3]={0, 0, 0};
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            dfs(ne);
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<2; j++)
                {
                    dp2[min(i+j, 2)]=(dp2[min(i+j, 2)]+1ll*dp[i]*q[ne][j])%mod;
                }
            }
            for(int i=0; i<3; i++) dp[i]=dp2[i], dp2[i]=0;
        }
        q[v][0]=(dp[0]+dp[2])%mod;
        q[v][1]=(dp[1]+dp[2])%mod;
    }
    else q[v][0]=1, q[v][1]=1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=1; a<n; a++)
    {
        int pr;
        scanf("%d", &pr);
        pr--;
        sv[pr].push_back(a);
    }
    dfs(0);
    cout<<q[0][0];
}