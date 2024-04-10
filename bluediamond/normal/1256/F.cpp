#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;
        string a, b, sa, sb;
        cin >> a >> b;
        sa = a;
        sb = b;
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());

        if (sa != sb)
        {
            cout << "NO\n";
            continue;
        }

        bool ok = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            if (sa[i] == sa[i + 1])
            {
                ok = 1;
                break;
            }
        }

        if (ok)
        {
            cout << "YES\n";
            continue;
        }

        int i1 = 0, i2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                i1 += (a[i] > a[j]);
                i2 += (b[i] > b[j]);
            }
        }

        if (i1 % 2 == i2 % 2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

    }

}