#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, sol = 0;
    cin >> n >> m;
    vector<int> a(n);
    set<int> s;
    m = min(m, 2 * n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (s.count(x))
        {
            sol++;
            a[i] = -1;
        }
        else
        {
            a[i] = x;
            s.insert(x);
        }
    }
    int o = 0, e = 0;
    for (auto &x : s)
    {
        if (x % 2 == 0)
        {
            e++;
        }
        else
        {
            o++;
        }
    }
    int ro = 0, re = 0;
    for (int i = 1; i <= m; i++)
    {
        if (s.count(i) == 0)
        {
            if (i % 2 == 0)
            {
                re++;
            }
            else
            {
                ro++;
            }
        }
    }
    if (e + re < n / 2 || o + ro < n / 2)
    {
        cout << "-1\n";
        return 0;
    }
    vector<int> extra;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != -1)
        {
            if (a[i] % 2 == 0)
            {
                if (e > n / 2)
                {
                    e--;
                    a[i] = -1;
                }
            }
            else
            {
                if (o > n / 2)
                {
                    o--;
                    a[i] = -1;
                }
            }
        }
    }
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += (a[i] == -1);
    }

    for (int i = 1; i <= m; i++)
    {
        if (s.count(i) == 0)
        {
            if (i % 2 == 0)
            {
                if (e < n / 2)
                {
                    e++;
                    extra.push_back(i);
                }
            }
            else
            {
                if (o < n / 2)
                {
                    o++;
                    extra.push_back(i);
                }
            }
        }
    }
    cout << cost << "\n";
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            cout << extra.back() << " ";
            extra.pop_back();
        }
        else
        {
            cout << a[i] << " ";
        }
    }
    cout << "\n";
}