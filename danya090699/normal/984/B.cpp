#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, ok=1;
    cin>>n>>m;
    char fi[n][m];
    for(int a=0; a<n; a++) for(int b=0; b<m; b++) cin>>fi[a][b];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(fi[a][b]!='*')
            {
                int va;
                if(fi[a][b]=='.') va=0;
                else va=fi[a][b]-'0';
                for(int i=-1; i<=1; i++)
                {
                    for(int j=-1; j<=1; j++)
                    {
                        if(!(i==0 and j==0))
                        {
                            int x=a+i, y=b+j;
                            if(x>=0 and x<n and y>=0 and y<m)
                            {
                                if(fi[x][y]=='*') va--;
                            }
                        }
                    }
                }
                if(va!=0) ok=0;
            }
        }
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}