#include <bits/stdc++.h>
using namespace std;
int go[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, q=0;
        cin>>n>>m;
        char fi[n][m+1], us[n][m];
        for(int a=0; a<n; a++)
        {
            scanf("%s", fi[a]);
            for(int b=0; b<m; b++)
            {
                if(fi[a][b]=='G') q++;
                us[a][b]=0;
            }
        }
        bool ok=1;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++)
            {
                if(fi[a][b]=='B')
                {
                    for(int i=0; i<4; i++)
                    {
                        int x=a+go[i][0], y=b+go[i][1];
                        if(x>=0 and x<n and y>=0 and y<m)
                        {
                            if(fi[x][y]=='.') fi[x][y]='#';
                            if(fi[x][y]=='G') ok=0;
                        }
                    }
                }
            }
        }
        if(ok)
        {
            queue <pair <int, int> > qu;
            if(fi[n-1][m-1]!='#') qu.push({n-1, m-1}), us[n-1][m-1]=1;
            while(qu.size())
            {
                int x=qu.front().first, y=qu.front().second;
                if(fi[x][y]=='G') q--;
                for(int i=0; i<4; i++)
                {
                    int nx=x+go[i][0], ny=y+go[i][1];
                    if(nx>=0 and nx<n and ny>=0 and ny<m)
                    {
                        if(!us[nx][ny] and fi[nx][ny]!='#')
                        {
                            us[nx][ny]=1, qu.push({nx, ny});
                        }
                    }
                }
                qu.pop();
            }
            if(q) ok=0;
        }
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
}