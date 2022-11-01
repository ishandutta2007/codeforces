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
        ll n,m;
        cin >> n >> m;
        cout << (m-1)*m/2+m*n*(n+1)/2 << "\n";
    }
    return 0;
}