#include <bits/stdc++.h>
using namespace std;
struct el
{
    int c[6];
};
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        bool f[n+1][m+1];
        for(int a=1; a<=n; a++)
        {
            string s;
            cin>>s;
            for(int b=0; b<m; b++) f[a][b+1]=s[b]-'0';
        }
        vector <el> an;
        for(int a=n; a>2; a--)
        {
            for(int b=1; b<=m; b++)
            {
                if(f[a][b])
                {
                    f[a][b]=0, f[a-1][b]^=1;
                    if(b+1<=m)
                    {
                        an.push_back({a, b, a-1, b, a-1, b+1});
                        f[a-1][b+1]^=1;
                    }
                    else
                    {
                        an.push_back({a, b, a-1, b, a-1, b-1});
                        f[a-1][b-1]^=1;
                    }
                }
            }
        }
        for(int a=m; a>1; a--)
        {
            if(f[1][a] and f[2][a])
            {
                an.push_back({1, a, 2, a, 1, a-1});
                f[1][a-1]^=1;
            }
            else if(f[1][a])
            {
                an.push_back({1, a, 1, a-1, 2, a-1});
                f[1][a-1]^=1;
                f[2][a-1]^=1;
            }
            else if(f[2][a])
            {
                an.push_back({2, a, 1, a-1, 2, a-1});
                f[1][a-1]^=1;
                f[2][a-1]^=1;
            }
        }

        if(f[1][1] and f[2][1])
        {
            an.push_back({1, 1, 1, 2, 2, 2});
            an.push_back({1, 2, 2, 1, 2, 2});
        }
        else if(f[1][1])
        {
            an.push_back({1, 1, 1, 2, 2, 2});
            an.push_back({1, 1, 1, 2, 2, 1});
            an.push_back({1, 1, 2, 1, 2, 2});
        }
        else if(f[2][1])
        {
            an.push_back({1, 2, 2, 1, 2, 2});
            an.push_back({1, 1, 1, 2, 2, 1});
            an.push_back({1, 1, 2, 1, 2, 2});
        }
        cout<<an.size()<<"\n";
        for(int a=0; a<an.size(); a++)
        {
            for(int i=0; i<6; i++) printf("%d ", an[a].c[i]);
            printf("\n");
        }
    }
}