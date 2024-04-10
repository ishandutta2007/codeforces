#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {
        int a, b, n, s;
        cin >> a >> b >> n >> s;
        if (b >= s - min(a, s / n) * n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}