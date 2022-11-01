#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k,w;
    scanf("%d%d%d%d",&n,&m,&k,&w);
    char s[k+1][n][m+1];
    for(int o=1;o<=k;o++) for(int i=0;i<n;i++) scanf("%s",s[o][i]);
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> q;
    for(int i=1;i<=k;i++) q.push({n*m,i,0});
    vector<bool> vis(k+1,0);
    int res=0;
    vector<array<int,2>> v;
    while(!q.empty())
    {
        auto [cost,now,prev]=q.top();
        q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        res+=cost;
        v.push_back({now,prev});
        for(int o=1;o<=k;o++)
        {
            if(vis[o]) continue;
            int cnt=0;
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) cnt+=(s[now][i][j]!=s[o][i][j]);
            q.push({cnt*w,o,now});
        }
    }
    printf("%d\n",res);
    for(array<int,2> a:v) printf("%d %d\n",a[0],a[1]);
    return 0;
}