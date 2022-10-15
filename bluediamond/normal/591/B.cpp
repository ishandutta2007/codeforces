#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 7;
int n, d[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 26; i++)
    {
        d[i] = i;
    }

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    for (int i = 1; i <= m; i++)
    {
        string a, b;
        cin >> a >> b;
        int x = a[0] - 'a';
        int y = b[0] - 'a';
        for (int j = 0; j < 26; j++)
        {
            if (d[j] == x)
            {
                d[j] = y;
                continue;
            }
            if (d[j] == y)
            {
                d[j] = x;
                continue;
            }
        }
    }

    for (auto &c : s)
    {
        cout << (char) (d[c - 'a'] + 'a');
    }
    cout << "\n";

}