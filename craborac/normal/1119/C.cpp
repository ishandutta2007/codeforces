#include <bits/stdc++.h>

using namespace std;

int s[500][2][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            s[i][0][0] ^= x;
            s[j][1][0] ^= x;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            s[i][0][1] ^= x;
            s[j][1][1] ^= x;
        }
    }
    bool d = 1;
    for (int i = 0; i < n; i++)
        if (s[i][0][0] != s[i][0][1])
            d = 0;
    for (int i = 0; i < m; i++)
        if (s[i][1][0] != s[i][1][1])
            d = 0;
    if (d)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}