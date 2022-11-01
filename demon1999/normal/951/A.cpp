#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    s = s + s;
    int m = 2 * n;
    int ans = 0;
    char last = 'w' + 'b' - s[0];
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (s[i] != last)
        {
            cnt++;
            last = s[i];
        }
        else
        {
            cnt = 1;
            last = s[i];
        }
        ans = max(ans, cnt);
    }
    cout << min(ans, n) << endl;
    return 0;
}