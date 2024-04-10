#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void br(int r1, int c1, int r2, int c2)
{
    for (int i = 1; i <= c2 - c1; i++)
    {
        cout << "R";
    }
    for (int i = 1; i <= r2 - r1; i++)
    {
        cout << "U";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
            swap(a[i].first, a[i].second);
        }
        sort(a.begin(), a.end());
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i].second;
        }
        bool bad = 0;
        for (int i = 1; i < n; i++)
        {
            if (b[i - 1] > b[i])
            {
                bad = 1;
                break;
            }
        }
        if (bad)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        br(0, 0, a[0].first, a[0].second);
        for (int i = 0; i + 1 < n; i++)
        {
            br(a[i].first, a[i].second, a[i + 1].first, a[i + 1].second);
        }
        cout << "\n";
    }
}