#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    char dx = 'A', dy = 'A';
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L' || s[i] == 'R')
        {
            if (dx != s[i] && dx != 'A')
            {
                ans++;
                dx = s[i];
                dy = 'A';
            }
            else
                dx = s[i];
        }
        else
        {
            if (dy != s[i] && dy != 'A')
            {
                ans++;
                dy = s[i];
                dx = 'A';
            }
            else
                dy = s[i];
        }
    }
    cout << ans << endl;
    return 0;
}