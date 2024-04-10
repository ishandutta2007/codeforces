#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, add[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, ok=1;
    cin>>n>>m;
    char fi[n][m];
    for(int a=0; a<n; a++) for(int b=0; b<m; b++) cin>>fi[a][b];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(fi[a][b]=='S')
            {
                for(int c=0; c<4; c++)
                {
                    int x=a+add[c][0], y=b+add[c][1];
                    if(x>=0 and x<n and y>=0 and y<m)
                    {
                        if(fi[x][y]=='.') fi[x][y]='D';
                        if(fi[x][y]=='W') ok=0;
                    }
                }
            }
        }
    }
    if(ok)
    {
        cout<<"Yes\n";
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++) cout<<fi[a][b];
            cout<<"\n";
        }
    }
    else cout<<"No";
}