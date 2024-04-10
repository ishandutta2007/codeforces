#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> h(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int p;
        cin >> p;
        h[p]=i;
    }
    vector inv(n+1,vector(n+2,int(0))); //a,p
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=1;j--) inv[i][j]=inv[i][j+1]+(i>h[j]);
    }
    const int inf=(1<<30);
    vector dp(k+1,vector((1<<k),int(inf)));
    dp[0][0]=0;
    auto f=[&](int a,int m,int mx)->int
    {
        int c=0;
        for(int i=0;i<k;i++) if(m&(1<<i)) c+=(a>h[mx-1-i]);
        return c;
    };
    auto chmin=[&](int &a,int b){a=min(a,b);};
    for(int p=0;p<n;p++)
    {
        vector ndp(k+1,vector((1<<k),int(inf)));
        for(int o=0;o<=k;o++)
        {
            for(int m=0;m<(1<<k);m++)
            {
                if(dp[o][m]==inf) continue;
                int mx=n-p+o;
                //place from mask
                for(int i=0;i<k;i++)
                {
                    int e=mx-1-i;
                    if(e>=1&&(m&(1<<i))==0&&o+1<=k)
                    {
                        chmin(ndp[o+1][m+(1<<i)],dp[o][m]+inv[h[e]][mx+1]+f(h[e],m,mx));
                    }
                }
                //place mx
                int nm=m;
                int c=0;
                while(nm&1)
                {
                    nm>>=1;
                    c++;
                }
                nm>>=1;
                int nmx=mx-1-c;
                int no=nmx-(n-(p+1));
                if(0<=no&&no<=k&&1<=mx&&mx<=n&&0<=nmx&&nmx<=n) chmin(ndp[no][nm],dp[o][m]+inv[h[mx]][mx+1]+f(h[mx],m,mx));
            }
        }
        dp=ndp;
    }
    cout << dp[0][0] << "\n";
    return 0;
}