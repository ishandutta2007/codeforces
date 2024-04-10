#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll res=1;
    for(ll i=1;i<=n;i++) res*=i;
    res/=(n/2);
    res/=(n/2);
    res/=2;
    cout << res << "\n";
    return 0;
}