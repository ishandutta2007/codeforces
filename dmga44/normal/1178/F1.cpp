#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 505
#define mod (ll(998244353))

ll dp[MAXN][MAXN],a[MAXN];

ll solve(int l,int r)
{
    ll mi=MAXN,p=-1;
    for(int i=l;i<=r;i++)
        if(mi>a[i])
        {
            mi=a[i];
            p=i;
        }

    ll s1=0,s2=0;
    for(int i=l;i<=p;i++)
        s1=(s1+(dp[l][i-1]*dp[i][p-1]))%mod;
    for(int i=p;i<=r;i++)
        s2=(s2+(dp[p+1][i]*dp[i+1][r]))%mod;
//    db(s1)
//    db(s2)
//    db(l)
//    db(r)
//    db(mi)
//    db(p)
//    db("")
    return (s1*s2)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
//    db(a[0])
//    db("")
    for(int i=0;i<=n;i++)
        dp[i][i]=dp[i][i-1]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j+i<n;j++)
            dp[j][j+i]=solve(j,i+j);
//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<n;j++)
//            cout << dp[i][j] << ' ';

    db(dp[0][n-1])

    return 0;
}