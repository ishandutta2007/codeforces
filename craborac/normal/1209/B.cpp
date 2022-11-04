#include <bits/stdc++.h>

using namespace std;

int a[300], b[300];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += s[i] - '0';
        cin >> a[i] >> b[i];
    }
    ans = cur;
    for (int j = 1; j <= 1000; j++)
    {
        cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (j >= b[i] && (j - b[i]) % a[i] == 0)
                s[i] = '0' + '1' - s[i];
            cur += s[i] - '0';
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}