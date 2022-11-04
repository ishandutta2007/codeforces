#include <bits/stdc++.h>

using namespace std;

int h[100010], st[100010];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int cur = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int mn = h[i];
        while (cur > 0 && h[i] > st[cur - 1])
        {
            cur--;
            mn = min(mn, st[cur]);
        }
        st[cur] = mn;
        cur++;
    }
    cout << cur << endl;
    return 0;
}