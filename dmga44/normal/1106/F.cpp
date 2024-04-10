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
#define MAXN 105
#define mod (ll(998244353))

ll pow(ll b,ll e,ll m)
{
    if(!e)
        return 1;
    ll x=pow(b,e/2,m);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

vector<int> discrete_root(int k, int a, int n)
{
    if (a == 0)
        return {0};
    int g = 3;
    ll sq = (ll) sqrt(n + .0) + 1;
    vector<pair<int, int>> dec(sq);
    for (int i = 1; i <= sq; ++i)
        dec[i - 1] = {pow(g, ll(1ll * i * sq * k % (n - 1)), n), i};
    sort(dec.begin(), dec.end());
    int any_ans = -1;
    for (int i = 0; i < sq; ++i)
    {
        int my = int(pow(g, ll(i * 1ll * k % (n - 1)), n) * 1ll * a % n);
        auto it = lower_bound(dec.begin(), dec.end(), make_pair(my, 0));
        if (it != dec.end() && it->first == my)
        {
            any_ans = it->second * sq - i;
            break;
        }
    }
    if (any_ans == -1)
        return {};
    int delta = (n - 1) / __gcd(k, n - 1);
    vector<int> ans;
    for (ll cur = any_ans % delta; cur < n - 1 && ans.size()<1; cur += delta)
        ans.push_back(pow(g, cur, n));
    return ans;
}

ll m[MAXN][MAXN],b[MAXN][MAXN],aux[MAXN][MAXN],aux2[MAXN][MAXN];
int k;

void mul()
{
    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++)
            aux2[i][j]=0;
    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++)
            for(int u=0; u<k; u++)
                aux2[i][j]=(aux2[i][j]+(m[i][u]*aux[u][j]))%(mod-1);
    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++)
            m[i][j]=aux2[i][j];
}

void qp(ll e)
{
    if(e==1)
        return ;
    qp(e/2);
    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++)
            aux[i][j]=m[i][j];
    mul();
    if(e&1)
    {
        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                aux[i][j]=b[i][j];
        mul();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    vector<ll> bs(k);
    for(int i=0; i<k; i++)
        cin >> bs[i];
    ll n,ma;
    cin >> n >> ma;

    m[k][0]=1;
    for(int i=0; i<k; i++)
        m[k][i+1]=bs[k-i-1];
    for(int i=1; i<k; i++)
        m[i][i+1]=1;
    for(int i=0; i<=k; i++)
        for(int j=0; j<=k; j++)
            b[i][j]=m[i][j];

    n-=k;
    k++;
    qp(n+1);

    ll xxx=m[k-1][0];
    vector<int> ok=discrete_root(xxx,ma,mod);

    if(ok.size())
        db(ok[0])
    else
        db(-1)

    return 0;
}