#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> v[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
    }
    int a[n+1][n+1];
    memset(a,0,sizeof a);
    for(int o=1;o<=n;o++)
    {
        queue<int> q;
        q.push(o);
        q.push(0);
        while(!q.empty())
        {
            int e=q.front();
            q.pop();
            int d=q.front();
            q.pop();
            if(d==2&&o!=e) a[o][e]++;
            if(d<2)
            {
                for(int to:v[e])
                {
                    q.push(to);
                    q.push(d+1);
                }
            }
        }
    }
    int res=0;
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=n;i++)
        {
            res+=(a[o][i]*(a[o][i]-1)/2);
        }
    }
    printf("%d\n",res);
    return 0;
}