#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[100002];

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll now = 2;
    bool ans = true;
    for(int i=1;i<=min(n, 50);i++)
    {
        bool flag = true;
        for(int j=2;j<=i+1;j++)
        {
            if(a[i]%j != 0) flag = false;
        }
        if(flag) ans = false;
    }

    if(ans) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}