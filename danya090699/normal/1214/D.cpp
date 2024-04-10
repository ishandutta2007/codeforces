#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=2;
    cin>>n>>m;
    char fi[n][m+1];
    int us[n][m];
    for(int a=0; a<n; a++)
    {
        scanf("%s", fi[a]);
        for(int b=0; b<m; b++) us[a][b]=0;
    }
    us[0][0]=1;
    for(int a=0; a<n+m-1; a++)
    {
        for(int r=max(0, a-(m-1)); (a-r>=0 and r<n); r++)
        {
            int c=a-r;
            if(c>=0 and c<m and us[r][c])
            {
                if(r+1<n and fi[r+1][c]=='.') us[r+1][c]=1;
                if(c+1<m and fi[r][c+1]=='.') us[r][c+1]=1;
            }
        }
    }
    us[n-1][m-1]++;
    for(int a=n+m-2; a>=0; a--)
    {
        int q=0;
        for(int r=max(0, a-(m-1)); (a-r>=0 and r<n); r++)
        {
            int c=a-r;
            if(c>=0 and c<m and us[r][c]==2)
            {
                q++;
                if(r-1>=0 and fi[r-1][c]=='.' and us[r-1][c]) us[r-1][c]=2;
                if(c-1>=0 and fi[r][c-1]=='.' and us[r][c-1]) us[r][c-1]=2;
            }
        }
        if(a!=n+m-2 and a!=0) an=min(an, q);
    }
    cout<<an;
}