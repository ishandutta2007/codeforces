#include <bits/stdc++.h>

using namespace std;

int mas[(int)3e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
    }
    for (int i = 0; i < n; i++)
        if (mas[i] != mas[n - 1])
            mx = i;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] != mas[n - 1])
            ans = max(ans, n - 1 - i);
        else
            ans = max(ans, mx - i);
    }
    cout << ans << endl;
    return 0;
}