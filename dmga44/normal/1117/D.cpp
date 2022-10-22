#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<string,int> psi;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 105
#define mod (ll(1e9+7))

ll ma[MAXN][MAXN],b[MAXN][MAXN],aux[MAXN][MAXN],aux2[MAXN][MAXN];
ll m;

void mul()
{
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            aux2[i][j]=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            for(int u=0;u<m;u++)
                aux2[i][j]=(aux2[i][j]+(ma[i][u]*aux[u][j]))%mod;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            ma[i][j]=aux2[i][j];
}

void qp(ll e)
{
    if(e==1)
        return ;
    qp(e/2);

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            aux[i][j]=ma[i][j];
    mul();
    if(e&1)
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                aux[i][j]=b[i][j];
        mul();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n >> m;

    ma[m][0]=1;
    ma[m][1]=1;
    ma[m][m]=1;
    for(int i=1;i<m;i++)
        ma[i][i+1]=1;
    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
            b[i][j]=ma[i][j];
    m++;

    qp(n+1);
    db(ma[m-1][0])

    return 0;
}