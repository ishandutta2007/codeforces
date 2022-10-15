#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--)
    {
        vector<int> f(4, 0);
        string s;
        cin >> s;
        for (auto &c : s)
        {
            if (c == 'U')
            {
                f[0]++;
            }
            if (c == 'D')
            {
                f[3]++;
            }
            if (c == 'L')
            {
                f[1]++;
            }
            if (c == 'R')
            {
                f[2]++;
            }
        }
        int x = min(f[0], f[3]);
        int y = min(f[1], f[2]);
        if (x == 0)
        {
            y = min(y, 1);
        }
        if (y == 0)
        {
            x = min(x, 1);
        }
        int ans = x + y;
        cout << 2 * ans << "\n";
        for (int i = 1; i <= x; i++)
        {
            cout << "U";
        }
        for (int i = 1; i <= y; i++)
        {
            cout << "R";
        }
        for (int i = 1; i <= x; i++)
        {
            cout << "D";
        }
        for (int i = 1; i <= y; i++)
        {
            cout << "L";
        }
        cout << "\n";
    }

}