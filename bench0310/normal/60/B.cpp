#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,n,m;
    scanf("%d%d%d",&k,&n,&m);
    char s[k][n][m+1];
    for(int o=0;o<k;o++) for(int i=0;i<n;i++) scanf("%s",s[o][i]);
    int d,e;
    scanf("%d%d",&d,&e);
    d--;
    e--;
    queue<array<int,3>> q;
    q.push({0,d,e});
    bool vis[k][n][m];
    for(int o=0;o<k;o++) for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[o][i][j]=0;
    vis[0][d][e]=1;
    int res=0;
    auto in=[&](array<int,3> a)->bool
    {
        return (0<=a[0]&&a[0]<k&&0<=a[1]&&a[1]<n&&0<=a[2]&&a[2]<m);
    };
    while(!q.empty())
    {
        array<int,3> a=q.front();
        q.pop();
        res++;
        for(int o=0;o<3;o++)
        {
            for(int i=-1;i<=1;i+=2)
            {
                array<int,3> b=a;
                b[o]+=i;
                if(in(b)&&vis[b[0]][b[1]][b[2]]==0&&s[b[0]][b[1]][b[2]]=='.')
                {
                    q.push(b);
                    vis[b[0]][b[1]][b[2]]=1;
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}