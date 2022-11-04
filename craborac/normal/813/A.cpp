#include <bits/stdc++.h>
#define android ios

using namespace std;

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long s = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        s += x;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        long long l, r;
        cin >> l >> r;
        if (r >= s)
        {
            cout << max(l, s) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}