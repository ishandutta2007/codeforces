#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
#define MAXN 705

int a[MAXN];
bool dp[MAXN][MAXN],m[MAXN][MAXN];

int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        dp[i][i]=1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(gcd(a[i],a[j])!=1)
                m[i][j]=1;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int u=max(j-i,0);u<=min(j,n-1-i);u++)
                if(dp[j][u] && dp[j][u+i])
                {
                    if(u && m[u-1][j])
                        dp[u-1][u+i]=1;
                    if(u+i+1<n && m[u+i+1][j])
                        dp[u+i+1][u]=1;
                }
    bool res=0;
    for(int i=0;i<n;i++)
        res|=(dp[i][0] && dp[i][n-1]);
    cout << ((res) ? "Yes" : "No") << '\n';

    return 0;
}