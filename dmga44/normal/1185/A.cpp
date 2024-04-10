#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x;
    vector<ll> v;
    for(int i=0;i<3;i++)
    {
        cin >> x;
        v.push_back(x);
    }

    ll d;
    cin >> d;

    sort(v.begin(),v.end());

    db(max(0ll,v[0]-v[1]+d)+max(0ll,-v[2]+v[1]+d))

    return 0;
}