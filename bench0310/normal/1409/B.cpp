#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(ll a,ll b,ll x,ll y,ll n)
{
    ll z=min(a-x,n);
    a-=z;
    n-=z;
    b-=min(b-y,n);
    return a*b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll a,b,x,y,n;
        cin >> a >> b >> x >> y >> n;
        cout << min(solve(a,b,x,y,n),solve(b,a,y,x,n)) << "\n";
    }
    return 0;
}