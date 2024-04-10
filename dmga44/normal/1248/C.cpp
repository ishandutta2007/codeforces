#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pii;
#define MAXN 100005
#define mod (ll(1e9+7))

ll dpn[MAXN][2][2],dpm[MAXN][2][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin >> n >> m;
    dpn[0][0][0]=1;
    dpn[0][1][0]=1;
    for(int i=1;i<n;i++)
    {
        dpn[i][0][0]=(dpn[i-1][1][0]+dpn[i-1][1][1])%mod;
        dpn[i][1][0]=(dpn[i-1][0][0]+dpn[i-1][0][1])%mod;
        dpn[i][0][1]=dpn[i-1][0][0];
        dpn[i][1][1]=dpn[i-1][1][0];
    }

    dpm[0][0][0]=1;
    dpm[0][1][0]=1;
    for(int i=1;i<m;i++)
    {
        dpm[i][0][0]=(dpm[i-1][1][0]+dpm[i-1][1][1])%mod;
        dpm[i][1][0]=(dpm[i-1][0][0]+dpm[i-1][0][1])%mod;
        dpm[i][0][1]=dpm[i-1][0][0];
        dpm[i][1][1]=dpm[i-1][1][0];
    }

    n--,m--;
    ll res=2;
    ll s1=(dpn[n][0][0]+dpn[n][1][0]+dpn[n][0][1]+dpn[n][1][1])%mod;
    ll s2=(dpm[m][0][0]+dpm[m][1][0]+dpm[m][0][1]+dpm[m][1][1])%mod;
    s1=(s1-2+mod)%mod;
    s2=(s2-2+mod)%mod;
    res=(res+s1+s2)%mod;
    db(res)

    return 0;
}