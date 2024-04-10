#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef pair<char,int> pci;
#define mod (ll(1e9+7))
#define MAXN 55
#define MAXT 2505

map<int,int> dp1[MAXT];
ll t[MAXN],g[MAXN];
ll dp2[MAXN][MAXN][MAXN][3];
ll fac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0]=1;
    for(ll i=1;i<MAXN;i++)
        fac[i]=(fac[i-1]*i)%mod;

    dp2[1][0][0][0]=1;
    dp2[0][1][0][1]=1;
    dp2[0][0][1][2]=1;
    for(int i=0;i<MAXN-1;i++)
        for(int j=0;j<MAXN-1;j++)
            for(int k=0;k<MAXN-1;k++)
            {
                dp2[i+1][j][k][0]=(dp2[i+1][j][k][0]+dp2[i][j][k][1]+dp2[i][j][k][2])%mod;
                dp2[i][j+1][k][1]=(dp2[i][j+1][k][1]+dp2[i][j][k][0]+dp2[i][j][k][2])%mod;
                dp2[i][j][k+1][2]=(dp2[i][j][k+1][2]+dp2[i][j][k][1]+dp2[i][j][k][0])%mod;
            }

    int n,ti;
    cin >> n >> ti;
    dp1[0][0]=1;
    for(int i=0;i<n;i++)
    {
        int t,g;
        cin >> t >> g;
        g--;
        for(int j=ti-t;j>=max(0,ti-(50*(n-i)));j--)
            for(auto yy : dp1[j])
            {
                int x=yy.first;
                int v=yy.second;
                int po=1;
                for(int ii=0;ii<g;ii++)
                    po*=MAXN;
                x+=po;
                dp1[j+t][x]=(dp1[j+t][x]+v)%mod;
            }
    }

    ll res=0;
    for(auto yy : dp1[ti])
    {
        int x=yy.first;
        ll v=yy.second;
        ll a=x%MAXN;
        ll b=(x/MAXN)%MAXN;
        ll c=x/(MAXN*MAXN);
        ll fff=(fac[a]*fac[b])%mod;
        fff=(fff*fac[c])%mod;
        res=(res+(((v*(dp2[a][b][c][0]+dp2[a][b][c][1]+dp2[a][b][c][2]))%mod)*fff)%mod)%mod;
    }
    db(res)

    return 0;
}
/**
15 100
31 3
13 2
32 1
47 1
25 3
50 3
49 1
35 3
2 2
30 2
46 1
37 1
44 1
48 2
10 3
**/