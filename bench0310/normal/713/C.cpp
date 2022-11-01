#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<ll> s;
    ll now=0;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin >> a;
        a-=i;
        s.insert(a);
        s.insert(a);
        now-=a;
        ll x=(*s.rbegin());
        s.erase(s.find(x));
        now+=x;
    }
    cout << now << "\n";
    return 0;
}