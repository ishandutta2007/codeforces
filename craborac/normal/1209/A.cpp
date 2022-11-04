#include <bits/stdc++.h>

using namespace std;

int a[300], used[300];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int j = 0; j < n; j++)
    {
        if (used[j] == 0)
        {
            ans++;
            used[j] = 1;
            for (int i = j + 1; i < n; i++)
                if (a[i] % a[j] == 0)
                    used[i] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}