#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[400002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=0;i<=2*n;i++)
        {
            cnt[i] = 0;
        }
        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            ans += cnt[a - i + n];
            cnt[a-i+n]++;
        }

        cout << ans << "\n";
    }
}