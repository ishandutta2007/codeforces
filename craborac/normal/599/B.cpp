#include <bits/stdc++.h>

using namespace std;

int a[100000];
pair<int, int> f[100000];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i =0; i < n; i++)
    {
        cin >> f[i].first;
        f[i].second = i;
    }
    sort(f, f + n);
    bool d = 0;
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        int l = -1;
        int r = n;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (f[m].first < b)
                l = m;
            else
                r = m;
        }
        if (r == n || f[r].first != b)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        if ((r > 0 && f[r].first == f[r - 1].first) || (r + 1 < n && f[r].first == f[r + 1].first))
            d = 1;
        a[i] = f[r].second + 1;
    }
    if (d)
    {
        cout << "Ambiguity" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for (int i = 0; i < m; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}