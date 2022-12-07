#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10;
int n, m, go[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char fi[sz][sz];
bool us[sz][sz];
void dfs(int r, int c)
{
    us[r][c]=1;
    for(int i=0; i<4; i++)
    {
        int nr=r+go[i][0], nc=c+go[i][1];
        if(nr>=0 and nr<n and nc>=0 and nc<m and fi[nr][nc]=='#' and !us[nr][nc]) dfs(nr, nc);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    int r=0, c=0;
    for(int a=0; a<n; a++)
    {
        scanf("%s", fi[a]);
        int yk=0, q=0;
        while(yk<m)
        {
            if(fi[a][yk]=='.') yk++;
            else
            {
                q++;
                while(yk<m and fi[a][yk]=='#') yk++;
            }
        }
        if(q==0) r=1;
        else if(q>1)
        {
            cout<<-1;
            return 0;
        }
    }
    for(int a=0; a<m; a++)
    {
        int yk=0, q=0;
        while(yk<n)
        {
            if(fi[yk][a]=='.') yk++;
            else
            {
                q++;
                while(yk<n and fi[yk][a]=='#') yk++;
            }
        }
        if(q==0) c=1;
        else if(q>1)
        {
            cout<<-1;
            return 0;
        }
    }
    if(r^c)
    {
        cout<<-1;
        return 0;
    }
    int an=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(fi[a][b]=='#' and !us[a][b]) an++, dfs(a, b);
        }
    }
    cout<<an;
}