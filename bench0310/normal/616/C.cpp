#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> sz(n*m+1,0);
    vector<vector<int>> id(n+2,vector<int>(m+2,0));
    char s[n+2][m+2];
    for(int o=0;o<=n+1;o++) for(int i=0;i<=m+1;i++) s[o][i]='*';
    for(int o=1;o<=n;o++) scanf("%s",s[o]+1);
    int idx=1;
    vector<array<int,2>> z={{1,0},{0,-1},{-1,0},{0,1}};
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=m;i++)
        {
            if(id[o][i]!=0||s[o][i]=='*') continue;
            queue<array<int,2>> q;
            q.push({o,i});
            id[o][i]=idx;
            while(!q.empty())
            {
                auto [r,c]=q.front();
                q.pop();
                sz[idx]++;
                for(auto [a,b]:z)
                {
                    int x=r+a;
                    int y=c+b;
                    if(s[x][y]=='.'&&id[x][y]==0)
                    {
                        id[x][y]=idx;
                        q.push({x,y});
                    }
                }
            }
            idx++;
        }
    }
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=m;i++)
        {
            if(s[o][i]=='.') printf(".");
            else
            {
                set<int> t;
                for(auto [a,b]:z) t.insert(id[o+a][i+b]);
                int res=1;
                for(int x:t) res=(res+sz[x])%10;
                printf("%d",res);
            }
        }
        printf("\n");
    }
    return 0;
}