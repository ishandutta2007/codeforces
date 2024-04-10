#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll d[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> d[i];
        sort(d + 1, d + n + 1);

        ll sum = 0, ans = d[n];
        for(ll i=1;i<=n;i++)
        {
            ans -= (i-1)*d[i] - sum;
            sum += d[i];
        }

        cout << ans << "\n";
    }
}