#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 7;
int n;
int a[N];
int b[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        vector<int> c;
        vector<int> d;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != b[i])
            {
                c.push_back(i);
                d.push_back(a[i] - b[i]);
            }
        }
        bool ok;
        if (c.empty())
        {
            ok = 1;
        }
        else
        {
            sort(d.begin(), d.end());
            if (d[0] < 0 && d[0] == d.back() && (int) c.size() == c.back() - c[0] + 1)
            {
                ok = 1;
            }
            else
            {
                ok = 0;
            }
        }
        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

}