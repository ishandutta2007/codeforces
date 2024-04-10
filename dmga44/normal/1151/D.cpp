#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pip> v;
    for(int i=0;i<n;i++)
    {
        ll l,r;
        cin >> l >> r;
        v.push_back(pip(l-r,pii(l,r)));
    }

    sort(v.rbegin(),v.rend());

    ll res=0;
    for(int i=0;i<n;i++)
        res+=i*v[i].second.first+(n-i-1)*v[i].second.second;
    db(res)

    return 0;
}