#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, a[N], b[N], av[N];
int u[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        u[b[i]] = i;
    }

    for (int ps = 1; ps <= n; ps++)
    {
        if (b[ps] == 1)
        {
            bool ok = 1;
            for (int i = ps; i <= n && ok; i++)
            {
                ok &= (b[i] == i - ps + 1);
            }
            if (ok)
            {
                ok = 1;
                for (int i = 1; i < ps && ok; i++)
                {
                    if (b[i] > 0)
                    {
                        ok &= (i < b[i] - b[n]);
                    }
                }
                if (ok)
                {
                    cout << ps - 1 << "\n";
                    return 0;
                }
            }
        }
    }

    int push = 0;
    for (int x = 1; x <= n; x++)
    {
        if (u[x] - push <= 0)
        {
            push++;
        }
        else
        {
            push += u[x] - push + 1;
        }
    }
    cout << push << "\n";

    return 0;
}

/**


**/