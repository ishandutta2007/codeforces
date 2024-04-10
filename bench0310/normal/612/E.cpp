#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> p(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        p[i]--;
    }
    vector<vector<int>> v[n+1];
    vector<bool> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        vector<int> cycle;
        cycle.push_back(i);
        vis[i]=1;
        while(vis[p[cycle.back()]]==0)
        {
            vis[p[cycle.back()]]=1;
            cycle.push_back(p[cycle.back()]);
        }
        v[cycle.size()].push_back(cycle);
    }
    vector<int> q(n,-1);
    for(int i=1;i<=n;i+=2)
    {
        for(vector<int> cycle:v[i])
        {
            int now=0;
            while(q[cycle[now]]==-1)
            {
                q[cycle[now]]=cycle[(now-i/2+i)%i];
                now=(now-i/2+i)%i;
            }
        }
    }
    for(int i=2;i<=n;i+=2)
    {
        if((v[i].size()%2)==1)
        {
            printf("-1\n");
            return 0;
        }
        for(int j=0;j<(int)v[i].size();j+=2)
        {
            vector<int> one=v[i][j];
            vector<int> two=v[i][j+1];
            for(int k=0;k<i;k++) q[one[k]]=two[k];
            for(int k=0;k<i;k++) q[two[k]]=one[(k+1)%i];
        }
    }
    for(int i=0;i<n;i++) printf("%d%c",q[i]+1," \n"[i==n-1]);
    return 0;
}