#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <pair <int, int> > sv[n][2];
    int left[n][2], dp[n][2], go[n][2];
    queue <pair <int, int> > qu;
    for(int a=0; a<n; a++)
    {
        dp[a][0]=-1, dp[a][1]=-1;
        go[a][0]=-1, go[a][1]=-1;
        scanf("%d", &left[a][0]);
        left[a][1]=left[a][0];
        for(int b=0; b<left[a][0]; b++)
        {
            int v;
            scanf("%d", &v);
            sv[v-1][0].push_back(make_pair(a, 1));
            sv[v-1][1].push_back(make_pair(a, 0));
        }
        if(left[a][0]==0)
        {
            dp[a][0]=0;
            dp[a][1]=1;
            qu.push(make_pair(a, 0));
            qu.push(make_pair(a, 1));
        }
    }
    while(qu.size())
    {
        int v=qu.front().first, t=qu.front().second;
        if(dp[v][t])
        {
            for(int a=0; a<sv[v][t].size(); a++)
            {
                int pr=sv[v][t][a].first, pt=sv[v][t][a].second;
                if(dp[pr][pt]==-1)
                {
                    dp[pr][pt]=1;
                    qu.push(make_pair(pr, pt));
                    go[pr][pt]=v;
                }
            }
        }
        else
        {
            for(int a=0; a<sv[v][t].size(); a++)
            {
                int pr=sv[v][t][a].first, pt=sv[v][t][a].second;
                if(dp[pr][pt]==-1)
                {
                    left[pr][pt]--;
                    if(left[pr][pt]==0)
                    {
                        dp[pr][pt]=0;
                        qu.push(make_pair(pr, pt));
                    }
                }
            }
        }
        qu.pop();
    }
    int s;
    cin>>s;
    s--;
    if(dp[s][0]==-1) cout<<"Draw";
    if(dp[s][0]==0) cout<<"Lose";
    if(dp[s][0]==1)
    {
        int cu=s, ct=0;
        cout<<"Win\n";
        while(cu!=-1)
        {
            cout<<cu+1<<" ";
            cu=go[cu][ct], ct^=1;
        }
    }
}