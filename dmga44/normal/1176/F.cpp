#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define MAXN 200005
#define oo ((ll)(1e18))

ll dp[MAXN][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    for(ll j=0;j<=n;j++)
        for(ll i=0;i<10;i++)
            dp[j][i]=-oo;
    dp[n][0]=0;
    while(n--)
    {
        ll k,c,d;
        cin >> k;
        vector<ll> ks[3];
        for(ll i=0;i<k;i++)
        {
            cin >> c >> d;
            ks[c-1].push_back(d);
        }

        sort(ks[0].rbegin(),ks[0].rend());
        sort(ks[1].rbegin(),ks[1].rend());
        sort(ks[2].rbegin(),ks[2].rend());

        ll best[3][2];
        best[0][0]=-1;
        if(ks[0].size())
            best[0][0]=max(ks[0][0],best[0][0]);
        if(ks[1].size())
            best[0][0]=max(ks[1][0],best[0][0]);
        if(ks[2].size())
            best[0][0]=max(ks[2][0],best[0][0]);
        best[0][1]=best[0][0];

        best[1][0]=-1;
        best[1][1]=-1;
        if(ks[0].size() && ks[1].size())
        {
            best[1][0]=max(best[1][0],ks[1][0]+ks[0][0]);
            best[1][1]=max(ks[1][0],ks[0][0]);
        }
        if(ks[0].size()>1)
        {
            best[1][0]=max(best[1][0],ks[0][1]+ks[0][0]);
            best[1][1]=max(best[1][1],ks[0][0]);
        }

        best[2][0]=-1;
        best[2][1]=-1;
        if(ks[0].size()>2)
        {
            best[2][0]=ks[0][1]+ks[0][0]+ks[0][2];
            best[2][1]=ks[0][0];
        }

        for(ll i=0;i<10;i++)
        {
            dp[n][i]=max(dp[n][i],dp[n+1][i]);
            for(ll j=0;j<3;j++)
            {
                if(best[j][0]==-1)
                    continue;
                ll cost=best[j][0];
                if(i+j+1>=10)
                    cost+=best[j][1];
                dp[n][(i+j+1)%10]=max(dp[n][(i+j+1)%10],dp[n+1][i]+cost);
            }
        }
    }

    ll res=0;
    for(ll i=0;i<10;i++)
        res=max(res,dp[0][i]);
    db(res)

    return 0;
}