#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 3e5 + 7;
int n, k;
ll suf[N], ans;

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        cin >> n >> k;
        for (int i = 1; i <= n; i++)
                cin >> suf[i];
        for (int i = n; i >= 1; i--)
                suf[i] += suf[i + 1];
        ans = suf[1];

        sort(suf + 2, suf + n + 1);
        reverse(suf + 2, suf + n + 1);

        for (int i = 2; i <= k; i++)
                ans += suf[i];
        cout << ans << "\n";

        return 0;
}