#include <bits/stdc++.h>
using namespace std;
const int sz=5e2+10, sz2=5e3+10, inf=1e9;
int dp[sz][sz2];
bool us[sz][sz2];
vector <pair <int, int> > sv[sz][sz2];
void dfs(int d, int s)
{
    us[d][s]=1;
    for(int a=0; a<sv[d][s].size(); a++)
    {
        int nd=sv[d][s][a].first, ns=sv[d][s][a].second;
        if(us[nd][ns]==0) dfs(nd, ns);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int d, s;
    cin>>d>>s;
    for(int a=0; a<d; a++) for(int b=0; b<=s; b++) dp[a][b]=inf;
    dp[0][0]=inf;
    queue <pair <int, int> > qu;
    qu.push({0, 0});
    while(qu.size())
    {
        int cd=qu.front().first, cs=qu.front().second;
        for(int i=0; (i<10 and cs+i<=s); i++)
        {
            int nd=(cd*10+i)%d, ns=cs+i;
            if(dp[nd][ns]==inf) dp[nd][ns]=dp[cd][cs]+1, qu.push({nd, ns});

            if(dp[nd][ns]==dp[cd][cs]+1) sv[nd][ns].push_back({cd, cs});
        }
        qu.pop();
    }
    if(dp[0][s]!=inf)
    {
        dfs(0, s);
        int cd=0, cs=0;
        while(!(cd==0 and cs==s))
        {
            for(int i=0; i<10; i++)
            {
                int nd=(cd*10+i)%d, ns=cs+i;
                if(us[nd][ns] and dp[nd][ns]==dp[cd][cs]+1)
                {
                    printf("%d", i);
                    cd=nd, cs=ns;
                    break;
                }
            }
        }
    }
    else cout<<-1;
}