#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s >> s;
    if (s[0] == 'w')
    {
        cout << 52 + ((n + 1) / 2 == 3) << "\n";
    }
    else
    {
        int d[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sol = 0;
        for (int i = 0; i < 12; i++)
        {
            sol += (d[i] >= n);
        }
        cout << sol << "\n";
    }
}