#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

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
        vector<int> a(n);
        bool yes = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i + 1 < n; i++)
        {
            if (a[i] <= a[i + 1])
            {
                yes = 1;
            }
        }
        if (yes)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}