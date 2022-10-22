#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

ll c[502][502];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=2*n;i++)
        {
            for(int j=1;j<=2*n;j++)
            {
                cin >> c[i][j];
            }
        }

        ll ans = 0;
        for(int i=n+1;i<=2*n;i++)
        {
            for(int j=n+1;j<=2*n;j++)
            {
                ans += c[i][j];
            }
        }

        ll tmp = 1e10;
        tmp = min(tmp, c[n][n+1]);
        tmp = min(tmp, c[n+1][n]);
        tmp = min(tmp, c[n][2*n]);
        tmp = min(tmp, c[2*n][n]);
        tmp = min(tmp, c[1][2*n]);
        tmp = min(tmp, c[2*n][1]);
        tmp = min(tmp, c[1][n+1]);
        tmp = min(tmp, c[n+1][1]);
        cout << ans + tmp << "\n";
    }
}