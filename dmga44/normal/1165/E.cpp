#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mod 998244353
#define MAXN 200005

ll a[MAXN],b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,x;
    cin >> n;
    vector<ll> as,bs;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]=a[i]*((i+1ll)*(n-i));
        as.push_back(a[i]);
    }

    for(ll i=0;i<n;i++)
    {
        cin >> x;
        bs.push_back(x);
    }

    sort(bs.begin(),bs.end());
    sort(as.rbegin(),as.rend());

    ll res=0;
    for(ll i=0;i<n;i++)
        res=(res+(((as[i])%mod)*bs[i])%mod)%mod;
    db(res)

    return 0;
}