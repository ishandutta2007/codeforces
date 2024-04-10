#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int a[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];

        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                ll cnt = 0;
                for(int k=i;k<=j;k++) if(a[k] == 0) cnt++;

                ans += j - i + 1 + cnt;
            }
        }

        cout << ans << "\n";
    }
}