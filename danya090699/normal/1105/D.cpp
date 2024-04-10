#include <bits/stdc++.h>
using namespace std;
int go[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, p;
    cin>>n>>m>>p;
    int l[p], an[p];
    for(int a=0; a<p; a++) an[a]=0;
    for(int a=0; a<p; a++) cin>>l[a];
    char fi[n][m+3];
    queue <pair <int, int> > qu[p];
    for(int a=0; a<n; a++)
    {
        scanf("%s", fi[a]);
        for(int b=0; b<m; b++)
        {
            if(fi[a][b]!='.' and fi[a][b]!='#') qu[fi[a][b]-'1'].push({a, b});
        }
    }
    while(1)
    {
        int fo=0;
        for(int a=0; a<p; a++)
        {
            int le=0;
            while(qu[a].size() and le<l[a])
            {
                int q=qu[a].size();
                for(int b=0; b<q; b++)
                {
                    int x=qu[a].front().first, y=qu[a].front().second;
                    for(int i=0; i<4; i++)
                    {
                        int nx=x+go[i][0], ny=y+go[i][1];
                        if(nx>=0 and nx<n and ny>=0 and ny<m)
                        {
                            if(fi[nx][ny]=='.')
                            {
                                fo=1;
                                fi[nx][ny]='1'+a, qu[a].push({nx, ny});
                            }
                        }
                    }
                    qu[a].pop();
                }
                le++;
            }
        }
        if(fo==0) break;
    }
    for(int a=0; a<n; a++) for(int b=0; b<m; b++) if(fi[a][b]!='.' and fi[a][b]!='#') an[fi[a][b]-'1']++;
    for(int a=0; a<p; a++) cout<<an[a]<<" ";
}