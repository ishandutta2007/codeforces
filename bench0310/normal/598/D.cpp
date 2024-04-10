#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    char s[n][m+1];
    for(int o=0;o<n;o++) scanf("%s",s[o]);
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<int> res(n*m+1,0);
    int idx=1;
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            if(s[o][i]=='*'||vis[o][i]) continue;
            queue<pair<int,int>> q;
            q.push({o,i});
            vis[o][i]=idx;
            int z[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
            while(!q.empty())
            {
                int a,b;
                tie(a,b)=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int c=a+z[j][0];
                    int d=b+z[j][1];
                    if(s[c][d]=='*') res[idx]++;
                    else if(vis[c][d]==0)
                    {
                        q.push({c,d});
                        vis[c][d]=idx;
                    }
                }
            }
            idx++;
        }
    }
    for(int i=0;i<k;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        printf("%d\n",res[vis[a][b]]);
    }
    return 0;
}