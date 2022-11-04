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
    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        long long le = 0, ri = (long long)1e6 + 1;
        while (ri - le > 1)
        {
            long long mi = (le + ri) / 2;
            if (mi * mi * mi <= a * b)
                le = mi;
            else
                ri = mi;
        }
        if (a % le != 0 || b % le != 0)
        {
            cout << "No\n";
            continue;
        }
        long long s = a / le;
        long long p = b / le;
        if (a != s * s * p || b != s * p * p)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}