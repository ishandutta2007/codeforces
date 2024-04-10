#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int a = 0;
        int p = 0;
        int z = 0;
        for (auto &ch : s)
        {
            int x = ch - '0';
            a = (a + x) % 3;
            p += (x % 2 == 0);
            z += (x == 0);
        }
        bool ok = (!a && (p >= 2) && (z >= 1));
        if (ok)
        {
            cout << "red\n";
        }
        else
        {
            cout << "cyan\n";
        }
    }
}