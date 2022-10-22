#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a+1, a+n+1);

        ll D = 1e10;
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(D >= a[i]) ans = max(ans, i);
            D = min(D, a[i+1] - a[i]);
        }

        cout << ans << "\n";
    }
}