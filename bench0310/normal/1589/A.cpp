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
        ll u,v;
        cin >> u >> v;
        cout << u*u << " " << -v*v << "\n";
    }
    return 0;
}