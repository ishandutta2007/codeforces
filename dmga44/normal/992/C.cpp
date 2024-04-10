#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mod 1000000007

ll qp(ll b,ll e)
{
    if(!e)
        return 1ll;
    ll inter=qp(b,e/2ll);
    inter=(inter*inter)%mod;
    if(e&1ll)
        inter=(inter*b)%mod;
    return inter;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x,k;
    cin >> x >> k;
    if(!x)
    {
        db(0)
        return 0;
    }
    x%=mod;
    ll y=qp(2ll,k)-1ll;
    ll yy=(qp(2ll,k+1ll)*x)%mod;
    ll res=(yy-y+mod)%mod;
    db(res)

    return 0;
}