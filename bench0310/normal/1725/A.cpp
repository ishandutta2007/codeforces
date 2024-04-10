#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    if(m>=2) cout << (m-1)*n << "\n";
    else cout << n-1 << "\n";
    return 0;
}