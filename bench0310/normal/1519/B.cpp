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
        int n,m,k;
        cin >> n >> m >> k;
        if(m-1+m*(n-1)==k) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}