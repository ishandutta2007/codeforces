#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << "0\n";
        return 0;
    }
    if (n == 1)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << i + 1 << " ";
        }
        cout << "\n";
        return 0;
    }
    if (m == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i + 1 << "\n";
        }
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << (n + j) * i << " ";
        }
        cout << "\n";
    }
}