#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int sm[n][n];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            char sy;
            cin>>sy;
            if(sy=='1') sm[a][b]=1;
            else sm[a][b]=inf;
            if(a==b) sm[a][b]=0;
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            for(int c=0; c<n; c++) sm[b][c]=min(sm[b][c], sm[b][a]+sm[a][c]);
        }
    }
    int m;
    cin>>m;
    int sp[m], dp[m], pr[m];
    for(int a=0; a<m; a++)
    {
        scanf("%d", &sp[a]), sp[a]--;
        dp[a]=inf;
    }
    dp[0]=1, pr[0]=-1;
    for(int a=0; a<m; a++)
    {
        for(int b=1; (a+b<m and b<n); b++)
        {
            if(sm[sp[a]][sp[a+b]]==b)
            {
                if(dp[a+b]>dp[a]+1)
                {
                    dp[a+b]=dp[a]+1;
                    pr[a+b]=a;
                }
            }
        }
    }
    vector <int> an;
    int s=m-1;
    while(s>=0)
    {
        an.push_back(s), s=pr[s];
    }
    cout<<an.size()<<"\n";
    while(an.size())
    {
        printf("%d ", sp[an.back()]+1);
        an.pop_back();
    }
}