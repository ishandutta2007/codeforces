#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll lim=1000000000000;
    set<ll> s;
    for(ll i=1;i*i*i<=lim;i++) s.insert(i*i*i);
    int t;
    cin >> t;
    while(t--)
    {
        ll x;
        cin >> x;
        bool ok=0;
        for(ll i=1;i*i*i<=x;i++) ok|=(s.find(x-i*i*i)!=s.end());
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}