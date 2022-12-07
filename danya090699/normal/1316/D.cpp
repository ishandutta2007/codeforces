#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10;
int n, vx[sz][sz], vy[sz][sz], us[sz][sz];
int go[4][2]={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char sy[4]={'R', 'L', 'U', 'D'}, an[sz][sz];
void dfs(int rtx, int rty, int x, int y)
{
    us[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int nx=x+go[i][0], ny=y+go[i][1];
        if(nx and nx<=n and ny and ny<=n and vx[nx][ny]==rtx and vy[nx][ny]==rty and !us[nx][ny])
        {
            an[nx][ny]=sy[i^1], dfs(rtx, rty, nx, ny);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=1; a<=n; a++)
    {
        for(int b=1; b<=n; b++) scanf("%d%d", &vx[a][b], &vy[a][b]);
    }
    for(int a=1; a<=n; a++)
    {
        for(int b=1; b<=n; b++)
        {
            if(vx[a][b]==a and vy[a][b]==b)
            {
                an[a][b]='X', dfs(a, b, a, b);
            }
            else if(vx[a][b]==-1)
            {
                for(int i=0; i<4; i++)
                {
                    int x=a+go[i][0], y=b+go[i][1];
                    if(x and x<=n and y and y<=n and vx[x][y]==-1)
                    {
                        an[a][b]=sy[i], us[a][b]=1;
                        break;
                    }
                }
            }
        }
    }
    for(int a=1; a<=n; a++)
    {
        for(int b=1; b<=n; b++)
        {
            if(!us[a][b])
            {
                cout<<"INVALID";
                return 0;
            }
        }
    }
    cout<<"VALID\n";
    for(int a=1; a<=n; a++) printf("%s\n", an[a]+1);
}