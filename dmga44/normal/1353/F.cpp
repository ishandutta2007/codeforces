#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 105

ll dp[MAXN][MAXN],a[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j];
                a[i][j]-=(i+j);
            }

        ll res=2e18;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                for(int ii=0;ii<=i;ii++)
                    for(int jj=0;jj<=j;jj++)
                        dp[ii][jj]=2e18;
                for(int ii=i;ii<n;ii++)
                    for(int jj=j;jj<m;jj++)
                        dp[ii][jj]=2e18;
                if(a[0][0]>=a[i][j])
                    dp[0][0]=(a[0][0]-a[i][j]);
                for(int ii=0;ii<=i;ii++)
                    for(int jj=0;jj<=j;jj++)
                    {
                        if(ii+jj==0 || a[ii][jj]<a[i][j])
                            continue;
                        if(ii && a[ii-1][jj]>=a[i][j])
                            dp[ii][jj]=min(dp[ii][jj],dp[ii-1][jj]);
                        if(jj && a[ii][jj-1]>=a[i][j])
                            dp[ii][jj]=min(dp[ii][jj],dp[ii][jj-1]);
                        dp[ii][jj]+=(a[ii][jj]-a[i][j]);
                    }
                for(int ii=i;ii<n;ii++)
                    for(int jj=j;jj<m;jj++)
                    {
                        if((ii==i && jj==j) || a[ii][jj]<a[i][j])
                            continue;
                        if(ii>i && a[ii-1][jj]>=a[i][j])
                            dp[ii][jj]=min(dp[ii][jj],dp[ii-1][jj]);
                        if(jj>j && a[ii][jj-1]>=a[i][j])
                            dp[ii][jj]=min(dp[ii][jj],dp[ii][jj-1]);
                        dp[ii][jj]+=(a[ii][jj]-a[i][j]);
                    }
//                db(dp[n-1][m-1])
//                cout << i << ' ' << j << '\n';
//                for(int ii=0;ii<n;ii++,cout << '\n')
//                    for(int jj=0;jj<n;jj++)
//                        cout << dp[ii][jj] << ' ';
//                db("")
                res=min(res,dp[n-1][m-1]);
            }
        db(res)
    }

    return 0;
}
/**
3
2 2
100 10
10 1
1 1
42
3 4
1 2 3 4
5 6 7 8
9 10 11 12
**/