#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, m, a[N];

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
                cin >> a[i];
        sort(a + 1, a + n + 1);

        while (m--)
        {
                int x;
                cin >> x;
                int l = 1, r = n, ans = 0;
                while (l <= r)
                {
                        int md = (l + r) / 2;
                        if (a[md] <= x)
                        {
                                ans = md;
                                l = md + 1;
                        }
                        else
                                r = md - 1;
                }
                cout << ans << " ";
        }
        cout << "\n";

}