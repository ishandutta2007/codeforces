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
        int n,a,b;
        cin >> n >> a >> b;
        string x;
        cin >> x;
        array<int,5> dp[n+1][2*n+1][a][b];
        for(int i=0;i<=n;i++) for(int d=-n;d<=n;d++) for(int p=0;p<a;p++) for(int r=0;r<b;r++) for(int j=0;j<5;j++) dp[i][d+n][p][r][j]=-1;
        dp[0][n][0][0][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int d=-n;d<=n;d++)
            {
                for(int p=0;p<a;p++)
                {
                    for(int r=0;r<b;r++)
                    {
                        if(dp[i][d+n][p][r][0]==-1) continue;
                        int c=(x[i]-'0');
                        dp[i+1][d+1+n][(10*p+c)%a][r]={i,d,p,r,0};
                        dp[i+1][d-1+n][p][(10*r+c)%b]={i,d,p,r,1};
                    }
                }
            }
        }
        array<int,5> opt={n,0,0,0,0};
        for(int d=-n+1;d<=n;d++) if(dp[n][d+n][0][0][0]!=-1) opt=min(opt,{abs(d),n,d,0,0});
        auto [o,i,d,p,r]=opt;
        if(o<n)
        {
            string s(n,'$');
            while(i>0)
            {
                auto [ni,nd,np,nr,col]=dp[i][d+n][p][r];
                s[i-1]=(col==0?'R':'B');
                i=ni; d=nd; p=np; r=nr;
            }
            cout << s << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}