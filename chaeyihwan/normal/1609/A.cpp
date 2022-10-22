#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        ll a[20];
        for(int i=1;i<=n;i++) cin >> a[i];
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            while(a[i]%2 == 0)
            {
                cnt++;
                a[i] /= 2;
            }
        }
        ll ans = 0;
        for(int i=1;i<=n;i++) ans += a[i];
        ll M = 0;
        for(int i=1;i<=n;i++) M = max(M, a[i]);

        ans -= M;
        ans += M << cnt;
        cout << ans << "\n";
    }
}