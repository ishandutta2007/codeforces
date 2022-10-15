#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int l = 1;
        int r = n;
        int sol = -1;
        while (l <= r)
        {
                int m = (l + r) >> 1;
                ll profit = 0LL;
                for (int i = 0; i < n; i++)
                {
                        int sub = i / m;
                        int x = max(0, a[i] - sub);
                        profit += x;
                }
                if (profit >= (ll) k)
                {
                        sol = m;
                        r = m - 1;
                }
                else
                {
                        l = m + 1;
                }
        }
        cout << sol << "\n";
}