#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, tot=0;
    cin>>n>>m;
    char fi[n][m+1], an[n][m+1];
    for(int a=0; a<n; a++)
    {
        scanf("%s", fi[a]);
        for(int b=0; b<m; b++)
        {
            an[a][b]='.';
            if(fi[a][b]=='X') tot++;
        }
        an[a][m]=0;
    }
    int dp[n][m], l[n][m], t[n][m];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(fi[a][b]=='X')
            {
                l[a][b]=1, t[a][b]=1;
                if(a) t[a][b]+=t[a-1][b];
                if(b) l[a][b]+=l[a][b-1];

                dp[a][b]=min(l[a][b], t[a][b]);
                if(a>0 and b>0) dp[a][b]=min(dp[a][b], dp[a-1][b-1]+1);
            }
            else l[a][b]=0, t[a][b]=0, dp[a][b]=0;

        }
    }
    int lg=-1, rg=min(n, m);
    while(rg-lg>1)
    {
        int mid=(lg+rg)>>1, su=0;
        char us[n][m], cu[n][m];
        for(int a=0; a<n; a++) for(int b=0; b<m; b++) us[a][b]=0, cu[a][b]='.';
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++)
            {
                if(dp[a][b]>=mid*2+1)
                {
                    cu[a-mid][b-mid]='X';
                    for(int c=b; c>=b-mid*2; c--)
                    {
                        if(us[a][c]) break;
                        for(int r=a; r>=a-mid*2; r--)
                        {
                            if(us[r][c]) break;
                            else us[r][c]=1, su++;
                        }
                    }
                }
            }
        }
        if(su==tot)
        {
            for(int a=0; a<n; a++) for(int b=0; b<m; b++) an[a][b]=cu[a][b];
            lg=mid;
        }
        else rg=mid;
    }
    cout<<lg<<"\n";
    for(int a=0; a<n; a++) printf("%s\n", an[a]);
}