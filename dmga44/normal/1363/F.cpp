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
typedef complex<ld> point;
#define MAXN 2005

int dp[MAXN][MAXN];
int af[MAXN][26],bf[MAXN][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        reverse(all(a));
        reverse(all(b));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                af[i+1][j]=af[i][j];
                bf[i+1][j]=bf[i][j];
            }
            af[i+1][a[i]-'a']++;
            bf[i+1][b[i]-'a']++;
        }

        for(int i=0;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=-1e6;

        int pos=0;
        for(int i=0;i<n;i++)
        {
            while(pos<n)
            {
                bool ok=1;
                for(int j=0;j<26;j++)
                    ok&=(af[i+1][j]>=bf[pos+1][j]);
                if(ok)
                    pos++;
                else
                    break;
            }

            for(int j=0;j<n;j++)
                if(a[i]==b[j])
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i][j]+1);

            for(int j=1;j<=pos;j++)
                dp[i+1][j]=max(dp[i+1][j],max(dp[i+1][j-1],dp[i][j]));
        }

        if(dp[n][n]<0)
            db(-1)
        else
            db(n-dp[n][n])

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                dp[i][j]=0;
            for(int j=0;j<26;j++)
                af[i][j]=bf[i][j]=0;
        }
    }

    return 0;
}
/**
1
8
dgrfghgh
dgrfghjh

6
1
a
a
2
ab
ba
3
abc
cab
3
abc
cba
4
abab
baba
4
abcc
aabc
**/