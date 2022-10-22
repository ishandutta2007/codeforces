#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define mod (ll)(1e9+7)
#define MAXN 2005

ll pascal[MAXN][MAXN];

void calc()
{
    pascal[0][1]=1;
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<MAXN;j++)
            pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%mod;
}

ll c(int n,int m)
{
    return pascal[n][m+1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    calc();

    int n,m;
    cin >> n >> m;
    ll res=0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            ll c1=c(m+i-2,i-1);
            ll c2=c(m-1+(n-j),n-j);
            res=(res+(c1*c2))%mod;
        }
    db(res)

    return 0;
}