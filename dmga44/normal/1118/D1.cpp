#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

ll a[MAXN],n,m;
vector<ll> ns;

bool check(ll x)
{
    ll sum=0;
    for(ll i=0;i<n;i++)
        sum+=max(0ll,ns[i]-(i/x));
    return sum>=m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll sum=0;
    cin >> n >> m;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        ns.push_back(a[i]);
        sum+=a[i];
    }

    sort(ns.rbegin(),ns.rend());

    if(sum<m)
    {
        db(-1)
        return 0;
    }

    ll res=0;
    for(ll i=(1<<17);i;i>>=1)
        if(!check(res+i))
            res+=i;
    db(res+1)

    return 0;
}