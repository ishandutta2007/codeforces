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
        ll n,k;
        cin >> n >> k;
        ll c=(k-(n%k))%k;
        cout << 1+((c+n-1)/n) << "\n";
    }
    return 0;
}