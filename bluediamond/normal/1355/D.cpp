#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    if (s < 2 * n)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for (int i = 1; i < n; i++)
        {
            cout << 2 << " ";
        }
        cout << s - 2 * (n - 1) << "\n";
        cout << "1\n";
    }

}