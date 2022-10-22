#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define MAXN 200005

ll dp[MAXN],a[MAXN],ac[MAXN],w[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
        a[i]=v[i];

    for(ll i=1;i<=n;i++)
        ac[i]=ac[i-1]+a[i-1];

    for(ll i=0;i<m;i++)
        cin >> w[i][0] >> w[i][1];

    for(ll j=0;j<=k;j++)
        for(int i=0;i<m;i++)
            if(j-w[i][0]>=0)
                dp[j]=max(dp[j],dp[j-w[i][0]]+ac[k-j+w[i][1]]-ac[k-j]);

    ll res=0;
    for(ll i=0;i<=k;i++)
        res=max(res,dp[i]);
    db(ac[k]-ac[0]-res)

    return 0;
}