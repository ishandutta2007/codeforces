#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 1005
#define mod (ll(998244353))

ll pos[MAXN];
ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<MAXN;i++)
        dp[1][i]=i;

    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    sort(a.begin(),a.end());

    vector<pii> edges;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            edges.push_back(pii(a[j]-a[i],j+1));

    sort(edges.rbegin(),edges.rend());

    ll ant=0,p=0,res=0;
    for(ll i=(100000/(k-1));i;i--)
    {
        while(p<edges.size() && edges[p].first>=i)
        {
            pos[edges[p].second]++;
            p++;
        }

        for(ll j=2;j<=n;j++)
            for(ll u=2;u<=k;u++)
                dp[u][j]=(dp[u][j-1]+dp[u-1][pos[j]])%mod;
        res=(res+(i*(dp[k][n]-ant+mod)))%mod;
        ant=dp[k][n];
    }
    db(res)

    return 0;
}