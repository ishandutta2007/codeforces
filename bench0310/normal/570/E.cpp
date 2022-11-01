#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int mod=1000000007;
    int n,m;
    cin >> n >> m;
    vector<string> s(n+1);
    for(int o=1;o<=n;o++)
    {
        cin >> s[o];
        s[o]="$"+s[o];
    }
    vector<vector<int>> now(n+1,vector<int>(n+1,0));
    now[1][n]=(s[1][1]==s[n][m]);
    vector<array<int,2>> one={{1,0},{0,1}};
    vector<array<int,2>> two={{-1,0},{0,-1}};
    auto in=[&](int a,int b)->bool{return (1<=a&&a<=n&&1<=b&&b<=m);};
    auto add=[&](int &a,int b){a=(a+b)%mod;};
    for(int x=0;2*(x+1)<=(n+m-2);x++)
    {
        vector<vector<int>> nxt(n+1,vector<int>(n+1,0));
        for(int a=1;a<=n;a++)
        {
            for(int c=1;c<=n;c++)
            {
                int b=x-a+2;
                int d=n+m-c-x;
                if(!(in(a,b)&&in(c,d))) continue;
                for(auto [da,db]:one)
                {
                    for(auto [dc,dd]:two)
                    {
                        if(!(in(a+da,b+db)&&in(c+dc,d+dd))) continue;
                        if(s[a+da][b+db]==s[c+dc][d+dd]) add(nxt[a+da][c+dc],now[a][c]);
                    }
                }
            }
        }
        now=nxt;
    }
    int res=0;
    if((n+m-1)&1)
    {
        for(int i=1;i<=n;i++) add(res,now[i][i]);
    }
    else
    {
        int x=(n+m-2)/2;
        for(int a=1;a<=n;a++)
        {
            for(int c=1;c<=n;c++)
            {
                int b=x-a+2;
                int d=n+m-c-x;
                if(!(in(a,b)&&in(c,d))) continue;
                if(s[a][b]==s[c][d]&&abs(a-c)+abs(b-d)==1) add(res,now[a][c]);
            }
        }
    }
    cout << res << "\n";
    return 0;
}