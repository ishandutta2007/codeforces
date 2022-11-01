#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        set<ll> s;
        for(ll i=1;i*i<=n;i++) s.insert(i*i);
        for(ll i=1;i*i*i<=n;i++) s.insert(i*i*i);
        cout << s.size() << "\n";
    }
    return 0;
}