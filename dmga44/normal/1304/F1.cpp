#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 55
#define MAXM 20105

int a[MAXN][MAXM],dp[MAXN][MAXM],madp[MAXN][MAXM][2];
int ac[MAXN][MAXM];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i+1][j+20];

    m+=100;
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=m;j++)
            ac[i][j]=ac[i][j-1]+a[i][j-1];

    for(int i=2;i<=n+1;i++)
    {
        for(int j=k;j<m;j++)
        {
            int sum=ac[i][j]-ac[i][j-k];
            sum+=ac[i-1][j]-ac[i-1][j-k];
            int add=max(madp[i-1][j-k][0],madp[i-1][j+k][1]);
//            db(add)
            for(int u=-k+1;u<k;u++)
            {
                int ss=0;
                if(u<=0 && i>2)
                    ss=ac[i-1][j+u]-ac[i-1][j-k];
                else if(i>2)
                    ss=ac[i-1][j]-ac[i-1][j-k+u];
                add=max(add,dp[i-1][j+u]-ss);
            }

            dp[i][j]=add+sum;
        }

        for(int j=1;j<m;j++)
        {
            madp[i][j][0]=max(madp[i][j-1][0],dp[i][j]);
            madp[i][m-j][1]=max(madp[i][m-j+1][1],dp[i][m-j]);
        }
    }
    db(madp[n+1][m-1][0])
//
//    for(int i=1;i<=n+1;i++,cout << '\n')
//        for(int j=0;j<=20+m-100+3;j++)
//            cout << dp[i][j] << ' ';

    return 0;
}
/**
3 3 3
1 2 3
4 5 6
7 8 9
**/