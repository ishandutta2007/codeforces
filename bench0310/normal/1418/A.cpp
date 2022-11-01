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
        ll x,y,k;
        cin >> x >> y >> k;
        cout << ((k*y+k-1+x-2)/(x-1))+k << "\n";
    }
    return 0;
}