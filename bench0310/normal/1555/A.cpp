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
        n=max(ll(6),n);
        if(n&1) n++;
        cout << 5*n/2 << "\n";
    }
    return 0;
}