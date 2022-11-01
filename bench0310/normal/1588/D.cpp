#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<string> s(n);
        auto id=[&](char c)->int
        {
            if(islower(c)) return (c-'a');
            else return (26+(c-'A'));
        };
        vector pos(n,vector(52,array<int,2>{-1,-1}));
        for(int i=0;i<n;i++)
        {
            cin >> s[i];
            int m=s[i].size();
            for(int j=0;j<m;j++)
            {
                int c=id(s[i][j]);
                if(pos[i][c][0]==-1) pos[i][c][0]=j;
                else pos[i][c][1]=j;
            }
        }
        vector dp(52,vector((1<<n),int(0)));
        vector p(52,vector((1<<n),array<int,2>{-1,-1}));
        array<int,3> opt={-1,-1,-1};
        for(int i=(int)s[0].size()-1;i>=0;i--)
        {
            int c=id(s[0][i]);
            for(int m=0;m<(1<<n);m++)
            {
                bool ok=1;
                for(int j=0;j<n;j++) ok&=(pos[j][c][(m>>j)&1]!=-1);
                if(!ok) continue;
                for(int d=0;d<52;d++)
                {
                    ok=1;
                    int nm=0;
                    for(int j=0;j<n;j++)
                    {
                        int r=pos[j][c][(m>>j)&1];
                        if(pos[j][d][0]==-1) ok=0;
                        else if(pos[j][d][0]>r) nm+=0;
                        else if(pos[j][d][1]>r) nm^=(1<<j);
                        else ok=0;
                    }
                    if(ok&&dp[c][m]<dp[d][nm]+1)
                    {
                        dp[c][m]=dp[d][nm]+1;
                        p[c][m]={d,nm};
                    }
                }
                opt=max(opt,{dp[c][m],c,m});
            }
        }
        auto [res,c,m]=opt;
        cout << res+1 << "\n";
        while(c!=-1)
        {
            cout << char(c<26?('a'+c):('A'+(c-26)));
            auto [nc,nm]=p[c][m];
            c=nc; m=nm;
        }
        cout << "\n";
    }
    return 0;
}