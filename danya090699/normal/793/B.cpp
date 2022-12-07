#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, y, x;
    cin>>n>>m;
    int us[n][m];
    char fi[n][m];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            cin>>fi[a][b];
            if(fi[a][b]=='S') us[a][b]=0;
            else us[a][b]=-1;
            if(fi[a][b]=='T')
            {
                y=a, x=b;
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++)
            {
                if(us[a][b]==i)
                {
                    for(int c=a-1; c>=0; c--)
                    {
                        if(us[c][b]==-1 and fi[c][b]!='*') us[c][b]=i+1;
                        else break;
                    }
                    for(int c=a+1; c<n; c++)
                    {
                        if(us[c][b]==-1 and fi[c][b]!='*') us[c][b]=i+1;
                        else break;
                    }
                    for(int c=b-1; c>=0; c--)
                    {
                        if(us[a][c]==-1 and fi[a][c]!='*') us[a][c]=i+1;
                        else break;
                    }
                    for(int c=b+1; c<m; c++)
                    {
                        if(us[a][c]==-1 and fi[a][c]!='*') us[a][c]=i+1;
                        else break;
                    }
                }
            }
        }
    }
    if(us[y][x]!=-1) cout<<"YES";
    else cout<<"NO";
}