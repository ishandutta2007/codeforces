#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    a="$"+a;
    b="$"+b;
    vector<array<int,2>> mv(m+1,{0,0});
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<2;j++)
        {
            string t=b.substr(1,i)+char('0'+j);
            for(int k=0;k<=m;k++) if(t.ends_with(b.substr(1,k))) mv[i][j]=k;
        }
    }
    auto chmin=[&](int &x,int y){x=min(x,y);};
    int mx=n-m+1;
    vector dp(m+1,vector(mx+1,int(n+1)));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        vector ndp(m+1,vector(mx+1,int(n+1)));
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=mx;k++)
            {
                for(int t=0;t<2;t++)
                {
                    int nj=mv[j][t];
                    int nk=k+(nj==m);
                    int c=(a[i]!=char('0'+t));
                    if(nk<=mx) chmin(ndp[nj][nk],dp[j][k]+c);
                }
            }
        }
        dp=ndp;
    }
    vector<int> res(mx+1,int(n+1));
    for(int j=0;j<=m;j++) for(int k=0;k<=mx;k++) chmin(res[k],dp[j][k]);
    for(int k=0;k<=mx;k++) cout << (res[k]<n+1?res[k]:-1) << " \n"[k==mx];
    return 0;
}