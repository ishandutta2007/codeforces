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
#define MAXN 5005

int dp[MAXN][MAXN],a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    int ant=-1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(ant!=a[i])
        {
            ant=a[i];
            v.push_back(a[i]);
        }
    }

    n=v.size();
    for(int i=0;i<=n;i++)
    {
        dp[i][i]=0;
        dp[i][i+1]=1;
        if(i)
            dp[i][i-1]=0;
    }
    for(int i=2;i<n;i++)
        for(int j=0;j+i<n;j++)
        {
            if(v[j]==v[j+i])
                dp[j][j+i]=dp[j+1][j+i-1]+1;
            else
                dp[j][j+i]=dp[j+1][j+i-1]+2;
            dp[j][j+i]=min(dp[j][j+i],dp[j+1][j+i]+1);
            dp[j][j+i]=min(dp[j][j+i],dp[j][j+i-1]+1);
        }
    db(dp[0][n-1])

    return 0;
}