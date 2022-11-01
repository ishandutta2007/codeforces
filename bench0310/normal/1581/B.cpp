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
        ll n,m,k;
        cin >> n >> m >> k;
        k-=2;
        bool res=[&]()->bool
        {
            if(!(n-1<=m&&m<=n*(n-1)/2)) return 0;
            if(n==1) return (0<=k);
            if(m==n*(n-1)/2) return (1<=k);
            return (2<=k);
        }();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}