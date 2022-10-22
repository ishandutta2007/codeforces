#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 2005

int dp[MAXN][MAXN];
string s[MAXN];
string b[10];

int solve(int i,int x)
{
    int res=0;
    for(int j=0;j<7;j++)
    {
        if(s[i][j]=='1' && b[x][j]=='0')
            return -1;
        res+=(s[i][j]!=b[x][j]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    b[0]="1110111";
    b[1]="0010010";
    b[2]="1011101";
    b[3]="1011011";
    b[4]="0111010";
    b[5]="1101011";
    b[6]="1101111";
    b[7]="1010010";
    b[8]="1111111";
    b[9]="1111011";

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> s[i];

    for(int i=0;i<n;i++)
        for(int kk=0;kk<=k;kk++)
            dp[i][kk]=-1;
    for(int i=0;i<10;i++)
    {
        int v=solve(n-1,i);
        if(v!=-1)
            dp[n-1][v]=i;
    }
//    db("xxx")
    for(int i=n-2;i>=0;i--)
        for(int j=0;j<=k;j++)
            if(dp[i+1][j]!=-1)
                for(int u=0;u<10;u++)
                {
                    int v=solve(i,u);
                    if(v!=-1 && j+v<=k)
                    {
//                        cout << v << ' ' << j << ' ' << u << '\n';
                        dp[i][j+v]=max(dp[i][j+v],u);
                    }
                }
//    db("xxx")
    if(dp[0][k]!=-1)
    {
        for(int i=0;i<n;i++)
        {
            cout << dp[i][k];
            k-=solve(i,dp[i][k]);
//            cout << k << '\n';
        }
        cout << '\n';
    }
    else
        db(-1)

    return 0;
}
/**
2 5
0010010
0010010

3 5
0100001
1001001
1010011
**/